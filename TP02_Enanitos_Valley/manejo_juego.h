#ifndef MANEJO_JUEGO_H
#define MANEJO_JUEGO_H

#include "granja.h"

/* V
    Pre: Recibe un puntero a coordenada_t
    Post: Devuelve una coordenada aleatoria dentro del mapa
*/
void elegir_coordenada_inicial_personaje(coordenada_t* coordenadas_iniciales_personaje);

/* V
    Pre: Recibe un puntero a personaje_t
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa,
          y con los valores iniciales de los atributos
*/
void inicializar_personaje(personaje_t* personaje, char enanito);

/* V
    Pre: Recibe un puntero a un deposito
    Post: Inicializa el deposito con una posicion aleatoria dentro del mapa
*/
void inicializar_deposito(coordenada_t* deposito);


/* hay que revisar todo esto
//  Pre: Recibe un puntero a objeto_t
// Post: Inicializa los objetos con una posicion aleatoria dentro del mapa

void inicializar_objetos(objeto_t* objetos);

//  Pre: Recibe un puntero a huerta_t
//  Post: Inicializa las huertas con una posicion aleatoria dentro del mapa

void inicializar_huertas(huerta_t* huertas);
*/

#endif /* MANEJO_JUEGO_H */