#include <stdio.h>
#include <stdbool.h>
#include <time.h>   // Para obtener una semilla desde el reloj
#include <stdlib.h> // Para usar rand
#include "manejo_juego.h"
#include "granja.h"

// Tamaño del mapa
#define TAMAÑO_TERRENO 20

// Letras de los enanitos
#define GRUÑON   'G'
#define FELIZ    'F'
#define DORMILON 'D'
#define SABIO    'S'

// Valores iniciales de los atributos
static const int  INIT_INT         = 0;
const int         INIT_MOV_PLAGADO = 10;
const int  INIT_INSECTICIDAS       = 0;
const int  INIT_OBJETO             = 0;
const int  MONEDAS_DEFAULT         = 0;
const char INIT_CANASTA            = ' ';
const char CULTIVO_VACIO           = 'C';
const int  INIT_FERTILIZANTE       = false;
const bool INIT_CULTIVO_OCUPADO    = false;
const bool INIT_PLAGADO            = false;

// Valores de las monedas de cada enanito
const int MONEDAS_GRUÑON   = 150;
const int MONEDAS_DORMILON = 200;
const int MONEDAS_SABIO    = 250;
const int MONEDAS_FELIZ    = 300;

// Valores de las monedas por cada cultivo
const int MONEDAS_TOMATE    = 5;
const int MONEDAS_ZANAHORIA = 10;
const int MONEDAS_BROCOLI   = 15;
const int MONEDAS_LECHUGA   = 20;

const bool CULTIVO_OCUPADO    = true;
const bool CULTIVO_DESOCUPADO = false;
const bool CENTRO_CULTIVO_NO_GENERADO     = false;
const bool CENTRO_CULTIVO_GENERADO        = true;

/* Mejorar comentario y traducir español
    Pre: min and max are valid int
    Post: returns a random int between min and max
*/
int random_number(int min, int max) {
    int numero = rand() % max + min; // la amplitud del rango es max y el valor mínimo es min
    return numero;
}

/* Mejorar comentario
    Pre: Recibe un char enanito
    Post: Devuelve la cantidad de monedas iniciales del personaje
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

/* Mejorar comentario
    Pre: Recibe un puntero a personaje_t
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa,
          y con los valores iniciales de los atributos
*/
void inicializar_personaje(personaje_t* personaje, char enanito){

    coordenada_t coordenadas_iniciales_personaje;
    coordenadas_iniciales_personaje.fila = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
    coordenadas_iniciales_personaje.columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
    personaje->posicion = coordenadas_iniciales_personaje;

    personaje->tiene_fertilizante = INIT_FERTILIZANTE;

    personaje->cant_insecticidas = INIT_INSECTICIDAS;

    personaje->cant_monedas = calcular_monedas_iniciales(enanito);

    for (int i = 0; i < MAX_CANASTA; i++) {
        personaje->canasta[i] = INIT_CANASTA;
    }

    personaje->tope_canasta = INIT_INT;
}

/* Mejorar comentario
    Pre:  Recibe un puntero a un deposito
    Post: Inicializa el deposito con una posicion aleatoria dentro del mapa
*/
void inicializar_deposito(coordenada_t* deposito, coordenada_t posicion_personaje){
    do{
        deposito->fila = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        deposito->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
    } while (deposito->fila == posicion_personaje.fila && deposito->columna == posicion_personaje.columna);
}

/* Mejorar comentario
    Pre: Recibe unas coordenadas de un cultivo y un deposito
    Post: Setea las cooredenas del cultivo con valores aleatorios dentro del mapa
            cuando estos no coinciden con las del deposito
*/
void coordenadas_cultivo(coordenada_t* coordenadas_cultivo, coordenada_t posicion_deposito){
    do{
        coordenadas_cultivo->fila    = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        coordenadas_cultivo->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
    } while (coordenadas_cultivo->fila == posicion_deposito.fila && coordenadas_cultivo->columna == posicion_deposito.columna);
}

/* Mejorar comentario
    Pre: Recibe un puntero a un cultivo_t
    Post: Inicializa el cultivo con los valores iniciales de los atributos 
*/
void inicializar_cultivos(cultivo_t cultivos[MAX_PLANTAS], coordenada_t posicion_deposito){
    /*
    typedef struct cultivo {
        int movimiento_plantado;
        coordenada_t posicion;
        char tipo;
        bool ocupado;
    } cultivo_t;

    */
    for (int i = INIT_INT; i < MAX_PLANTAS; i++) {
        cultivos[i].movimiento_plantado = INIT_MOV_PLAGADO;
        cultivos[i].tipo                = CULTIVO_VACIO;
        cultivos[i].ocupado             = INIT_CULTIVO_OCUPADO;

        coordenada_t coordenadas_cultivo_medio;
        coordenadas_cultivo(&coordenadas_cultivo_medio, posicion_deposito);

        int delta_filas[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int delta_columnas[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        for (int j = 0; j < MAX_PLANTAS; j++) {
            cultivos[i].posicion.fila = coordenadas_cultivo_medio.fila + delta_filas[j];
            cultivos[i].posicion.columna = coordenadas_cultivo_medio.columna + delta_columnas[j];        

        }
    }
    
/*
    cultivo_t cultivo;

    cultivo.movimiento_plantado = INIT_MOV_PLAGADO;

    coordenada_t coordenadas_cultivo_medio;
    coordenadas_cultivo(&coordenadas_cultivo_medio, posicion_deposito);

    int delta_filas[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int delta_columnas[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    for (int i = 0; i < MAX_PLANTAS; i++) {
        cultivo.posicion.fila = coordenadas_cultivo_medio.fila + delta_filas[i];
        cultivo.posicion.columna = coordenadas_cultivo_medio.columna + delta_columnas[i];        

    }

    cultivo.tipo     = CULTIVO_VACIO;

    cultivo.ocupado  = INIT_CULTIVO_OCUPADO;

    return cultivo;*/
}

/* Mejorar comentario
  Pre: Recibe un puntero a huerta_t
  Post: Inicializa la huerta con los valores iniciales de los atributos
*/
huerta_t inicializar_huerta(coordenada_t posicion_deposito){

    huerta_t huerta;

    huerta.movimientos_plagado = INIT_MOV_PLAGADO;
    huerta.plagado             = INIT_PLAGADO;
    
    cultivo_t cultivos[MAX_PLANTAS];
    inicializar_cultivos(cultivos, posicion_deposito);

    for (int i = INIT_INT; i < MAX_PLANTAS; i++) {
        huerta.cultivos[i] = cultivos[i];
    }

    huerta.tope_cultivos = INIT_INT;

    return huerta;
}

/* Mejorar comentario
    Pre: recibe el tipo de cultivo a comprar
    Post: devuelve el costo del cultivo en int
*/
int calcular_costo_cultivo(char cultivo){
    int costo_cultivo = INIT_INT;
    switch (cultivo) {
        case TOMATE:
            costo_cultivo = MONEDAS_TOMATE;
            break;
        case ZANAHORIA:
            costo_cultivo = MONEDAS_ZANAHORIA;
            break;
        case BROCOLI:
            costo_cultivo = MONEDAS_BROCOLI;
            break;
        case LECHUGA:
            costo_cultivo = MONEDAS_LECHUGA;
            break;
        default:
            costo_cultivo = INIT_INT;
            break;
    }
    return costo_cultivo;
}

/* Mejorar comentario
    Pre: recibe el juego (puntero a juego_t) y el tipo de cultivo a comprar
    Post: compra el cultivo, transforma el cultivo en ese tipo y resta el costo del mismo a las monedas del jugador
*/
void comprar_cultivo(juego_t* juego, char cultivo){
    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        for (int j = INIT_INT; j < MAX_PLANTAS; j++) {
            if (juego->jugador.posicion.fila == juego->huertas[i].cultivos[j].posicion.fila && 
                juego->jugador.posicion.columna == juego->huertas[i].cultivos[j].posicion.columna) {
                if (juego->huertas[i].cultivos[j].ocupado == CULTIVO_DESOCUPADO) {
                    if (juego->jugador.cant_monedas >= calcular_costo_cultivo(cultivo)){
                        juego->jugador.cant_monedas -= calcular_costo_cultivo(cultivo);
                        juego->huertas[i].cultivos[j].tipo = cultivo;
                        juego->huertas[i].cultivos[j].ocupado = CULTIVO_OCUPADO;
                    }  
                } 
            }
        } 
    }
}