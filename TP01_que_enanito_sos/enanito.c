#include <stdio.h>
#include "calculo_enanito.h"

#define GRUNION  'G'
#define DORMILON 'D'
#define SABIO    'S'
#define FELIZ    'F'
static const char INIT_CHAR = ' ';

int main(void) {

  char inicial_enanito = INIT_CHAR;

  printf("Bienvenido al test para saber que enanito es compatible con vos!\n");
  printf("El test se basa en 4 preguntas para determinar cual de los enanitos es tu alma gemela!\n");
  printf("Cada pregunta tiene un puntaje asociado, y al final se suman todos los puntos para determinar el enanito.\n");

  calcular_enanito(&inicial_enanito);

  switch (inicial_enanito){
  case GRUNION:
    printf("\nEl enanito más compatible con vos es: -GRUÑON-\n");
    break;
  case DORMILON:
    printf("\nEl enanito más compatible con vos es: -DORMILON-\n");
    break;
  case SABIO:
    printf("\nEl enanito más compatible con vos es: -SABIO-\n");
    break;
  case FELIZ:
    printf("\nEl enanito más compatible con vos es: -FELIZ-\n");
    break;
  
  default:
    printf("\nHubo un error al realizar el test.\n");
    break;
  }

  return 0;
}