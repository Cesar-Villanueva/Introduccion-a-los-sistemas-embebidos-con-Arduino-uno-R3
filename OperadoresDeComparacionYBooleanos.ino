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

  int numeroUno = 12;
  int numeroDos = 10;

  Serial.println("=== OPERADORES DE COMPARACION, BOOLEANOS Y BITWISE ===");
  Serial.println();

  //====================================================
  // Operador de comparación ==
  //====================================================
  Serial.println("Operador == (Igual)");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  bool igual = (numeroUno == numeroDos);

  Serial.print("numeroUno == numeroDos: ");
  Serial.println(igual);
  Serial.println();

  //====================================================
  // Operador de comparación !=
  //====================================================
  Serial.println("Operador != (Diferente)");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  bool diferente = (numeroUno != numeroDos);

  Serial.print("numeroUno != numeroDos: ");
  Serial.println(diferente);
  Serial.println();

  //====================================================
  // Operador de comparación >
  //====================================================
  Serial.println("Operador > (Mayor que)");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  bool mayor = (numeroUno > numeroDos);

  Serial.print("numeroUno > numeroDos: ");
  Serial.println(mayor);
  Serial.println();

  //====================================================
  // Operador de comparación <
  //====================================================
  Serial.println("Operador < (Menor que)");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  bool menor = (numeroUno < numeroDos);

  Serial.print("numeroUno < numeroDos: ");
  Serial.println(menor);
  Serial.println();

  //====================================================
  // Operador de comparación >=
  //====================================================
  Serial.println("Operador >= (Mayor o igual)");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  bool mayorIgual = (numeroUno >= numeroDos);

  Serial.print("numeroUno >= numeroDos: ");
  Serial.println(mayorIgual);
  Serial.println();

  //====================================================
  // Operador de comparación <=
  //====================================================
  Serial.println("Operador <= (Menor o igual)");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  bool menorIgual = (numeroUno <= numeroDos);

  Serial.print("numeroUno <= numeroDos: ");
  Serial.println(menorIgual);
  Serial.println();

  //====================================================
  // Operador booleano &&
  //====================================================
  Serial.println("Operador && (AND)");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  bool operadorAND = (numeroUno > 5 && numeroDos > 5);

  Serial.print("(numeroUno > 5 && numeroDos > 5): ");
  Serial.println(operadorAND);
  Serial.println();

  //====================================================
  // Operador booleano ||
  //====================================================
  Serial.println("Operador || (OR)");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  bool operadorOR = (numeroUno < 5 || numeroDos > 5);

  Serial.print("(numeroUno < 5 || numeroDos > 5): ");
  Serial.println(operadorOR);
  Serial.println();

  //====================================================
  // Operador booleano !
  //====================================================
  Serial.println("Operador ! (NOT)");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  bool operadorNOT = !(numeroUno == numeroDos);

  Serial.print("!(numeroUno == numeroDos): ");
  Serial.println(operadorNOT);
  Serial.println();

  //====================================================
  // Operador Bitwise &
  //====================================================
  Serial.println("Operador Bitwise &");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  int bitAND = numeroUno & numeroDos;

  Serial.print("numeroUno & numeroDos: ");
  Serial.println(bitAND);
  Serial.println();

  //====================================================
  // Operador Bitwise |
  //====================================================
  Serial.println("Operador Bitwise |");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  int bitOR = numeroUno | numeroDos;

  Serial.print("numeroUno | numeroDos: ");
  Serial.println(bitOR);
  Serial.println();

  //====================================================
  // Operador Bitwise ^
  //====================================================
  Serial.println("Operador Bitwise ^");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);
  Serial.print("numeroDos = ");
  Serial.println(numeroDos);

  int bitXOR = numeroUno ^ numeroDos;

  Serial.print("numeroUno ^ numeroDos: ");
  Serial.println(bitXOR);
  Serial.println();

  //====================================================
  // Operador Bitwise <<
  //====================================================
  Serial.println("Operador Bitwise <<");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);

  int desplazamientoIzquierda = numeroUno << 1;

  Serial.print("numeroUno << 1: ");
  Serial.println(desplazamientoIzquierda);
  Serial.println();

  //====================================================
  // Operador Bitwise >>
  //====================================================
  Serial.println("Operador Bitwise >>");

  Serial.print("numeroUno = ");
  Serial.println(numeroUno);

  int desplazamientoDerecha = numeroUno >> 1;

  Serial.print("numeroUno >> 1: ");
  Serial.println(desplazamientoDerecha);
  Serial.println();

  Serial.println("=== FIN DEL EJEMPLO ===");
}

void loop() {
}

