/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/

#define LED_PIN 13

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  Serial.println("=== EJEMPLOS DE ESTRUCTURAS DE CONTROL ===");

  int contador = 0;

  // 1. if...else
  if (contador == 0) {
    Serial.println("if: contador es 0");
  } else {
    Serial.println("else: contador no es 0");
  }

  // 2. for
  for (int i = 0; i < 3; i++) {
    Serial.print("for: i = ");
    Serial.println(i);
  }

  // 3. while
  int j = 0;
  while (j < 2) {
    Serial.print("while: j = ");
    Serial.println(j);
    j++;
  }

  // 4. do...while
  int k = 0;
  do {
    Serial.print("do...while: k = ");
    Serial.println(k);
    k++;
  } while (k < 2);

  // 5. switch...case
  int opcion = 1;
  switch (opcion) {
    case 0:
      Serial.println("switch: opcion 0");
      break;

    case 1:
      Serial.println("switch: opcion 1");
      break;

    default:
      Serial.println("switch: opcion por defecto");
      break;
  }

  // 6. break y continue dentro de un for
  for (int n = 0; n < 5; n++) {

    if (n == 3)
      break;      // Sale del bucle cuando n == 3

    if (n == 1)
      continue;   // Omite la iteración cuando n == 1

    Serial.print("break/continue ejemplo: n = ");
    Serial.println(n);
  }

  // 7. goto
  Serial.println("Antes de goto");

  goto etiqueta;

  Serial.println("Esto se salta con goto");

etiqueta:
  Serial.println("Despues de goto");

  // 8. return (en setup para terminar la ejecución)
  Serial.println("Ejemplo de return");

  return;
}

void loop() {
  // No hace nada
}