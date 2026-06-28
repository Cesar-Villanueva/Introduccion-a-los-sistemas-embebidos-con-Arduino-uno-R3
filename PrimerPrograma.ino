/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/

// Definición de constantes mediante macros
#define PIN_LED 13
#define RETARDO 1000

void setup() {
  // Configurar el pin del LED como salida
  pinMode(PIN_LED, OUTPUT);

  Serial.print("Pin del LED: ");
  Serial.println(PIN_LED);

  Serial.print("Retardo: ");
  Serial.print(RETARDO);
  Serial.println(" ms");
}

void loop() {

  // Encender el LED
  Serial.println("LED ENCENDIDO");
  digitalWrite(PIN_LED, HIGH);
  delay(RETARDO);

  // Apagar el LED
  Serial.println("LED APAGADO");
  digitalWrite(PIN_LED, LOW);
  delay(RETARDO);
}

