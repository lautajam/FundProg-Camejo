#include <stdio.h>
#include <stdlib.h> // Para usar rand
#include <stdbool.h>
#include "granja.h"
#include "manejo_juego.h"

/*
 * Inicializará el juego, cargando toda la información inicial de las huertas, los obstáculos, las
    herramientas y el personaje.
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