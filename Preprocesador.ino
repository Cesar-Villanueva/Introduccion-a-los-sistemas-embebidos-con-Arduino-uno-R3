/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/


//====================================================
// PREPROCESADOR Y DIRECTIVAS EN ARDUINO
//====================================================

// Incluye la librería principal de Arduino
#include <Arduino.h>

// Define el pin del LED integrado
#define LED 13

// Descomenta la siguiente línea para habilitar
// los mensajes de depuración.
//#define DEBUG

void setup() {

  Serial.begin(9600);
  while (!Serial) {}

  pinMode(LED, OUTPUT);

  Serial.println("=== PREPROCESADOR Y DIRECTIVAS ===");
  Serial.println();

  //====================================================
  // Directiva #define
  //====================================================
  Serial.println("Directiva #define");

  Serial.print("Pin del LED = ");
  Serial.println(LED);

  Serial.println();

  //====================================================
  // Directiva #ifdef
  //====================================================
  Serial.println("Directiva #ifdef");

#ifdef DEBUG
  Serial.println("Modo DEBUG habilitado.");
#else
  Serial.println("Modo DEBUG deshabilitado.");
#endif

  Serial.println();

  //====================================================
  // Directiva #ifndef
  //====================================================
  Serial.println("Directiva #ifndef");

#ifndef SENSOR
  Serial.println("La constante SENSOR no esta definida.");
#endif

  Serial.println();

  //====================================================
  // Directiva #if
  //====================================================
  Serial.println("Directiva #if");

#if LED == 13
  Serial.println("El LED esta conectado al pin 13.");
#else
  Serial.println("El LED esta conectado a otro pin.");
#endif

  Serial.println();

  //====================================================
  // Directiva #else
  //====================================================
  Serial.println("Directiva #else");

#if defined(DEBUG)
  Serial.println("Se mostraran mensajes de depuracion.");
#else
  Serial.println("El programa se ejecuta en modo normal.");
#endif

  Serial.println();

  //====================================================
  // Directiva #endif
  //====================================================
  Serial.println("La directiva #endif finaliza un bloque condicional.");

  Serial.println();
  Serial.println("=== FIN DEL EJEMPLO ===");
}

void loop() {

  digitalWrite(LED, HIGH);
  delay(500);

  digitalWrite(LED, LOW);
  delay(500);
}

