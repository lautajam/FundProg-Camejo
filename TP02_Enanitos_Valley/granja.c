#include <stdio.h>
#include <stdlib.h> // Para usar rand
#include <time.h>   // Para obtener una semilla desde el reloj
#include <stdbool.h>
#include "granja.h"
#include "manejo_juego.h"

#define MAP_SIZE 20

// Margenes de movimiento del personaje
static const int MIN_MOVE_X = 0;
static const int MAX_MOVE_X = MAP_SIZE - 1;
static const int MIN_MOVE_Y = 0;
static const int MAX_MOVE_Y = MAP_SIZE - 1;

#define ARRIBA    'w'
#define IZQUIERDA 'a'
#define ABAJO     's'
#define DERECHA   'd'

const char ESPACIOS_VACIOS    = '-';
const char ESTILO_JUGADOR     = 'S';
const char ESTILO_DEPOSITO    = 'D';

const bool HUERTA_ENCONTRADA     = true;
const bool HUERTA_NO_ENCONTRADA  = false;

static const int  INIT_INT     = 0;
//static const char INIT_OBJETOS = ' ';

/*
 * Inicializará el juego, cargando toda la información inicial de las huertas, los obstáculos, las
    herramientas y el personaje.
 * El enanito corresponde al enanito obtenido en el TP1.
 */
void inicializar_juego(juego_t* juego, char enanito) {

    srand ((unsigned)time(NULL)); // genera la semilla que luego usará la funcion numero_random()

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

    juego->movimientos = INIT_INT;

    /* hay que revisar todo esto
    objeto_t objetos[MAX_OBJETOS];
    inicializar_objetos(objetos);
    for (int i = INIT_INT; i < MAX_OBJETOS; i++) {
        juego->objetos[i] = objetos[i];
    }

    int tope_objetos = INIT_INT;
    */
   
    huerta_t huertas[MAX_HUERTA];
    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        juego->huertas[i] = inicializar_huerta();
    }

}

/*
 * Realizará la acción recibida por parámetro. Puede ser un movimiento, con todas sus consecuencias, o sembrar, poner 
    insecticida o fertilizante.
 * La acción recibida deberá ser válida.
 */
void realizar_jugada(juego_t* juego, char accion){

    switch (accion)
        {
        case ARRIBA:
            if (juego->jugador.posicion.fila > MIN_MOVE_Y){
                juego->jugador.posicion.fila--;
                juego->movimientos++;
            } break;
        case IZQUIERDA:
            if (juego->jugador.posicion.columna > MIN_MOVE_X){
                juego->jugador.posicion.columna--;
                juego->movimientos++;
            } break;
        case ABAJO:
            if (juego->jugador.posicion.fila < MAX_MOVE_Y){
                juego->jugador.posicion.fila++;
                juego->movimientos++;
            } break;
        case DERECHA:
            if (juego->jugador.posicion.columna < MAX_MOVE_X){
                juego->jugador.posicion.columna++;
                juego->movimientos++;
            } break;
        }
}

/*
 * Imprime el juego por pantalla
 */
void imprimir_terreno(juego_t juego){

    for (int i = 0; i < MAP_SIZE; i++) { // y
        for (int j = 0; j < MAP_SIZE; j++) { // x
            if (i == juego.jugador.posicion.fila && j == juego.jugador.posicion.columna) {
                printf(" %c", ESTILO_JUGADOR);
            } else if (i == juego.deposito.fila && j == juego.deposito.columna) {
                printf(" %c", ESTILO_DEPOSITO);
            } else {
                bool encontro_huerta = HUERTA_NO_ENCONTRADA;
                for (int k = 0; k < MAX_HUERTA; k++) {
                    if (i == juego.huertas[k].cultivos->posicion.fila && j == juego.huertas[k].cultivos->posicion.columna) {
                        printf(" %c", juego.huertas[k].cultivos->tipo);
                        encontro_huerta = HUERTA_ENCONTRADA;
                        k = MAX_HUERTA;
                    }
                }
                if (!encontro_huerta) {
                    printf(" %c", ESPACIOS_VACIOS);
                }
                
            }
        }
        printf("\n");
    }

}

/*
 * El juego se dará por ganado si se llega a 1000 monedas. Si Blancanieves se queda 
 * sin monedas, se considerará perdido.
 * Devuelve:
 * --> 1 si es ganado
 * --> -1 si es perdido
 * --> 0 si se sigue jugando
 */
int estado_juego(juego_t juego){
    if (juego.jugador.cant_monedas <= 0) {
        return -1;
    } else if (juego.jugador.cant_monedas >= 1000) {
        return 1;
    }
    return 0;
}
