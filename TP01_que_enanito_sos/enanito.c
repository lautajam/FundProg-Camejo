#include <stdio.h>

// CONSTANTES
const char LECHUGA   = 'A';
const char BROCOLI   = 'B';
const char ZANAHORIA = 'C';
const char TOMATE    = 'D';
const char INVIERNO  = 'I';
const char VERANO    = 'V';
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

  char opcion  = ' ';
  int  puntaje = 0;

  do
  {
    printf("¿Cuál es tu verdura favorita?\n");
    printf("(A) Lechuga, (B) Brócoli, (C) Zanahoria o (D) Tomate\n");
    scanf(" %c", &opcion);

    if (opcion == LECHUGA) {
        puntaje = 0;
    } else if (opcion == BROCOLI) {
        puntaje = 5;
    } else if (opcion == ZANAHORIA) {
        puntaje = 10;
    } else if (opcion == TOMATE) {
        puntaje = 15;
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
int segunda_pregunta_team(int* condicion_pregunta_3){

  char opcion  = ' ';
  int  puntaje = 0;

  do
  {
    printf("¿Sos team invierno o team verano?\n");
    printf("(I) Invierno\n");
    printf("(V) Verano\n");

    scanf(" %c", &opcion);

    if (opcion == INVIERNO)
    {
      puntaje               += 0;
      *condicion_pregunta_3  = 0;
    }
    else if (opcion == VERANO)
    {
      puntaje               += 10;
      *condicion_pregunta_3  = 1;
    }
    else
    {
      printf("Error, no se ingresó una letra válida.");
    }
  } while (opcion != INVIERNO && opcion != VERANO);
  
  return puntaje;
}

/*
Pre: -
Post: Se le harán preguntas al usuario y en base a sus respuestas se le asignará un enanito. El
enanito asignado será devuelto por referencia en el parámetro inicial_enanito que va a contenr
su inicial.
  G: Gruñón
  D: Dormilón
  S: Sabio
  F: Feliz
*/
void calcular_enanito(char* inicial_enanito){
  
  int puntaje              = 0;
  int condicion_pregunta_3 = 0;

  puntaje += primer_pregunta_verduras();

  printf("Puntaje hasta ahora: %i \n", puntaje);

  puntaje += segunda_pregunta_team(&condicion_pregunta_3);

  printf("Puntaje hasta ahora: %i \n", puntaje);

  printf("condicion_pregunta_3: %i \n", condicion_pregunta_3);

}

int main(void) {

  char inicial_enanito = ' ';

  printf("Bienvenido al test para saber que enanito es compatible con vos!\n");
  printf("El test se basa en 4 preguntas para determinar cual de los enanitos es tu alma gemela!\n");

  calcular_enanito(&inicial_enanito);

  return 0;
}