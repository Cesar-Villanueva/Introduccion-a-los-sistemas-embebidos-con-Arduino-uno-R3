/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/


//====================================================
// LIBRERÍAS
//====================================================

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Stepper.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>



//====================================================
// DEFINICIÓN DE PINES
//====================================================

//---------- LEDs ----------
#define LED_ROJO        13
#define LED_AMARILLO    12
#define LED_VERDE       11

//---------- Sensor Ultrasónico ----------
#define TRIG_PIN        22
#define ECHO_PIN        23

//---------- Motor a Pasos ----------
#define IN1             24
#define IN2             25
#define IN3             26
#define IN4             27

//---------- Servomotor ----------
#define SERVO_PIN       28

//---------- Sensor de Nivel ----------
#define NIVEL_PIN       A0

//---------- Buzzer ----------
#define BUZZER_PIN      29

//---------- RFID ----------
#define SS_PIN          53
#define RST_PIN         5

//---------- Botón de Emergencia ----------
#define BOTON_PIN       2



//====================================================
// CONSTANTES
//====================================================

#define PASOS_REVOLUCION    2048

const char CONTRASENA[] = "1234";

// UID de la tarjeta autorizada
const byte UID_AUTORIZADO[4] = {0xC3, 0x90, 0x41, 0xAD}; // C3 90 41 AD



//====================================================
// VARIABLES GLOBALES
//====================================================

char opcionMenu;

bool accesoPermitido = false;

volatile bool emergencia = false;



//====================================================
// OBJETOS
//====================================================

// RFID
MFRC522 rfid(SS_PIN, RST_PIN);

// LCD
LiquidCrystal_I2C lcd(0x27,16,2);

// Servo
Servo servoMotor;

// Motor a pasos
Stepper motorPasos(PASOS_REVOLUCION, IN1, IN3, IN2, IN4);

//----------------------------------------------------
// Teclado Matricial
//----------------------------------------------------

const byte FILAS = 4;
const byte COLUMNAS = 4;

char teclas[FILAS][COLUMNAS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {30,31,32,33};
byte pinesColumnas[COLUMNAS] = {34,35,36,37};

Keypad teclado = Keypad(makeKeymap(teclas),
                        pinesFilas,
                        pinesColumnas,
                        FILAS,
                        COLUMNAS);



//====================================================
// PROTOTIPOS
//====================================================

// Inicialización
void inicializarSistema();

// Pantalla
void mostrarBienvenida();

// Autenticación
void autenticarUsuario();
bool leerRFID();
bool validarRFID();
bool ingresarPassword();

// Menú
void mostrarMenu();

// Módulos
void moduloSemaforo();
void moduloUltrasonico();
void moduloServo();
void moduloMotorPasos();
void moduloNivelAgua();

// Interrupción
void interrupcionEmergencia();
void modoEmergencia();

void apagarLeds();


//====================================================
// SETUP
//====================================================

void setup()
{

    Serial.begin(9600);

    // Inicializar sistema
    inicializarSistema();

    // Mensaje de bienvenida
    mostrarBienvenida();

}



//====================================================
// LOOP
//====================================================

void loop()
{

    
    autenticarUsuario();

    mostrarMenu();

}



//====================================================
// INICIALIZACIÓN DEL SISTEMA
//====================================================

void inicializarSistema()
{

    // LEDs
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);

    // Sensor ultrasónico
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    // Buzzer
    pinMode(BUZZER_PIN, OUTPUT);

    // Botón de emergencia
    pinMode(BOTON_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(BOTON_PIN),
                    interrupcionEmergencia,
                    RISING);

    // LCD
    lcd.begin();
    lcd.backlight();

    // Servo
    servoMotor.attach(SERVO_PIN);

    // Motor a pasos
    motorPasos.setSpeed(10);

    // RFID
    SPI.begin();
    rfid.PCD_Init();

}



//====================================================
// PANTALLA DE BIENVENIDA
//====================================================

void mostrarBienvenida()
{

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print(" PROYECTO FINAL ");

    lcd.setCursor(0,1);
    lcd.print(" Arduino Mega ");

    Serial.println();
    Serial.println("==============================");
    Serial.println(" PROYECTO FINAL");
    Serial.println("==============================");

    delay(2000);

}

//====================================================
// APAGAR TODOS LOS LEDS
//====================================================

void apagarLeds()
{

    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, LOW);

}


//====================================================
// INTERRUPCIÓN
//====================================================

void interrupcionEmergencia()
{

    emergencia = true;

}

//====================================================
// AUTENTICACIÓN
//====================================================

void autenticarUsuario()
{

    accesoPermitido = false;

    while(!accesoPermitido)
    {
        if(emergencia)
        {
          modoEmergencia();
        }

        if(validarRFID())
        {

            if(ingresarPassword())
            {

                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Acceso");
                lcd.setCursor(0,1);
                lcd.print("Concedido");

                Serial.println("Acceso concedido");

                delay(1500);

                accesoPermitido = true;

            }

            else
            {

                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("PIN");
                lcd.setCursor(0,1);
                lcd.print("Incorrecto");

                Serial.println("PIN incorrecto");

                delay(1500);

            }

        }

    }

}

//====================================================
// MENÚ PRINCIPAL
//====================================================

void mostrarMenu()
{

    while (true)
    {

        // Si ocurre una emergencia
        if (emergencia)
        {
            modoEmergencia();
        }

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("1 2 3 4 5");

        lcd.setCursor(0,1);
        lcd.print("Seleccione");

        Serial.println();
        Serial.println("===== MENU PRINCIPAL =====");
        Serial.println("1 - Semaforo");
        Serial.println("2 - Ultrasonico");
        Serial.println("3 - Servomotor");
        Serial.println("4 - Motor a Pasos");
        Serial.println("5 - Nivel de Agua");

        char opcion = 0;

        while(opcion == 0)
        {

            if(emergencia)
            {
                modoEmergencia();
            }

            opcion = teclado.getKey();

        }

        switch(opcion)
        {

            case '1':

                moduloSemaforo();

                break;

            case '2':

                moduloUltrasonico();

                break;

            case '3':

                moduloServo();

                break;

            case '4':

                moduloMotorPasos();

                break;

            case '5':

                moduloNivelAgua();

                break;

            default:

                lcd.clear();

                lcd.setCursor(0,0);
                lcd.print("Opcion");

                lcd.setCursor(0,1);
                lcd.print("No valida");

                delay(1000);

                break;

        }

    }

}

//====================================================
// MÓDULO SEMÁFORO
//====================================================

void moduloSemaforo()
{

    Serial.println();
    Serial.println("===== MODULO SEMAFORO =====");

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Modulo");

    lcd.setCursor(0,1);
    lcd.print("Semaforo");

    delay(1500);

    while(true)
    {

        // Si ocurre una emergencia
        if(emergencia)
        {
            modoEmergencia();
        }

        // Salir del módulo
        if(teclado.getKey() == '#')
        {

            apagarLeds();

            Serial.println("Saliendo del modulo Semaforo");

            return;

        }

        //------------------------------------------------
        // LED VERDE
        //------------------------------------------------

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Semaforo");

        lcd.setCursor(0,1);
        lcd.print("Verde");

        digitalWrite(LED_VERDE, HIGH);
        digitalWrite(LED_AMARILLO, LOW);
        digitalWrite(LED_ROJO, LOW);

        delay(2000);

        //------------------------------------------------
        // PARPADEO VERDE
        //------------------------------------------------

        for(int i=0; i<4; i++)
        {

            if(emergencia)
            {
                modoEmergencia();
            }

            if(teclado.getKey() == '#')
            {

                apagarLeds();

                return;

            }

            digitalWrite(LED_VERDE, LOW);

            delay(250);

            digitalWrite(LED_VERDE, HIGH);

            delay(250);

        }

        //------------------------------------------------
        // AMARILLO
        //------------------------------------------------

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Semaforo");

        lcd.setCursor(0,1);
        lcd.print("Amarillo");

        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AMARILLO, HIGH);
        digitalWrite(LED_ROJO, LOW);

        delay(1500);

        //------------------------------------------------
        // ROJO
        //------------------------------------------------

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Semaforo");

        lcd.setCursor(0,1);
        lcd.print("Rojo");

        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AMARILLO, LOW);
        digitalWrite(LED_ROJO, HIGH);

        delay(5000);

    }

}



//====================================================
// VALIDAR RFID
//====================================================

bool validarRFID()
{

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Acerque");

    lcd.setCursor(0,1);
    lcd.print("su tarjeta");

    Serial.println("Esperando tarjeta RFID...");

    while(true)
    {

        if(emergencia)
        {
            modoEmergencia();
        }

        if(!rfid.PICC_IsNewCardPresent())
            continue;

        if(!rfid.PICC_ReadCardSerial())
            continue;

        bool tarjetaValida = true;

        for(byte i=0;i<4;i++)
        {

            if(rfid.uid.uidByte[i] != UID_AUTORIZADO[i])
            {

                tarjetaValida = false;

                break;

            }

        }

        rfid.PICC_HaltA();
        rfid.PCD_StopCrypto1();

        if(tarjetaValida)
        {

            Serial.println("Tarjeta correcta");

            return true;

        }

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Tarjeta");

        lcd.setCursor(0,1);
        lcd.print("No valida");

        Serial.println("Tarjeta no valida");

        delay(1500);

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Acerque");

        lcd.setCursor(0,1);
        lcd.print("su tarjeta");

    }

}

//====================================================
// INGRESAR CONTRASEÑA
//====================================================

bool ingresarPassword()
{

    char password[5];

    byte indice = 0;

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Ingrese PIN");

    lcd.setCursor(0,1);

    while(true)
    {

        if(emergencia)
        {
            modoEmergencia();
        }

        char tecla = teclado.getKey();

        if(tecla)
        {

            if(tecla >= '0' && tecla <= '9')
            {

                if(indice < 4)
                {

                    password[indice] = tecla;

                    lcd.print('*');

                    indice++;

                }

            }

            if(tecla == '#')
            {

                password[4] = '\0';

                if(strcmp(password, CONTRASENA) == 0)
                {

                    return true;

                }

                return false;

            }

        }

    }

}

//====================================================
// MÓDULO ULTRASÓNICO
//====================================================

void moduloUltrasonico()
{

    Serial.println();
    Serial.println("===== MODULO ULTRASONICO =====");

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Modulo");

    lcd.setCursor(0,1);
    lcd.print("Ultrasonico");

    delay(1500);

    while(true)
    {

        if(emergencia)
        {
            modoEmergencia();
        }

        if(teclado.getKey() == '#')
        {
            apagarLeds();
            digitalWrite(BUZZER_PIN, LOW);
            return;
        }

        // Generar pulso
        digitalWrite(TRIG_PIN, LOW);
        delayMicroseconds(5);

        digitalWrite(TRIG_PIN, HIGH);
        delayMicroseconds(10);

        digitalWrite(TRIG_PIN, LOW);

        long duracion = pulseIn(ECHO_PIN, HIGH);

        float distancia = duracion * 0.0343 / 2.0;

        // Mostrar distancia
        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Distancia:");

        lcd.setCursor(0,1);
        lcd.print(distancia);
        lcd.print(" cm");

        Serial.print("Distancia: ");
        Serial.print(distancia);
        Serial.println(" cm");

        // Indicadores

        if(distancia > 30)
        {

            digitalWrite(LED_VERDE, HIGH);
            digitalWrite(LED_AMARILLO, LOW);
            digitalWrite(LED_ROJO, LOW);

            digitalWrite(BUZZER_PIN, LOW);

        }
        else if(distancia > 10)
        {

            digitalWrite(LED_VERDE, LOW);
            digitalWrite(LED_AMARILLO, HIGH);
            digitalWrite(LED_ROJO, LOW);

            digitalWrite(BUZZER_PIN, LOW);

        }
        else
        {

            digitalWrite(LED_VERDE, LOW);
            digitalWrite(LED_AMARILLO, LOW);
            digitalWrite(LED_ROJO, HIGH);

            digitalWrite(BUZZER_PIN, HIGH);

        }

        delay(200);

    }

}

//====================================================
// MÓDULO SERVOMOTOR
//====================================================

void moduloServo()
{

    Serial.println();
    Serial.println("===== MODULO SERVOMOTOR =====");

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Modulo");

    lcd.setCursor(0,1);
    lcd.print("Servomotor");

    delay(1500);

    while(true)
    {

        if(emergencia)
        {
            modoEmergencia();
        }

        if(teclado.getKey() == '#')
        {

            servoMotor.write(90);

            Serial.println("Saliendo del modulo Servomotor");

            return;

        }

        // Posición 0°
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Servo: 0");

        servoMotor.write(0);

        delay(1000);

        if(teclado.getKey() == '#')
        {

            servoMotor.write(90);

            return;

        }

        // Posición 90°
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Servo: 90");

        servoMotor.write(90);

        delay(1000);

        if(teclado.getKey() == '#')
        {

            servoMotor.write(90);

            return;

        }

        // Posición 180°
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Servo: 180");

        servoMotor.write(180);

        delay(1000);

    }

}

//====================================================
// MÓDULO MOTOR A PASOS
//====================================================

void moduloMotorPasos()
{

    Serial.println();
    Serial.println("===== MODULO MOTOR A PASOS =====");

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Modulo");

    lcd.setCursor(0,1);
    lcd.print("Motor Pasos");

    delay(1500);

    while(true)
    {

        if(emergencia)
        {
            modoEmergencia();
        }

        if(teclado.getKey() == '#')
        {

            Serial.println("Saliendo del modulo Motor a Pasos");

            return;

        }

        //------------------------------------------------
        // Giro horario
        //------------------------------------------------

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Girando");

        lcd.setCursor(0,1);
        lcd.print("Horario");

        motorPasos.step(PASOS_REVOLUCION);

        if(teclado.getKey() == '#')
        {

            return;

        }

        delay(500);

        //------------------------------------------------
        // Giro antihorario
        //------------------------------------------------

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Girando");

        lcd.setCursor(0,1);
        lcd.print("Antihorario");

        motorPasos.step(-PASOS_REVOLUCION);

        delay(500);

    }

}

//====================================================
// MÓDULO SENSOR DE NIVEL DE AGUA
//====================================================

void moduloNivelAgua()
{

    Serial.println();
    Serial.println("===== MODULO SENSOR DE NIVEL =====");

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Modulo");

    lcd.setCursor(0,1);
    lcd.print("Nivel Agua");

    delay(1500);

    while(true)
    {

        if(emergencia)
        {
            modoEmergencia();
        }

        if(teclado.getKey() == '#')
        {

            apagarLeds();

            digitalWrite(BUZZER_PIN, LOW);

            Serial.println("Saliendo del modulo Nivel de Agua");

            return;

        }

        int nivel = analogRead(NIVEL_PIN);

        Serial.print("Nivel de agua: ");
        Serial.println(nivel);

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Nivel:");

        lcd.setCursor(0,1);
        lcd.print(nivel);

        if(nivel < 300)
        {

            digitalWrite(LED_VERDE, HIGH);
            digitalWrite(LED_AMARILLO, LOW);
            digitalWrite(LED_ROJO, LOW);

            digitalWrite(BUZZER_PIN, LOW);

        }
        else if(nivel < 600)
        {

            digitalWrite(LED_VERDE, LOW);
            digitalWrite(LED_AMARILLO, HIGH);
            digitalWrite(LED_ROJO, LOW);

            digitalWrite(BUZZER_PIN, LOW);

        }
        else
        {

            digitalWrite(LED_VERDE, LOW);
            digitalWrite(LED_AMARILLO, LOW);
            digitalWrite(LED_ROJO, HIGH);

            digitalWrite(BUZZER_PIN, HIGH);

        }

        delay(300);

    }

}

//====================================================
// MODO EMERGENCIA
//====================================================

void modoEmergencia()
{

    apagarLeds();

    digitalWrite(BUZZER_PIN, LOW);

    servoMotor.write(90);

    while(true)
    {

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("**EMERGENCIA**");

        lcd.setCursor(0,1);
        lcd.print("Ingrese PIN");

        Serial.println("***** MODO EMERGENCIA *****");

        digitalWrite(LED_ROJO, HIGH);
        digitalWrite(LED_AMARILLO, HIGH);
        digitalWrite(LED_VERDE, HIGH);

        delay(500);

        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_AMARILLO, LOW);
        digitalWrite(LED_VERDE, LOW);

        delay(500);

        if(ingresarPassword())
        {

            lcd.clear();

            lcd.setCursor(0,0);
            lcd.print("Emergencia");

            lcd.setCursor(0,1);
            lcd.print("Finalizada");

            Serial.println("Emergencia finalizada");

            delay(1500);

            emergencia = false;

            return;

        }

    }

}