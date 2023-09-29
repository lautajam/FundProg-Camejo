#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> // Para usar rand
#include <stdbool.h>
#include "granja.h"

#define MAP_SIZE 20

const int MIN_MOVE_X = 0;
const int MAX_MOVE_X = MAP_SIZE - 1;
const int MIN_MOVE_Y = 0;
const int MAX_MOVE_Y = MAP_SIZE - 1;

// Funciones extras
/* V
    Pre: min and max are valid int
    Post: returns a random int between min and max
*/
int random_number(int min, int max) {
    int numero = rand() % (max - min + 1) + min;
    return numero;
}

// Funciones manejo juego
/* V
    Pre: Recibe un puntero a coordenada_t
    Post: Devuelve una coordenada aleatoria dentro del mapa
*/
void elegir_coordenada_inicial_personaje(coordenada_t* coordenadas_iniciales_personaje){
    coordenadas_iniciales_personaje->fila = random_number(0, MAX_MOVE_Y);
    coordenadas_iniciales_personaje->columna = random_number(0, MAX_MOVE_X);
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
    int cant_monedas;
    char canasta[MAX_CANASTA];
    int tope_canasta;
    } personaje_t;
    */
    coordenada_t coordenadas_iniciales_personaje;
    elegir_coordenada_inicial_personaje(&coordenadas_iniciales_personaje);
    personaje->posicion = coordenadas_iniciales_personaje;

    personaje->tiene_fertilizante = false;

    personaje->cant_insecticidas = 0;
}

// Funciones manejo juego
/*
 * Inicializará el juego, cargando toda la información inicial de las huertas, los obstáculos, las herramientas y el personaje.
 * El enanito corresponde al enanito obtenido en el TP1.
 */
void inicializar_juego(juego_t* juego, char enanito) {

    /* Data de juego_t
    typedef struct juego {
    personaje_t jugador;
    int movimientos;
    objeto_t objetos[MAX_OBJETOS];
    int tope_objetos;
    huerta_t huertas[MAX_HUERTA];
    coordenada_t deposito;
    } juego_t;
    */

    personaje_t personaje;
    inicializar_personaje(&personaje, enanito);
    juego->jugador = personaje;

}