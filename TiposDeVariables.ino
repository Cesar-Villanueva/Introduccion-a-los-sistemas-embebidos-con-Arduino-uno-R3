/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/

// ===============================
// EJEMPLO DE TIPOS DE VARIABLES
// ===============================

// Variable global
int contadorGlobal = 0;

// Variable constante
const int LED = 13;

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  Serial.println("=== EJEMPLO DE VARIABLES EN ARDUINO ===");
  Serial.println();

  // Uso de la variable constante
  Serial.print("Constante LED = ");
  Serial.println(LED);

  // Uso de la variable global
  contadorGlobal++;
  Serial.print("Variable global = ");
  Serial.println(contadorGlobal);

  // Uso de la variable local
  int contadorLocal = 10;
  contadorLocal++;
  Serial.print("Variable local = ");
  Serial.println(contadorLocal);

  // Uso de la variable static
  funcionStatic();

  Serial.println();
  Serial.println("Variable volatile:");
  Serial.println("Se utiliza cuando una variable");
  Serial.println("puede cambiar fuera del programa");
  Serial.println("principal, por ejemplo mediante");
  Serial.println("una interrupcion o por hardware.");
  Serial.println("Su funcion es evitar que el");
  Serial.println("compilador optimice su lectura.");

  Serial.println();
  Serial.println("=== FIN DEL EJEMPLO ===");
}

void loop() {
}

// Función para demostrar una variable static
void funcionStatic() {
  static int contadorStatic = 0;

  contadorStatic++;

  Serial.print("Variable static = ");
  Serial.println(contadorStatic);

  contadorStatic++;

  Serial.print("Variable static despues de incrementar = ");
  Serial.println(contadorStatic);
}