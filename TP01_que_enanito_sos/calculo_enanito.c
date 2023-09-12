#include <stdio.h>
#include "calculo_enanito.h"

// CONSTANTES GLOBALES y ESTATICAS
static const char INIT_CHAR = ' ';
const char   LECHUGA        = 'A';
const char   BROCOLI        = 'B';
const char   ZANAHORIA      = 'C';
const char   TOMATE         = 'D';
const char   INVIERNO       = 'I';
const char   VERANO         = 'V';
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
const float  DIVISOR_PUNTAJE_CULTIVO    = 8;

/*
Pre: -
Post: En base a su respuesta se le asignará un puntaje. 
      Ese puntaje se devolverá por retorno y podrá ser:
        00: Lechuga
        05: Brócoli
        10: Zanahoria
        15: Tomate
*/
int pregunta_verdura_favorita(){

  char verdura_favorita   = INIT_CHAR;
  int  puntaje_verdura_favorita    = INIT_INT;

  do {
    printf("\n¿Cuál es tu verdura favorita?\n");
    printf("(A) Lechuga, (B) Brócoli, (C) Zanahoria o (D) Tomate\n");
    scanf(" %c", &verdura_favorita);

    if (verdura_favorita == LECHUGA) {
        puntaje_verdura_favorita = PUNTAJE_LECHUGA;
    } else if (verdura_favorita == BROCOLI) {
        puntaje_verdura_favorita = PUNTAJE_BROCOLI;
    } else if (verdura_favorita == ZANAHORIA) {
        puntaje_verdura_favorita = PUNTAJE_ZANAHORIA;
    } else if (verdura_favorita == TOMATE) {
        puntaje_verdura_favorita = PUNTAJE_TOMATE;
    } else {
        printf("Error, no se ingresó una letra válida.");
    }

  } while (verdura_favorita != LECHUGA && verdura_favorita != BROCOLI 
           && verdura_favorita!= ZANAHORIA && verdura_favorita != TOMATE);
  
  return puntaje_verdura_favorita;
}

/*
Pre:  Recibe la referencia de team_estacion (team_invierno: I, team_verano: V).
Post: En base a su respuesta se le asignará un puntaje. 
      Ese puntaje se devolverá por retorno y podrá ser:
        00: Invierno
        10: Verano
      Tambien, modificará el valor del team_estacion por referencia:
        I: Invierno
        V: Verano
*/
int pregunta_team_estacion(char* team_estacion){

  char opcion_team_estacion  = INIT_CHAR;
  int  puntaje_team_estacion = INIT_INT;

  do {
    printf("\n¿Sos team invierno o team verano?\n");
    printf("(I) Invierno\n");
    printf("(V) Verano\n");

    scanf(" %c", &opcion_team_estacion);

    if (opcion_team_estacion == INVIERNO){
      puntaje_team_estacion += PUNTAJE_INVIERNO;
    } else if (opcion_team_estacion == VERANO){
      puntaje_team_estacion += PUNTAJE_VERANO;
    } else{
      printf("Error, no se ingresó una letra válida.");
    }

  } while (opcion_team_estacion != INVIERNO && opcion_team_estacion != VERANO);
  
  *team_estacion = opcion_team_estacion;

  return puntaje_team_estacion;
}

/*
Pre:  Recibe el valor de team_estacion (team_invierno: I, team_verano: V), de eso depende la pregunta.
Post: En base a su respuesta se le asignará un puntaje. 
      Ese puntaje se devolverá por retorno y podrá ser:
        Desde 0 para 'No me enoja'
        Hasta 5 para 'Me enoja muchisimo'
*/
int pregunta_enojo(char team_estacion){

  int puntaje_enojo           = INIT_INT;
  int valor_enojo_ingresado   = INIT_INT;

  do{

    if (team_estacion == VERANO){
      printf("\n¿Cuánto te enojan los mosquitos?\n");
      printf("Escala: Desde (0) para 'No me enojan', hasta (5) para 'Me enojan muchisimo'\n");
    } else{ 
      printf("\n¿Cuánto te enoja trabajar abajo de la lluvia?\n");
      printf("Escala: Desde (0) para 'No me enoja', hasta (5) para 'Me enoja muchisimo'\n");
    }

    scanf("%i", &valor_enojo_ingresado);

    if (valor_enojo_ingresado >= MIN_VALOR_ENOJO && valor_enojo_ingresado <= MAX_VALOR_ENOJO){
      puntaje_enojo = valor_enojo_ingresado;
    } else{
      printf("Error, no se ingresó un valor válido.");
    }

  } while (valor_enojo_ingresado < MIN_VALOR_ENOJO || valor_enojo_ingresado > MAX_VALOR_ENOJO);

  return puntaje_enojo;
}

/*
Pre:  -
Post: En base a su respuesta se le asignará un puntaje. 
      Ese puntaje se devolverá por retorno y podrá ser:
        Desde 5 puntos para 40 minutos
        Hasta 15 puntos para 120 minutos
*/
int pregunta_tiempo_cultivo(){

  int   puntaje_tiempo_cultivos = INIT_INT;
  float tiempo_cultivo   = INIT_FLOAT;

  do {
    printf("\n¿Cuánto tiempo te llevaría cosechar un cultivo de 10m²?\n");
    printf("El rango de minutos debe ser entre 40 y 120 en formato MM.mm (MM = Minutos y mm = Milesima de minuto)\n");
    scanf("%f", &tiempo_cultivo);

    if (tiempo_cultivo >= MIN_TIEMPO_CULTIVO && tiempo_cultivo <= MAX_TIEMPO_CULTIVO){
      puntaje_tiempo_cultivos = (int)(tiempo_cultivo / DIVISOR_PUNTAJE_CULTIVO);
    } else{
      printf("Error, no se ingresó un valor válido.");
    }

  } while (tiempo_cultivo < MIN_TIEMPO_CULTIVO || tiempo_cultivo > MAX_TIEMPO_CULTIVO);
  
  return puntaje_tiempo_cultivos;

}

/*
Pre:  -
Post: En base a sus respuestas se le asignará un puntaje. 
      Ese puntaje se devolverá por retorno y podrá ser:
        Desde 0 puntos
        Hasta 40 puntos
*/
int puntaje_enanito(){

  int  puntaje_enanito_total = INIT_INT;
  char estacion_team         = INIT_CHAR;

  puntaje_enanito_total += pregunta_verdura_favorita();

  printf("Puntaje hasta ahora: %i \n", puntaje_enanito_total);

  puntaje_enanito_total += pregunta_team_estacion(&estacion_team);

  printf("Puntaje hasta ahora: %i \n", puntaje_enanito_total);

  printf("team_estacion: %c \n", estacion_team);

  puntaje_enanito_total -= pregunta_enojo(estacion_team);

  printf("Puntaje hasta ahora: %i \n", puntaje_enanito_total);

  puntaje_enanito_total += pregunta_tiempo_cultivo();

  printf("Puntaje hasta ahora: %i \n", puntaje_enanito_total);

  return puntaje_enanito_total;

}

/*
Pre:  Se recibe una referencia a una variable de tipo char que va a contener la inicial del enanito.
Post: Se calculará la inicial del enanito en base al puntaje obtenido. 
      Se modificará el valor de la variable inicial_enanito por referencia.
        G: Gruñón
        D: Dormilón
        S: Sabio
        F: Feliz
*/
void calcular_enanito(char* inicial_enanito){
  
  int puntaje = INIT_INT;

  puntaje = puntaje_enanito();

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
