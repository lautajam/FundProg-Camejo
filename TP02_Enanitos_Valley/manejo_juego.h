#ifndef MANEJO_JUEGO_H
#define MANEJO_JUEGO_H

#include "granja.h"

/* Mejorar comentario
    Pre: Recibe un puntero a personaje_t
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa,
          y con los valores iniciales de los atributos
*/
void inicializar_personaje(personaje_t* personaje, char enanito);

/* Mejorar comentario
    Pre:  Recibe un puntero a un deposito
    Post: Inicializa el deposito con una posicion aleatoria dentro del mapa
*/
void inicializar_deposito(coordenada_t* deposito, coordenada_t posicion_personaje);

/* Mejorar comentario
  Pre: Recibe un puntero a huerta_t
  Post: Inicializa la huerta con los valores iniciales de los atributos
*/
huerta_t inicializar_huerta(coordenada_t posicion_deposito);

#endif /* MANEJO_JUEGO_H */