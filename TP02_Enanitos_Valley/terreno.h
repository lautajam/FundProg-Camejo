#ifndef _TERRENO_H_
#define _TERRENO_H_

#include "granja.h"

#define TAMAÑO_TERRENO 20

/*
    Pre: recibe una matriz (terreno de juego) de tamaño (TAMAÑO_TERRENO x TAMAÑO_TERRENO)
    Post: carga el terreno con los objetos del juego: el jugador y el deposito, el resto lo deja vacio
*/
void cargar_terreno(char terreno[TAMAÑO_TERRENO][TAMAÑO_TERRENO], juego_t juego);

#endif /* _TERRENO_H_ */