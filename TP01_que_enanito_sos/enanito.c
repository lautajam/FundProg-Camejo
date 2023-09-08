#include <stdio.h>

// CONSTANTES
const char LECHUGA   = 'A';
const char BROCOLI   = 'B';
const char ZANAHORIA = 'C';
const char TOMATE    = 'D';
const char INVIERNO  = 'I';
const char VERANO    = 'V';
const char INIT_CHAR = ' ';
const int  INIT_INT  = 0;
const int  PUNTAJE_LECHUGA    = 0;
const int  PUNTAJE_BROCOLI    = 5;
const int  PUNTAJE_ZANAHORIA  = 10;
const int  PUNTAJE_TOMATE     = 15;
const int  PUNTAJE_INVIERNO   = 0;
const int  PUNTAJE_VERANO     = 10;
const int  MIN_TIEMPO_CULTIVO = 40;
const int  MAX_TIEMPO_CULTIVO = 120;
const int  MIN_VALOR_ENOJO    = 0;
const int  MAX_VALOR_ENOJO    = 5;

/*
Pre: -
Post: Se le hará una pregunta al usuario (cual es su verdura favorita) y en base a su 
respuesta se le asignará un puntaje. Ese puntaje se devolverá por retorno.
  0: Lechuga
  5: Brócoli
  10: Zanahoria
  15: Tomate
*/
int primer_pregunta_verduras(){

  char opcion  = INIT_CHAR;
  int  puntaje = INIT_INT;

  do
  {
    printf("¿Cuál es tu verdura favorita?\n");
    printf("(A) Lechuga, (B) Brócoli, (C) Zanahoria o (D) Tomate\n");
    scanf(" %c", &opcion);

    if (opcion == LECHUGA) {
        puntaje = PUNTAJE_LECHUGA;
    } else if (opcion == BROCOLI) {
        puntaje = PUNTAJE_BROCOLI;
    } else if (opcion == ZANAHORIA) {
        puntaje = PUNTAJE_ZANAHORIA;
    } else if (opcion == TOMATE) {
        puntaje = PUNTAJE_TOMATE;
    } else {
        printf("Error, no se ingresó una letra válida.");
    }
    
  } while (opcion != LECHUGA && opcion != BROCOLI && opcion != ZANAHORIA && opcion != TOMATE);
  
  return puntaje;
}

/*
Pre: Recibe una referencia a un entero que va a contener el valor del condicion_pregunta_3.
Post: Se le hará una pregunta al usuario (si es team invierno o team verano) y en base a su
respuesta se le asignará un puntaje. Ese puntaje se devolverá por retorno.
  0: Invierno
  10: Verano
Tambien, modificará el valor del condicion_pregunta_3 por referencia.
  0: Invierno
  1: Verano
*/
int segunda_pregunta_team(char* condicion_pregunta_3){

  char opcion  = INIT_CHAR;
  int  puntaje = INIT_INT;

  do
  {
    printf("¿Sos team invierno o team verano?\n");
    printf("(I) Invierno\n");
    printf("(V) Verano\n");

    scanf(" %c", &opcion);

    if (opcion == INVIERNO)
    {
      puntaje += PUNTAJE_INVIERNO;
    }
    else if (opcion == VERANO)
    {
      puntaje += PUNTAJE_VERANO;
    }
    else
    {
      printf("Error, no se ingresó una letra válida.");
    }
  } while (opcion != INVIERNO && opcion != VERANO);
  
  *condicion_pregunta_3 = opcion;

  return puntaje;
}

/*
Pre: Se recibe una referencia a una variable de tipo char que va a contener la inicial del enanito.
Post: Se le harán preguntas al usuario y en base a sus respuestas se le asignará un enanito. El
enanito asignado será devuelto por referencia en el parámetro inicial_enanito que va a contenr
su inicial.
  G: Gruñón
  D: Dormilón
  S: Sabio
  F: Feliz
*/
void calcular_enanito(char* inicial_enanito){
  
  int puntaje               = INIT_INT;
  char condicion_pregunta_3 = INIT_CHAR;

  puntaje += primer_pregunta_verduras();

  printf("Puntaje hasta ahora: %i \n", puntaje);

  puntaje += segunda_pregunta_team(&condicion_pregunta_3);

  printf("Puntaje hasta ahora: %i \n", puntaje);

  printf("condicion_pregunta_3: %c \n", condicion_pregunta_3);



}

int main(void) {

  char inicial_enanito = INIT_CHAR;

  printf("Bienvenido al test para saber que enanito es compatible con vos!\n");
  printf("El test se basa en 4 preguntas para determinar cual de los enanitos es tu alma gemela!\n");

  calcular_enanito(&inicial_enanito);

  return 0;
}