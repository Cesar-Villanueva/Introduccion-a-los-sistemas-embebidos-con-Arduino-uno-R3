/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/


//====================================================
// PRACTICA SEMAFORO 
//====================================================

// Definición de pines
#define LED_ROJO      13
#define LED_AMARILLO  12
#define LED_VERDE     11

// Definición de tiempos (ms)
#define TIEMPO_VERDE      2000
#define TIEMPO_PARPADEO    250
#define TIEMPO_AMARILLO   1500
#define TIEMPO_ROJO       5000

void setup() {

  // Configurar los pines como salidas
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

}

void loop() {

  //=========================================
  // Luz verde durante 2 segundos
  //=========================================
  digitalWrite(LED_VERDE, HIGH);
  delay(TIEMPO_VERDE);

  //=========================================
  // Parpadeo del LED verde
  // (4 veces en aproximadamente 2 segundos)
  //=========================================
  for (int i = 0; i < 4; i++) {

    digitalWrite(LED_VERDE, LOW);
    delay(TIEMPO_PARPADEO);

    digitalWrite(LED_VERDE, HIGH);
    delay(TIEMPO_PARPADEO);

  }

  digitalWrite(LED_VERDE, LOW);

  //=========================================
  // Luz amarilla durante 1.5 segundos
  //=========================================
  digitalWrite(LED_AMARILLO, HIGH);
  delay(TIEMPO_AMARILLO);
  digitalWrite(LED_AMARILLO, LOW);

  //=========================================
  // Luz roja durante 5 segundos
  //=========================================
  digitalWrite(LED_ROJO, HIGH);
  delay(TIEMPO_ROJO);
  digitalWrite(LED_ROJO, LOW);

}

