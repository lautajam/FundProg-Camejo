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

/*
    Pre:  Recibe dos valores, un valor mínimo y un valor máximo para el rango
    Post: Devuelve un número aleatorio dentro del rango
*/
int random_number(int min, int max) {
    int numero = rand() % max + min;
    return numero;
}

/* 
    Pre: Recibe la inicial del enanito conseguida en el test
    Post: Devuelve la cantidad de monedas iniciales del personaje dependiendo de la inicial del enanito
            Gruñoon:  150 monedas
            Dormilon: 200 monedas
            Sabio:    250 monedas
            Feliz:    300 monedas
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
    Pre: recibe dos coordenadas para comparar
    Post: devuelve true si las coordenadas son iguales, sino devuelve false
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

/* Inicializar personaje*/
void coordenadas_iniciales_personaje(coordenada_t coordenadas_personaje, coordenada_t coordenadas_deposito, huerta_t huerta[MAX_HUERTA]){
    do{
        coordenadas_personaje.fila    = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        coordenadas_personaje.columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
    } while (!posicion_valida_huertas(coordenadas_personaje, huerta) && !posicion_igual(coordenadas_personaje, coordenadas_deposito));
}

/* Mejorar comentario
    Pre: Recibe un puntero a personaje_t
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa,
          y con los valores iniciales de los atributos
*/
void inicializar_personaje(personaje_t* personaje, char enanito, huerta_t huerta[MAX_HUERTA], coordenada_t deposito){

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

/* Inicializar deposito*/
/* 
    Pre:  Recibe las coordenadas del deposito (en forma de puntero para modificarlas) y la lista de huertas
    Post: Inicializa el deposito con una posicion aleatoria dentro del mapa
          y chequea que las coordenadas del deposito no coincidan con las de algun cultivo,
          en caso que coincidan, vuelve a generar la coordenadas
*/
void inicializar_deposito(coordenada_t* deposito, huerta_t huerta[MAX_HUERTA]){
    do{
        deposito->fila = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        deposito->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
    } while (!posicion_valida_huertas(*deposito, huerta));
}

/* Inicializar huertas y cultivos*/
/* Mejorar comentario
    Pre: Recibe unas coordenadas de un cultivo y un deposito
    Post: Setea las cooredenas del cultivo con valores aleatorios dentro del mapa
            cuando estos no coinciden con las del deposito
*/
void coordenadas_cultivo(coordenada_t* coordenadas_cultivo, coordenada_t posicion_deposito){
    coordenadas_cultivo->fila    = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
    coordenadas_cultivo->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
}

/* Mejorar comentario
    Pre: Recibe un puntero a un cultivo_t
    Post: Inicializa el cultivo con los valores iniciales de los atributos 
*/
void inicializar_cultivos(cultivo_t cultivos[MAX_PLANTAS], coordenada_t posicion_deposito){

    coordenada_t coordenadas_cultivo_medio;

    int delta_columnas[] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
    int delta_filas[]    = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
 
    for (int  j = INIT_INT; j < MAX_PLANTAS; j++) { // Genera 3 "semillaS" (coordenadas iniciales del cultivo)

        coordenadas_cultivo(&coordenadas_cultivo_medio, posicion_deposito);

        for (int i = INIT_INT; i < MAX_PLANTAS; i++) { // Genera 8 cultivos alrededor de la semilla
            cultivos[i].movimiento_plantado = INIT_MOV_PLAGADO;
            cultivos[i].tipo                = CULTIVO_VACIO;
            cultivos[i].ocupado             = INIT_CULTIVO_OCUPADO;

            cultivos[i].posicion.columna = coordenadas_cultivo_medio.columna + delta_columnas[i];
            cultivos[i].posicion.fila    = coordenadas_cultivo_medio.fila    + delta_filas[i];
        }
    }
    
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

/* Compra de cultivo */
/*
    Pre: recibe el tipo de cultivo a comprar
    Post: devuelve el costo del cultivo en int, en caso de que el cultivo no exista devuelve INIT_INT (0)
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

/* 
    Pre: recibe un cultivo para chequear si esta ocupado
    Post: devuelve true si el cultivo esta ocupado, sino devuelve false
*/
bool cultivo_ocupado(cultivo_t cultivo){
    return cultivo.ocupado == CULTIVO_OCUPADO;
}

/*
    Pre: recibe la cantidad de monedas del jugador y el costo del cultivo
    Post: devuelve true si el jugador tiene las monedas suficientes para comprar el cultivo, sino devuelve false
*/
bool monedas_suficientes(int cant_monedas, int costo_cultivo){
    return cant_monedas >= costo_cultivo;
}

/*
    Pre: recibe el juego (puntero a juego_t) y el tipo de cultivo a comprar
    Post: compra el cultivo, transforma el cultivo en ese tipo y resta el costo del mismo a las monedas del jugador
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
                    }  
                } 
            }
        } 
    }
}