#include <stdio.h>
#include <stdbool.h>
#include <time.h> // Para obtener una semilla desde el reloj
#include <stdlib.h> // Para usar rand
#include "manejo_juego.h"
#include "granja.h"

#define GRUÑON 'G'
#define FELIZ 'F'
#define DORMILON 'D'
#define SABIO 'S'

#define MAP_SIZE 20

const int MIN_MOVE_X = 0;
const int MAX_MOVE_X = MAP_SIZE - 1;
const int MIN_MOVE_Y = 0;
const int MAX_MOVE_Y = MAP_SIZE - 1;

static const int  INIT_INT        = 0;
const char        INIT_CANASTA    = ' ';

const int MONEDAS_GRUÑON   = 150;
const int MONEDAS_DORMILON = 200;
const int MONEDAS_SABIO    = 250;
const int MONEDAS_FELIZ    = 300;

const int  INIT_INSECTICIDAS     = 0;
const int  INIT_FERTILIZANTE     = false;
const char CULTIVO_VACIO         = 'C';
const int  INIT_OBEJETO          = 0;
const bool INIT__CULTIVO_OCUPADO = false;

/* Mejorar comentario y traducir español
    Pre: min and max are valid int
    Post: returns a random int between min and max
*/
int random_number(int min, int max) {
    int numero = rand() % max + min; // la amplitud del rango es max y el valor mínimo es min
    return numero;
}

/* Mejorar comentario HAY QUE AGREGAR LAS CONDICIONES DE APARICIÓN
    Pre: Recibe un puntero a coordenada_t
    Post: Devuelve una coordenada aleatoria dentro del mapa
*/
void elegir_coordenada_inicial_personaje(coordenada_t* coordenadas_iniciales_personaje){
    coordenadas_iniciales_personaje->fila = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
    coordenadas_iniciales_personaje->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
}

/* Mejorar comentario
    Pre: Recibe un char enanito
    Post: Devuelve la cantidad de monedas iniciales del personaje
*/
int calcular_monedas_iniciales(char enanito){
    int monedas_iniciales = INIT_INT;
    if (enanito == GRUÑON){
        monedas_iniciales = MONEDAS_GRUÑON;
    } else if (enanito == DORMILON){
        monedas_iniciales = MONEDAS_DORMILON;
    } else if (enanito == SABIO){
        monedas_iniciales = MONEDAS_SABIO;
    } else {
        monedas_iniciales = MONEDAS_FELIZ;
    }
    return monedas_iniciales;
}

/* Mejorar comentario
    Pre: Recibe un puntero a personaje_t
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa,
          y con los valores iniciales de los atributos
*/
void inicializar_personaje(personaje_t* personaje, char enanito){

    /* Data del personaje (personaje_t) BOORAR ANTES DE ENTREGAR *-COMPLETO-*
    typedef struct personaje {
    coordenada_t posicion;
    bool tiene_fertilizante;
    int cant_insecticidas;
    int cant_monedas;
    char canasta[MAX_CANASTA];
    int tope_canasta;
    } personaje_t;
    */

    coordenada_t coordenadas_iniciales_personaje;
    elegir_coordenada_inicial_personaje(&coordenadas_iniciales_personaje);
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
        objeto.tipo             = INIT_OBEJETO;
        objetos[i]              = objeto;
    }
}

//    Mejorar comentario
//    Pre: Recibe un puntero a un cultivo_t
//    Post: Inicializa el cultivo con los valores iniciales de los atributos 

void inicializar_cultivos(cultivo_t cultivos[MAX_PLANTAS]){

    // Data de cultivo_t:
    //  typedef struct cultivo {
    //      int movimiento_plantado;
    //      coordenada_t posicion;
    //      char tipo;
    //      bool ocupado;
    //  } cultivo_t;


    for (int i = 0; i < MAX_PLANTAS; i++) {
        cultivo_t cultivo;
        cultivo.movimiento_plantado = INIT_INT;

        cultivo.posicion.fila    = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        cultivo.posicion.columna = random_number(MIN_MOVE_X, MAX_MOVE_X);

        cultivo.tipo    = CULTIVO_VACIO;
        cultivo.ocupado = INIT__CULTIVO_OCUPADO;
        cultivos[i]     = cultivo;
    }
}

//  Mejorar comentario
//  Pre: Recibe un puntero a huerta_t
//  Post: Inicializa la huerta con los valores iniciales de los atributos

void inicializar_huerta(huerta_t* huerta){

    // Data de huerta_t:
    //  typedef struct huerta {
    //      int movimientos_plagado;
    //      bool plagado;
    //      cultivo_t cultivos[MAX_PLANTAS];
    //      int tope_cultivos;
    //  } huerta_t;

    *huerta.movimientos_plagado = INIT_INT;
    *huerta.plagado = false;
        
        cultivo_t cultivos[MAX_PLANTAS];
        inicializar_cultivos(cultivos);
        
        for (int j = 0; j < MAX_PLANTAS; j++) {
            huerta.cultivos[j] = cultivos[j];
        }

        huerta.tope_cultivos = INIT_INT;
        huertas[i] = huerta;
    }
}
*/