/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  // Variables iniciales
  int numeroUno = 15;
  int numeroDos = 4;

  int suma = numeroUno + numeroDos;                 // + suma
  int resta = numeroUno - numeroDos;                // - resta
  int multiplicacion = numeroUno * numeroDos;       // * multiplicación
  int division = numeroUno / numeroDos;             // / división entera
  int residuo = numeroUno % numeroDos;              // % residuo
  int asignacion = 20;                              // = asignación

  // Imprimir resultados
  Serial.println("=== OPERADORES ARITMETICOS EN ARDUINO ===");
  Serial.println();

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);

  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  Serial.println();

  Serial.print("Suma (numeroUno + numeroDos) = ");
  Serial.println(suma);

  Serial.print("Resta (numeroUno - numeroDos) = ");
  Serial.println(resta);

  Serial.print("Multiplicacion (numeroUno * numeroDos) = ");
  Serial.println(multiplicacion);

  Serial.print("Division entera (numeroUno / numeroDos) = ");
  Serial.println(division);

  Serial.print("Residuo (numeroUno % numeroDos) = ");
  Serial.println(residuo);

  Serial.print("Asignacion (asignacion = 20) = ");
  Serial.println(asignacion);
}

void loop() {
  // No hace nada
}