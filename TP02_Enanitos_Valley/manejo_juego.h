#ifndef MANEJO_JUEGO_H
#define MANEJO_JUEGO_H

#include "granja.h"

// Tamaño del mapa
#define MAP_SIZE 20

// Letras de los cultivos
#define TOMATE    't'
#define ZANAHORIA 'z'
#define BROCOLI   'b'
#define LECHUGA   'l'

// Margenes de movimiento del personaje
static const int MIN_MOVE_X = 0;
static const int MAX_MOVE_X = MAP_SIZE - 1;
static const int MIN_MOVE_Y = 0;
static const int MAX_MOVE_Y = MAP_SIZE - 1;


/* Mejorar comentario
    Pre: Recibe un puntero a personaje_t
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa,
          y con los valores iniciales de los atributos
*/
void inicializar_personaje(personaje_t* personaje, char enanito, huerta_t huerta[MAX_HUERTA], coordenada_t posicion_deposito);

/* Mejorar comentario
    Pre:  Recibe un puntero a un deposito
    Post: Inicializa el deposito con una posicion aleatoria dentro del mapa
*/
void inicializar_deposito(coordenada_t* deposito, huerta_t huerta[MAX_HUERTA]);

/* Mejorar comentario
  Pre: Recibe un puntero a huerta_t
  Post: Inicializa la huerta con los valores iniciales de los atributos
*/
huerta_t inicializar_huerta(coordenada_t posicion_deposito);

/* Mejorar comentario
    Pre: recibe el juego (puntero a juego_t) y el tipo de cultivo a comprar
    Post: compra el cultivo, transforma el cultivo en ese tipo y resta el costo del mismo a las monedas del jugador
*/
void comprar_cultivo(juego_t* juego, char cultivo);

#endif /* MANEJO_JUEGO_H */