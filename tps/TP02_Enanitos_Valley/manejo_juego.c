#include <stdio.h>
#include <stdbool.h>
#include <time.h>   // Para obtener una semilla desde el reloj
#include <stdlib.h> // Para usar rand
#include "manejo_juego.h"
#include "granja.h"

// Tamaño del mapa
#define TAMAÑO_TERRENO 20
const int CENTRO_BORDE_HUERTO = 1;

// Letras de los enanitos
#define GRUÑON   'G'
#define FELIZ    'F'
#define DORMILON 'D'
#define SABIO    'S'

// Valores iniciales de los atributos
static const int  INIT_INT         = 0;
const int         INIT_MOV_PLAGADO = 10;
const int  INIT_INSECTICIDAS       = 3;
const int  INIT_OBJETO             = 0;
const int  MAX_ESPINAS             = 5;
const int  MONEDAS_DEFAULT         = 0;
const char INIT_CANASTA            = ' ';
static const char CULTIVO_VACIO    = 'C';
static const char ESPINA           = 'E';
const int  INIT_FERTILIZANTE       = false;
const bool INIT_CULTIVO_OCUPADO    = false;
const bool INIT_PLAGADO            = false;
static const int INIT_CONTADOR_CULTIVOS = 1; 

// Valores de las monedas de cada enanito
const int MONEDAS_GRUÑON   = 150;
const int MONEDAS_DORMILON = 200;
const int MONEDAS_SABIO    = 250;
const int MONEDAS_FELIZ    = 300;

// Valores de las monedas por cada cultivo
const int MONEDAS_TOMATE_COMPRA    = 5;
const int MONEDAS_ZANAHORIA_COMPRA = 10;
const int MONEDAS_BROCOLI_COMPRA   = 15;
const int MONEDAS_LECHUGA_COMPRA   = 20;

// Valores booleanos para los cultivos
static const bool CULTIVO_OCUPADO    = true;
//static const bool CULTIVO_DESOCUPADO = false;
const bool CENTRO_CULTIVO_NO_GENERADO     = false;
const bool CENTRO_CULTIVO_GENERADO        = true;

/* Funciones extras y necesarias */
/*
    Pre:  Recibe dos valores, un valor mínimo y un valor máximo para el rango
    Post: Devuelve un número aleatorio dentro del rango
*/
int random_number(int min, int max) {
    int numero = rand() % max + min;
    return numero;
}

/* 
    Pre:  Recibe la inicial del enanito conseguida en el test
    Post: Devuelve la cantidad de monedas iniciales del personaje dependiendo de la inicial del enanito
            - Gruñoon:  150 monedas
            - Dormilon: 200 monedas
            - Sabio:    250 monedas
            - Feliz:    300 monedas
*/
int calcular_monedas_iniciales(char enanito){
    int monedas_iniciales = INIT_INT;
    switch (enanito) {
        case GRUÑON:
            monedas_iniciales = MONEDAS_GRUÑON;
            break;
        case DORMILON:
            monedas_iniciales = MONEDAS_DORMILON;
            break;
        case SABIO:
            monedas_iniciales = MONEDAS_SABIO;
            break;
        case FELIZ:
            monedas_iniciales = MONEDAS_FELIZ;
            break;
        default:
            monedas_iniciales = MONEDAS_DEFAULT;
            break;
    }
    return monedas_iniciales;
}

/*
    Pre:  Recibe dos coordenadas para comparar
    Post: Devuelve true si las coordenadas son iguales, sino devuelve false
*/
bool posicion_igual(coordenada_t posicion_1, coordenada_t posicion_2){
    return posicion_1.fila == posicion_2.fila && posicion_1.columna == posicion_2.columna;
}

/*
    Pre:  Recibe un las coordenadas del deposito y la lista de huertas
    Post: Chequea si las coordenadas del deposito coinciden con las de algun cultivo
          En caso que coincidan, devuelve false, sino devuelve true
*/
bool posicion_valida_huertas(coordenada_t posicion_verificar, huerta_t huerta[MAX_HUERTA]){

    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        for (int j = INIT_INT; j < MAX_PLANTAS; j++) {
            if (posicion_verificar.fila    == huerta[i].cultivos[j].posicion.fila &&
                posicion_verificar.columna == huerta[i].cultivos[j].posicion.columna) {
                return false;
            }
        }
    }
    return true;
}

/*
    Pre:  Recibe un las coordenadas a verificar y la lista de objetos
    Post: Chequea si las coordenadas a chequear coinciden con las de algun objeto
          En caso que coincidan, devuelve true, sino devuelve false
*/
bool hay_objeto( coordenada_t posicion_verificar, objeto_t objetos[MAX_OBJETOS]){

    for (int i = INIT_INT; i < MAX_OBJETOS; i++) {
        if (posicion_verificar.fila    == objetos[i].posicion.fila &&
            posicion_verificar.columna == objetos[i].posicion.columna) {
            return true;
        }
    }
    return false;
}

/* Inicializar personaje*/
/*
    Pre:  Recibe un las coordenadas a verificar y el juego para leer
    Post: Chequea si las coordenadas a chequear coinciden con las d algo en el mapa
          En caso que coincidan, devuelve true, sino devuelve false
*/
bool posicion_valida_personaje(coordenada_t posicion_verificar, juego_t juego){
    if (posicion_valida_huertas(posicion_verificar, juego.huertas)){
        if (!posicion_igual(posicion_verificar, juego.deposito)){ // chequea el deposito
            if (!hay_objeto(posicion_verificar, juego.objetos)){
                return true;
            }
        }
    }
    return false;
}

/* 
    Pre:  Recibe las coordenadas del personaje (en forma de puntero para modificarlas), la lista de huertas y 
          las coordenadas del deposito
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa y chequea que las coordenadas del 
          personaje no coincidan con las de algun cultivo, ni con el deposito en caso que coincidan, vuelve a 
          generar la coordenadas
*/
void generar_coordenadas_iniciales_personaje(coordenada_t* coordenadas_personaje, juego_t juego){
    do{
        coordenadas_personaje->fila    = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        coordenadas_personaje->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
    } while (!posicion_valida_personaje(*coordenadas_personaje, juego));
}

/*
    Pre: Recibe un personaje (en forma de puntero para modificarlo) la inicial del enanito, la lista de huertas 
         y las coordenadas del deposito
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa (no pisando el deposito ni los cultivos)
            - Calcula las monedas iniciales del personaje dependiendo de la inicial del enanito
            - Inicia la canasta con valores vacios
            - Inicia los insecticidas con INIT_INSECTICIDAS (es 3, valor pedido por la consigna)
            - Inicia el fertilizante con INIT_FERTILIZANTE (es false, valor pedido por la consigna)
*/
void inicializar_personaje(personaje_t* personaje, char enanito, juego_t juego){

    coordenada_t coordenadas_iniciales_personaje;
    generar_coordenadas_iniciales_personaje(&coordenadas_iniciales_personaje, juego);
    personaje->posicion = coordenadas_iniciales_personaje;

    personaje->tiene_fertilizante = INIT_FERTILIZANTE;

    personaje->cant_insecticidas = INIT_INSECTICIDAS;

    personaje->cant_monedas = calcular_monedas_iniciales(enanito);

    for (int i = INIT_INT; i < MAX_CANASTA; i++) {
        personaje->canasta[i] = INIT_CANASTA;
    }

    personaje->tope_canasta = INIT_INT;
}

/* Inicializar deposito*/
/* 
    Pre:  Recibe las coordenadas del deposito (en forma de puntero para modificarlas) y la lista de huertas
    Post: Inicializa el deposito con una posicion aleatoria dentro del mapa y chequea que las coordenadas del 
          deposito no coincidan con las de algun cultivo, en caso que coincidan, vuelve a generar la coordenadas
*/
void inicializar_deposito(coordenada_t* deposito, huerta_t huerta[MAX_HUERTA]){
    do{
        deposito->fila = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        deposito->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
    } while (!posicion_valida_huertas(*deposito, huerta));
}

/* Inicializar huertas y cultivos*/
/* 
    Pre:  Recibe unas coordenadas de un cultivo (en forma de puntero para modificarlas)
    Post: Setea las cooredenas del cultivo con valores aleatorios dentro del mapa
*/
void coordenadas_cultivo(coordenada_t* coordenadas_cultivo, juego_t juego){
    int contador_cultivos;
    
    do{
        contador_cultivos = INIT_INT;
        coordenadas_cultivo->fila    = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        coordenadas_cultivo->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);

        int fila_inicial    = coordenadas_cultivo->fila - CENTRO_BORDE_HUERTO;
        int fila_final      = coordenadas_cultivo->fila + CENTRO_BORDE_HUERTO;
        int columna_inicial = coordenadas_cultivo->columna - CENTRO_BORDE_HUERTO;
        int columna_final   = coordenadas_cultivo->columna + CENTRO_BORDE_HUERTO;

        for (int fila = fila_inicial; fila <= fila_final; fila++) {
            for (int columna = columna_inicial; columna <= columna_final; columna++) {

                coordenada_t coordenadas_cultivo_test;
                coordenadas_cultivo_test.fila    = fila;
                coordenadas_cultivo_test.columna = columna;

                if (posicion_valida_huertas(coordenadas_cultivo_test, juego.huertas)) {
                    contador_cultivos++;
                }
            }
        }
    }while(contador_cultivos < MAX_PLANTAS);
}

/* 
    Pre:  Recibe un array de cultivos
    Post: Inicializa los cultivos:
            - Inicializa el movimiento_plantado con INIT_MOV_PLAGADO (es 10, valor pedido por la consigna)
            - Inicializa el tipo con CULTIVO_VACIO (es 'C', valor pedido por la consigna)
            - Inicializa el ocupado con INIT_CULTIVO_OCUPADO (es false, valor pedido por la consigna)
            - Inicializa las coordenadas de los cultivos con coordenadas aleatorias dentro del mapa
*/
void inicializar_cultivos(cultivo_t cultivos[MAX_PLANTAS], juego_t juego){

    coordenada_t coordenadas_cultivo_medio;

    coordenadas_cultivo(&coordenadas_cultivo_medio, juego);

    int index_cultivos = INIT_INT;
    int fila_inicial = coordenadas_cultivo_medio.fila - CENTRO_BORDE_HUERTO;
    int fila_final = coordenadas_cultivo_medio.fila + CENTRO_BORDE_HUERTO;
    int columna_inicial = coordenadas_cultivo_medio.columna - CENTRO_BORDE_HUERTO;
    int columna_final = coordenadas_cultivo_medio.columna + CENTRO_BORDE_HUERTO;

    for (int fila = fila_inicial; fila <= fila_final; fila++) {
        for (int columna = columna_inicial; columna <= columna_final; columna++) {
            if (index_cultivos < MAX_PLANTAS) {
                cultivos[index_cultivos].movimiento_plantado = INIT_MOV_PLAGADO;
                cultivos[index_cultivos].tipo = CULTIVO_VACIO;
                cultivos[index_cultivos].ocupado = INIT_CULTIVO_OCUPADO;

                cultivos[index_cultivos].posicion.fila = fila;
                cultivos[index_cultivos].posicion.columna = columna;
                
                index_cultivos++;
            }
        }
    }
}

/* 
  Pre:  Recibe el juego (para leerlo)
  Post: Devuelve una huerta inicializada con los valores pedidos por la consigna
            - Inicializa el movimiento_plantado con INIT_MOV_PLAGADO (es 10, valor pedido por la consigna)
            - Inicializa el tipo con CULTIVO_VACIO (es 'C', valor pedido por la consigna)
            - Inicializa el ocupado con INIT_CULTIVO_OCUPADO (es false, valor pedido por la consigna)
            - Inicializa los cultivos con la funcion inicializar_cultivos()
*/
huerta_t inicializar_huerta(juego_t juego){

    huerta_t huerta;

    huerta.movimientos_plagado = INIT_MOV_PLAGADO;
    huerta.plagado             = INIT_PLAGADO;
    
    cultivo_t cultivos[MAX_PLANTAS];
    inicializar_cultivos(cultivos, juego);

    for (int i = INIT_INT; i < MAX_PLANTAS; i++) {
        huerta.cultivos[i] = cultivos[i];
    }

    huerta.tope_cultivos = INIT_INT;

    return huerta;
}

/* Inicializar objetos*/
/* 
    Pre:  Recibe un array de objetos (en forma de puntero para modificarlo), el tope de objetos (en forma de puntero 
          para modificarlo), la lista de huertas y las coordenadas del deposito
    Post: Inicializa los objetos:
            - Inicializa el tipo con 'E' (es el tipo de objeto que corresponde a los obstaculos espinas)
*/
void inicializar_objetos(objeto_t objetos[MAX_OBJETOS], int* tope_objetos, huerta_t huerta[MAX_HUERTA], coordenada_t deposito){

    // genera 5 coordenadas aleatorias para las espinas, verifica que no haya nada en esa posicion

    while (*tope_objetos < MAX_ESPINAS) {
        coordenada_t coordenadas_objeto;
        coordenadas_objeto.fila    = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        coordenadas_objeto.columna = random_number(MIN_MOVE_X, MAX_MOVE_X);

        if (posicion_valida_huertas(coordenadas_objeto, huerta) && !posicion_igual(coordenadas_objeto, deposito)) {
            objetos[*tope_objetos].tipo = ESPINA;
            objetos[*tope_objetos].posicion = coordenadas_objeto;

            //printf("Coordenadas de las espinas: %i, %i\n", coordenadas_objeto.fila, coordenadas_objeto.columna); //test
            //printf("Tipo de objeto: %c\n", objetos[*tope_objetos].tipo);      //test

            (*tope_objetos)++;
        }
    }
}

/* Compra de cultivo */
/*
    Pre:  Recibe el tipo de cultivo a comprar
    Post: Devuelve el costo del cultivo en int, en caso de que el cultivo no exista devuelve INIT_INT (0)
*/
int calcular_costo_cultivo(char cultivo){
    int costo_cultivo = INIT_INT;
    switch (cultivo) {
        case TOMATE:
            costo_cultivo = MONEDAS_TOMATE_COMPRA;
            break;
        case ZANAHORIA:
            costo_cultivo = MONEDAS_ZANAHORIA_COMPRA;
            break;
        case BROCOLI:
            costo_cultivo = MONEDAS_BROCOLI_COMPRA;
            break;
        case LECHUGA:
            costo_cultivo = MONEDAS_LECHUGA_COMPRA;
            break;
        default:
            costo_cultivo = INIT_INT;
            break;
    }
    return costo_cultivo;
}

/* 
    Pre:  Recibe un cultivo para chequear si esta ocupado
    Post: Devuelve true si el cultivo esta ocupado, sino devuelve false
*/
bool cultivo_ocupado(cultivo_t cultivo){
    return cultivo.ocupado == CULTIVO_OCUPADO;
}

/*
    Pre:  Recibe la cantidad de monedas del jugador y el costo del cultivo
    Post: Devuelve true si el jugador tiene las monedas suficientes para comprar el cultivo, sino devuelve false
*/
bool monedas_suficientes(int cant_monedas, int costo_cultivo){
    return cant_monedas >= costo_cultivo;
}

/*
    Pre:  Recibe el juego (en forma de puntero a para modificarlo) y el tipo de cultivo a comprar
    Post: Si el cultivo no esta ocupado, el jugador tiene las monedas suficientes para comprarlo y el cultivo
          existe, compra el cultivo, transforma el cultivo en ese tipo y resta el costo del mismo a las monedas 
          del jugador
*/
void comprar_cultivo(juego_t* juego, char cultivo){

    int costo_cultivo = calcular_costo_cultivo(cultivo);

    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        for (int j = INIT_INT; j < MAX_PLANTAS; j++) {

            if (posicion_igual(juego->jugador.posicion, juego->huertas[i].cultivos[j].posicion)) {
                if (!cultivo_ocupado(juego->huertas[i].cultivos[j])) {
                    if (monedas_suficientes(juego->jugador.cant_monedas, costo_cultivo)){

                        juego->jugador.cant_monedas -= costo_cultivo;

                        juego->huertas[i].cultivos[j].tipo = cultivo;
                        juego->huertas[i].cultivos[j].ocupado = CULTIVO_OCUPADO;
                        juego->huertas[i].cultivos[j].movimiento_plantado = INIT_CONTADOR_CULTIVOS;

                   }  
                } 
            }
        } 
    }
}