#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h> // Para usar rand
#include <time.h> // Para obtener una semilla desde el reloj
#include "manejo_juego.h"

#define GRUÑON 'G'
#define FELIZ 'F'
#define DORMILON 'D'
#define SABIO 'S'

#define MAP_SIZE 20

const int MIN_MOVE_X = 0;
const int MAX_MOVE_X = MAP_SIZE - 1;
const int MIN_MOVE_Y = 0;
const int MAX_MOVE_Y = MAP_SIZE - 1;

static const int  INIT_INT     = 0;
//static const char INIT_CHAR    = ' ';
const char        INIT_CANASTA = ' ';

const int MONEDAS_GRUÑON   = 150;
const int MONEDAS_DORMILON = 200;
const int MONEDAS_SABIO    = 250;
const int MONEDAS_FELIZ    = 300;

const int INIT_INSECTICIDAS = 0;
const int INIT_FERTILIZANTE = false;

// Funciones extras
/*
    Pre: min and max are valid int
    Post: returns a random int between min and max
*/
int random_number(int min, int max) {
    int numero = rand() % max + min; // la amplitud del rango es 20 y el valor mínimo es 10.
    return numero;
}

// Funciones manejo juego
/*
    Pre: Recibe un puntero a coordenada_t
    Post: Devuelve una coordenada aleatoria dentro del mapa
*/
void elegir_coordenada_inicial_personaje(coordenada_t* coordenadas_iniciales_personaje){
    srand ((unsigned)time(NULL));
    coordenadas_iniciales_personaje->fila = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
    coordenadas_iniciales_personaje->columna = random_number(MIN_MOVE_X, MAX_MOVE_X);
}

/*
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

/*
    Pre: Recibe un puntero a char canasta
    Post: Inicializa la canasta con el valor inicial de INIT_CANASTA
*/
void inicializar_canasta(char canasta[MAX_CANASTA]){
    for (int i = 0; i < MAX_CANASTA; i++){
        canasta[i] = INIT_CANASTA;
    }
}

/*
    Pre: Recibe un puntero a personaje_t
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa,
          y con los valores iniciales de los atributos
*/
void inicializar_personaje(personaje_t* personaje, char enanito){

    /*
    typedef struct personaje {
    coordenada_t posicion; V
    bool tiene_fertilizante; V
    int cant_insecticidas; V
    int cant_monedas; v
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
        personaje->canasta[i] = ' ';
    }

    personaje->tope_canasta = INIT_INT;
}