/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/

// Macro para el pin del LED
#define LED_INTERNO 13

// Macro para configurar un pin como salida
#define CONFIGURAR_SALIDA(pin) pinMode(pin, OUTPUT)

// Macro para encender un LED
#define ENCENDER_LED(pin) digitalWrite(pin, HIGH)

// Macro para apagar un LED
#define APAGAR_LED(pin) digitalWrite(pin, LOW)

// Macro para esperar un tiempo
#define ESPERAR(ms) delay(ms)

void setup() {

  Serial.begin(9600);
  while (!Serial) {}

  Serial.println("=== EJEMPLO DE MACROS ===");

  // Configurar el LED interno
  CONFIGURAR_SALIDA(LED_INTERNO);

  Serial.println("LED configurado como salida.");
}

void loop() {

  Serial.println("LED ENCENDIDO");
  ENCENDER_LED(LED_INTERNO);
  ESPERAR(1000);

  Serial.println("LED APAGADO");
  APAGAR_LED(LED_INTERNO);
  ESPERAR(1000);
}

