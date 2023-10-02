#include <stdio.h>
#include <stdbool.h>
#include <time.h> // Para obtener una semilla desde el reloj
#include <stdlib.h> // Para usar rand
#include "manejo_juego.h"
#include "granja.h"

// Letras de los enanitos
#define GRUÑON 'G'
#define FELIZ 'F'
#define DORMILON 'D'
#define SABIO 'S'

// Tamaño del mapa
#define MAP_SIZE 20

// Margenes de movimiento del personaje
static const int MIN_MOVE_X = 0;
static const int MAX_MOVE_X = MAP_SIZE - 1;
static const int MIN_MOVE_Y = 0;
static const int MAX_MOVE_Y = MAP_SIZE - 1;

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

/* Mejorar comentario HAY QUE AGREGAR LAS CONDICIONES DE APARICIÓN
    Pre:  Recibe un puntero a un deposito
    Post: Inicializa el deposito con una posicion aleatoria dentro del mapa
*/
void inicializar_deposito(coordenada_t* deposito){
    deposito->fila = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
    deposito->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
}

/* hay que revisar todo esto

void inicializar_objetos(objeto_t* objetos){

    // Data de objeto_t:
    //  typedef struct objeto {
    //      coordenada_t posicion;
    //      char tipo;
    //  } objeto_t;


    for (int i = 0; i < MAX_OBJETOS; i++) {
        objeto_t objeto;
        objeto.posicion.fila    = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        objeto.posicion.columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
        objeto.tipo             = INIT_OBJETO;
        objetos[i]              = objeto;
    }
}

//    Mejorar comentario
//    Pre: Recibe un puntero a un cultivo_t
//    Post: Inicializa el cultivo con los valores iniciales de los atributos 

cultivo_t inicializar_cultivo(){

    // Data de cultivo_t:
    //  typedef struct cultivo {
    //      int movimiento_plantado;
    //      coordenada_t posicion;
    //      char tipo;
    //      bool ocupado;
    //  } cultivo_t;

    cultivo_t cultivo;

    cultivo.movimiento_plantado = INIT_MOV_PLAGADO;

    coordenada_t coordenadas_iniciales_cultivo;
    coordenadas_iniciales_cultivo.fila    = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
    coordenadas_iniciales_cultivo.columna = random_number(MIN_MOVE_X, MAX_MOVE_X);

    cultivo.posicion = coordenadas_iniciales_cultivo;

    cultivo.tipo     = CULTIVO_VACIO;

    cultivo.ocupado  = INIT_CULTIVO_OCUPADO;

    return cultivo;
}

//  Mejorar comentario
//  Pre: Recibe un puntero a huerta_t
//  Post: Inicializa la huerta con los valores iniciales de los atributos

huerta_t inicializar_huerta(){

    // Data de huerta_t:
    //  typedef struct huerta {
    //      int movimientos_plagado;
    //      bool plagado;
    //      cultivo_t cultivos[MAX_PLANTAS];
    //      int tope_cultivos;
    //  } huerta_t;

        huerta_t huerta;

        huerta.movimientos_plagado = INIT_MOV_PLAGADO;
        huerta.plagado             = INIT_PLAGADO;


        cultivo_t cultivos[MAX_PLANTAS];
        
        for (int i = 0; i < MAX_PLANTAS; i++) {
            cultivos[i] = inicializar_cultivo();
        }

        huerta.tope_cultivos = INIT_INT;

        return huerta;
}
*/