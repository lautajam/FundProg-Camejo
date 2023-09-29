#ifndef MANEJO_JUEGO_H
#define MANEJO_JUEGO_H

#include "granja.h"

/* V
    Pre: Recibe un puntero a coordenada_t
    Post: Devuelve una coordenada aleatoria dentro del mapa
*/
void elegir_coordenada_inicial_personaje(coordenada_t* coordenadas_iniciales_personaje);

/*
    Pre: Recibe un puntero a personaje_t
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa,
          y con los valores iniciales de los atributos
*/
void inicializar_personaje(personaje_t* personaje, char enanito);

#endif /* MANEJO_JUEGO_H */