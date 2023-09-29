#ifndef __GRANJA_H__
#define __GRANJA_H__

#include <stdbool.h>

#define MAX_CANASTA 10
#define MAX_OBJETOS 100
#define MAX_HUERTA 3
#define MAX_PLANTAS 9

typedef struct coordenada {
    int fila;
    int columna;
} coordenada_t;

typedef struct cultivo {
    int movimiento_plantado;
    coordenada_t posicion;
    char tipo;
    bool ocupado;
} cultivo_t;

typedef struct huerta {
    int movimientos_plagado;
    bool plagado;
    cultivo_t cultivos[MAX_PLANTAS];
    int tope_cultivos;
} huerta_t;

typedef struct objeto {
    coordenada_t posicion;
    char tipo;
} objeto_t;

typedef struct personaje {
    coordenada_t posicion;
    bool tiene_fertilizante;
    int cant_insecticidas;
    int cant_monedas;
    char canasta[MAX_CANASTA];
    int tope_canasta;
} personaje_t;

typedef struct juego {
    int movimientos;
    objeto_t objetos[MAX_OBJETOS];
    int tope_objetos;

    huerta_t huertas[MAX_HUERTA];

    coordenada_t deposito;

    personaje_t jugador;
} juego_t;

/*
 * Inicializará el juego, cargando toda la información inicial de las huertas, los obstáculos, las herramientas y el personaje.
 * El enanito corresponde al enanito obtenido en el TP1.
 */
void inicializar_juego(juego_t* juego, char enanito);

/*
 * Realizará la acción recibida por parámetro. Puede ser un movimiento, con todas sus consecuencias, o sembrar, poner insecticida o fertilizante.
 * La acción recibida deberá ser válida.
 */
void realizar_jugada(juego_t* juego, char accion);

/*
 * Imprime el juego por pantalla
 */
void imprimir_terreno(juego_t juego);

/*
 * El juego se dará por ganado si se llega a 1000 monedas. Si Blancanieves se queda 
 * sin monedas, se considerará perdido.
 * Devuelve:
 * --> 1 si es ganado
 * --> -1 si es perdido
 * --> 0 si se sigue jugando
 */
int estado_juego(juego_t juego);

#endif /* __GRANJA_H__ */