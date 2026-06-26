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

  Serial.println("=== INFORMACION DE TIPOS DE DATOS EN ARDUINO ===");
  Serial.println();

  Serial.println("Tipo: bool / boolean");
  Serial.println("sizeof:");
  Serial.println(sizeof(bool));
  Serial.println("Bits: 8");
  Serial.println("Rango: true / false");
  Serial.println();

  Serial.println("Tipo: byte / unsigned char");
  Serial.println("sizeof:");
  Serial.println(sizeof(byte));
  Serial.println("Bits: 8");
  Serial.println("Rango: 0 a 255");
  Serial.println();

  Serial.println("Tipo: char");
  Serial.println("sizeof:");
  Serial.println(sizeof(char));
  Serial.println("Bits: 8");
  Serial.println("Rango: -128 a 127");
  Serial.println();

  Serial.println("Tipo: int / short");
  Serial.println("sizeof:");
  Serial.println(sizeof(int));
  Serial.println("Bits: 16");
  Serial.println("Rango: -32768 a 32767");
  Serial.println();

  Serial.println("Tipo: unsigned int / word");
  Serial.println("sizeof:");
  Serial.println(sizeof(unsigned int));
  Serial.println("Bits: 16");
  Serial.println("Rango: 0 a 65535");
  Serial.println();

  Serial.println("Tipo: long");
  Serial.println("sizeof:");
  Serial.println(sizeof(long));
  Serial.println("Bits: 32");
  Serial.println("Rango: -2147483648 a 2147483647");
  Serial.println();

  Serial.println("Tipo: unsigned long");
  Serial.println("sizeof:");
  Serial.println(sizeof(unsigned long));
  Serial.println("Bits: 32");
  Serial.println("Rango: 0 a 4294967295");
  Serial.println();

  Serial.println("Tipo: float");
  Serial.println("sizeof:");
  Serial.println(sizeof(float));
  Serial.println("Bits: 32");
  Serial.println("Rango: ~3.4E38");
  Serial.println();

  Serial.println("Tipo: double (en Arduino UNO es igual a float)");
  Serial.println("sizeof:");
  Serial.println(sizeof(double));
  Serial.println("Bits: 32");
  Serial.println("Rango: ~3.4E38");
  Serial.println();

  Serial.println("Tipo: size_t");
  Serial.println("sizeof:");
  Serial.println(sizeof(size_t));
  Serial.println("Bits: 16");
  Serial.println("Rango: 0 a 65535");
  Serial.println();

  Serial.println("Tipo: array (depende del tipo)");
  Serial.println("Ejemplo: int valores[5]");
  Serial.println("sizeof int valores[5]:");
  int valores[5] = {1, 2, 3, 4, 5};
  Serial.println(sizeof(valores));
  Serial.println("Bits totales: 80 (5 enteros de 16 bits)");
  Serial.println();

  Serial.println("Tipo: void");
  Serial.println("sizeof: N/A");
  Serial.println("Bits: N/A");
  Serial.println("Rango: No aplica (sin retorno)");
  Serial.println();

  Serial.println("=== FIN DE LA INFORMACION ===");
}

void loop() {
}