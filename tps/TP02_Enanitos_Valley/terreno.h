#ifndef _TERRENO_H_
#define _TERRENO_H_

#include "granja.h"

#define TAMAÑO_TERRENO 20

/*
    Pre: recibe una matriz (terreno de juego) de tamaño (TAMAÑO_TERRENO x TAMAÑO_TERRENO)
    Post: carga el terreno con los objetos del juego: el jugador y el deposito, el resto lo deja vacio
*/
void cargar_terreno(char terreno[TAMAÑO_TERRENO][TAMAÑO_TERRENO], juego_t juego);// Metodo de prueba

/*
    Pre: recibe el juego de donde va a extraer la información
    Post: devuelve la interfaz del juego por pantalla, con los datos
            de la canasta, los movimientos, las monedas, los insecticidas
            y los fertilizantes
            Las letras corresponden a las acciones que puede realizar el jugador
            Y los precios de los cultivos con las letras correspondientes
*/
void imprimir_interfaz(juego_t juego);

#endif /* _TERRENO_H_ */