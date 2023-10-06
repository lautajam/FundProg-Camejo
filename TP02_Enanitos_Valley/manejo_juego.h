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

/*
    Pre: Recibe un personaje (en forma de puntero para modificarlo) la inicial del enanito, la lista de huertas 
         y las coordenadas del deposito
    Post: Inicializa el personaje con una posicion aleatoria dentro del mapa (no pisando el deposito ni los cultivos)
            - Calcula las monedas iniciales del personaje dependiendo de la inicial del enanito
            - Inicia la canasta con valores vacios
            - Inicia los insecticidas con INIT_INSECTICIDAS (es 3, valor pedido por la consigna)
            - Inicia el fertilizante con INIT_FERTILIZANTE (es false, valor pedido por la consigna)
*/
void inicializar_personaje(personaje_t* personaje, char enanito, huerta_t huerta[MAX_HUERTA], coordenada_t posicion_deposito);

/* 
    Pre:  Recibe las coordenadas del deposito (en forma de puntero para modificarlas) y la lista de huertas
    Post: Inicializa el deposito con una posicion aleatoria dentro del mapa y chequea que las coordenadas del 
          deposito no coincidan con las de algun cultivo, en caso que coincidan, vuelve a generar la coordenadas
*/
void inicializar_deposito(coordenada_t* deposito, huerta_t huerta[MAX_HUERTA]);

/* 
  Pre:  Recibe el juego (para leerlo)
  Post: Devuelve una huerta inicializada con los valores pedidos por la consigna
            - Inicializa el movimiento_plantado con INIT_MOV_PLAGADO (es 10, valor pedido por la consigna)
            - Inicializa el tipo con CULTIVO_VACIO (es 'C', valor pedido por la consigna)
            - Inicializa el ocupado con INIT_CULTIVO_OCUPADO (es false, valor pedido por la consigna)
            - Inicializa los cultivos con la funcion inicializar_cultivos()
*/
huerta_t inicializar_huerta(juego_t juego);

/*
    Pre:  Recibe el juego (en forma de puntero a para modificarlo) y el tipo de cultivo a comprar
    Post: Si el cultivo no esta ocupado, el jugador tiene las monedas suficientes para comprarlo y el cultivo
          existe, compra el cultivo, transforma el cultivo en ese tipo y resta el costo del mismo a las monedas 
          del jugador
*/
void comprar_cultivo(juego_t* juego, char cultivo);

#endif /* MANEJO_JUEGO_H */