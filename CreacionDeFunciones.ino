/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/


// Declaración de la función
int sumar(int num1, int num2) {
  return num1 + num2;
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  int valor1 = 5;
  int valor2 = 10;

  // Llamada a la función
  int resultado = sumar(valor1, valor2);

  Serial.println("=== EJEMPLO DE FUNCION EN ARDUINO ===");
  Serial.print("Valor1 = ");
  Serial.println(valor1);

  Serial.print("Valor2 = ");
  Serial.println(valor2);

  Serial.print("Suma = ");
  Serial.println(resultado);
}

void loop() {
  // No hace nada
}

