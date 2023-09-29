#include <stdio.h>
#include <stdlib.h> // Para usar rand
#include <stdbool.h>
#include "granja.h"
#include "manejo_juego.h"

//static const int  INIT_INT     = 0;
//static const char INIT_OBJETOS = ' ';

/*
 * Inicializará el juego, cargando toda la información inicial de las huertas, los obstáculos, las
    herramientas y el personaje.
 * El enanito corresponde al enanito obtenido en el TP1.
 */
void inicializar_juego(juego_t* juego, char enanito) {

    /* Data de juego_t
    typedef struct juego {
    personaje_t jugador; V
    int movimientos; V
    objeto_t objetos[MAX_OBJETOS]; V
    int tope_objetos; V
    huerta_t huertas[MAX_HUERTA]; V
    coordenada_t deposito;
    } juego_t;
    */

    personaje_t personaje;
    inicializar_personaje(&personaje, enanito);
    juego->jugador = personaje;

    coordenada_t deposito;
    inicializar_deposito(&deposito);
    juego->deposito = deposito;

    /* ESTO ESTÁ MAL
    int movimientos = INIT_INT;
    objeto_t objetos[MAX_OBJETOS];
    inicializar_objetos(objetos);
    for (int i = INIT_INT; i < MAX_OBJETOS; i++) {
        juego->objetos[i] = objetos[i];
    }

    int tope_objetos = INIT_INT;

    huerta_t huertas[MAX_HUERTA];
    inicializar_huertas(huertas);    
    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        juego->huertas[i] = huertas[i];
    } */

}