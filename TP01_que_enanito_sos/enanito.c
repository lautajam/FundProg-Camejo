#include <stdio.h>

// CONSTANTES GLOBALES
const char   INIT_CHAR = ' ';
const char   LECHUGA   = 'A';
const char   BROCOLI   = 'B';
const char   ZANAHORIA = 'C';
const char   TOMATE    = 'D';
const char   INVIERNO  = 'I';
const char   VERANO    = 'V';
const int    INIT_INT           = 0;
const int    PUNTAJE_LECHUGA    = 0;
const int    PUNTAJE_BROCOLI    = 5;
const int    PUNTAJE_ZANAHORIA  = 10;
const int    PUNTAJE_TOMATE     = 15;
const int    PUNTAJE_INVIERNO   = 0;
const int    PUNTAJE_VERANO     = 10;
const int    MIN_VALOR_ENOJO    = 0;
const int    MAX_VALOR_ENOJO    = 5;
const int    MIN_TIEMPO_CULTIVO = 40;
const int    MAX_TIEMPO_CULTIVO = 120;
const int    MAX_VALOR_GRUÑON   = 9;
const int    MIN_VALOR_DORMILON = 10;
const int    MAX_VALOR_DORMILON = 19;
const int    MIN_VALOR_SABIO    = 20;
const int    MAX_VALOR_SABIO    = 29;
const int    MIN_VALOR_FELIZ    = 30;
const float  INIT_FLOAT         = 0;
const float  DIVISOR_PUNTAJE    = 8;

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

  char opcion_verdura  = INIT_CHAR;
  int  puntaje = INIT_INT;

  do
  {
    printf("¿Cuál es tu verdura favorita?\n");
    printf("(A) Lechuga, (B) Brócoli, (C) Zanahoria o (D) Tomate\n");
    scanf(" %c", &opcion_verdura);

    if (opcion_verdura == LECHUGA) {
      puntaje = PUNTAJE_LECHUGA;
    } else if (opcion_verdura == BROCOLI) {
        puntaje = PUNTAJE_BROCOLI;
    } else if (opcion_verdura == ZANAHORIA) {
        puntaje = PUNTAJE_ZANAHORIA;
    } else if (opcion_verdura == TOMATE) {
        puntaje = PUNTAJE_TOMATE;
    } else {
        printf("Error, no se ingresó una letra válida.\n");
    }

    // Limpiar el búfer de entrada
    while (getchar() != '\n');

  } while (opcion_verdura != LECHUGA && opcion_verdura != BROCOLI 
           && opcion_verdura!= ZANAHORIA && opcion_verdura != TOMATE);
  
  return puntaje;
}

/*
Pre: Recibe una referencia a un entero que va a contener el valor del condicion_pregunta_3.
Post: Se le hará una pregunta al usuario (si es team invierno o team verano) y en base a su
respuesta se le asignará un puntaje. Ese puntaje se devolverá por retorno.
  0: Invierno
  10: Verano
Tambien, modificará el valor del condicion_pregunta_3 por referencia.
  I: Invierno
  V: Verano
*/
int segunda_pregunta_team(char* condicion_pregunta_3){

  char opcion_team  = INIT_CHAR;
  int  puntaje = INIT_INT;

  do
  {
    printf("¿Sos team invierno o team verano?\n");
    printf("(I) Invierno\n");
    printf("(V) Verano\n");

    scanf(" %c", &opcion_team);

    if (opcion_team == INVIERNO){
      puntaje += PUNTAJE_INVIERNO;
    } else if (opcion_team == VERANO){
      puntaje += PUNTAJE_VERANO;
    } else{
      printf("Error, no se ingresó una letra válida.\n");
    }

    // Limpiar el búfer de entrada
    while (getchar() != '\n');

  } while (opcion_team != INVIERNO && opcion_team != VERANO);
  
  *condicion_pregunta_3 = opcion_team;

  return puntaje;
}

/*
  Pre: Recibe un char que contiene el valor de condicion_pregunta_3 (eleccion de team invierno o team verano).
  Post: Se le hará una pregunta al usuario (cuanto le enojan los mosquitos o trabajar abajo de la lluvia) dependiendo
  de la condicion_pregunta_3 (depende si es team verano o team invierno). En base a su respuesta numerica se le asignará
  un puntaje. Ese puntaje se devolverá por retorno.
    Desde 0 para 'No me enoja'
    Hasta 5 para 'Me enoja muchisimo'
*/
int tercer_pregunta_enojo(char condicion_pregunta_3){

  int puntaje = INIT_INT;
  int valor_enojo = INIT_INT;

  do{

    if (condicion_pregunta_3 == VERANO){
      printf("¿Cuánto te enojan los mosquitos?\n");
      printf("Escala: Desde (0) para 'No me enojan', hasta (5) para 'Me enojan muchisimo'\n");
    } else{ 
      printf("¿Cuánto te enoja trabajar abajo de la lluvia?\n");
      printf("Escala: Desde (0) para 'No me enoja', hasta (5) para 'Me enoja muchisimo'\n");
    }

    scanf("%i", &valor_enojo);

    if (valor_enojo >= MIN_VALOR_ENOJO && valor_enojo <= MAX_VALOR_ENOJO){
      puntaje = valor_enojo;
    } else{
      printf("Error, no se ingresó un valor válido.\n");
    }

    // Limpiar el búfer de entrada
    while (getchar() != '\n');

  } while (valor_enojo < MIN_VALOR_ENOJO || valor_enojo > MAX_VALOR_ENOJO);

  return puntaje;
}

/*
Pre: -
Post: -
*/
int cuarta_pregunta_cultivos(){

  int   puntaje        = INIT_INT;
  float tiempo_cultivo = INIT_FLOAT;

  do{
    printf("¿Cuánto tiempo te llevaría cosechar un cultivo de 10m²?\n");
    printf("El rango de minutos debe ser entre 40 y 120 en formato MM.mm (MM = Minutos y mm = Milesima de minuto)\n");
    scanf("%f", &tiempo_cultivo);

    if (tiempo_cultivo >= MIN_TIEMPO_CULTIVO && tiempo_cultivo <= MAX_TIEMPO_CULTIVO){
      puntaje = (int)(tiempo_cultivo / DIVISOR_PUNTAJE);
    } else{
      printf("Error, no se ingresó un valor válido.\n");
    }

    // Limpiar el búfer de entrada
    while (getchar() != '\n');
    
  } while (tiempo_cultivo < MIN_TIEMPO_CULTIVO || tiempo_cultivo > MAX_TIEMPO_CULTIVO);
  
  return puntaje;

}

/*
Pre: Se recibe una referencia a una variable de tipo char que va a contener la inicial del enanito.
Post: Se le harán preguntas al usuario y en base a sus respuestas se le asignará un enanito. El
enanito asignado será devuelto por referencia en el parámetro inicial_enanito que va a contener
su inicial.
  G: Gruñón
  D: Dormilón
  S: Sabio
  F: Feliz
*/
void calcular_enanito(char* inicial_enanito){
  
  int  puntaje              = INIT_INT;
  char condicion_pregunta_3 = INIT_CHAR;

  puntaje += primer_pregunta_verduras();

  printf("Puntaje hasta ahora: %i \n", puntaje);

  puntaje += segunda_pregunta_team(&condicion_pregunta_3);

  printf("Puntaje hasta ahora: %i \n", puntaje);

  printf("condicion_pregunta_3: %c \n", condicion_pregunta_3);

  puntaje -= tercer_pregunta_enojo(condicion_pregunta_3);

  printf("Puntaje hasta ahora: %i \n", puntaje);

  puntaje += cuarta_pregunta_cultivos();

  printf("Puntaje hasta ahora: %i \n", puntaje);

  if (puntaje <= MAX_VALOR_GRUÑON){
    *inicial_enanito = 'G';
  } else if (puntaje >= MIN_VALOR_DORMILON && puntaje <= MAX_VALOR_DORMILON) {
    *inicial_enanito = 'D';
  } else if (puntaje >= MIN_VALOR_SABIO && puntaje <= MAX_VALOR_SABIO) {
    *inicial_enanito = 'S';
  } else{
    *inicial_enanito = 'F';
  }

}

int main(void) {

  char inicial_enanito = INIT_CHAR;

  printf("Bienvenido al test para saber que enanito es compatible con vos!\n");
  printf("El test se basa en 4 preguntas para determinar cual de los enanitos es tu alma gemela!\n");
  printf("Cada pregunta tiene un puntaje asociado, y al final se suman todos los puntos para determinar el enanito.\n");

  calcular_enanito(&inicial_enanito);

  switch (inicial_enanito){
  case 'G':
    printf("El enanito màs compatible con vos es: -GRUÑON-\n");
    break;
  case 'D':
    printf("El enanito màs compatible con vos es: -DORMILON-\n");
    break;
  case 'S':
    printf("El enanito màs compatible con vos es: -SABIO-\n");
    break;
  case 'F':
    printf("El enanito màs compatible con vos es: -FELIZ-\n");
    break;
  
  default:
    printf("Hubo un error al realizar el test.\n");
    break;
  }

  return 0;
}