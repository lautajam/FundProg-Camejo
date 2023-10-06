#include <stdbool.h>
#include <stdio.h>
#include "terreno.h"

// Estilos de los objetos
const char ESPACIOS_VACIOS    = '-';
const char ESTILO_JUGADOR     = 'S';
const char ESTILO_DEPOSITO    = 'D';
static const char ESPINA      = 'E';

// Constantes de inicializacion
static const int INI_INT      = 0;

/*
    Pre: recibe una matriz (terreno de juego) de tamaño (TAMAÑO_TERRENO x TAMAÑO_TERRENO)
    Post: inicializa el terreno con espacios vacios
*/
void inicializar_terreno(char terreno[TAMAÑO_TERRENO][TAMAÑO_TERRENO]) {
    for (int i = 0; i < TAMAÑO_TERRENO; i++) {
        for (int j = 0; j < TAMAÑO_TERRENO; j++) {
            terreno[i][j] = ESPACIOS_VACIOS;
        }
    }
}

/*
    Pre:  recibe un cultivo
    Post: devuelve true si el cultivo esta fuera del rango del terreno
*/
bool cultivo_fuera_de_rango(coordenada_t posicion_cultivo) {
    return (posicion_cultivo.fila < INI_INT || posicion_cultivo.fila >= TAMAÑO_TERRENO || 
            posicion_cultivo.columna < INI_INT || posicion_cultivo.columna >= TAMAÑO_TERRENO);
}

/*
    Pre:  recibe una matriz (terreno de juego) de tamaño (TAMAÑO_TERRENO x TAMAÑO_TERRENO)
    Post: carga el terreno con los cultivos del juego
*/
void cargar_huertas(char terreno[TAMAÑO_TERRENO][TAMAÑO_TERRENO], juego_t juego) {
    for (int i = INI_INT; i < MAX_HUERTA; i++) {
        for (int j = INI_INT; j < MAX_PLANTAS; j++) {

            coordenada_t posicion_cultivo = juego.huertas[i].cultivos[j].posicion;

            if (cultivo_fuera_de_rango(posicion_cultivo)) {

            } else {
                terreno[posicion_cultivo.fila][posicion_cultivo.columna] = juego.huertas[i].cultivos[j].tipo;
            }
        }
    }
}


/*
    Pre: recibe una matriz (terreno de juego) de tamaño (TAMAÑO_TERRENO x TAMAÑO_TERRENO)
    Post: carga el terreno con los objetos del juego: el jugador y el deposito, el resto lo deja vacio
*/
void cargar_terreno(char terreno[TAMAÑO_TERRENO][TAMAÑO_TERRENO], juego_t juego){

    inicializar_terreno(terreno);

    terreno[juego.deposito.fila][juego.deposito.columna] = ESTILO_DEPOSITO; //cargar deposito

    cargar_huertas(terreno, juego);

    for (int i = INI_INT; i < juego.tope_objetos; i++) {
        if (juego.objetos[i].tipo == ESPINA) {
            terreno[juego.objetos[i].posicion.fila][juego.objetos[i].posicion.columna] = ESPINA;
        }
    }

    terreno[juego.jugador.posicion.fila][juego.jugador.posicion.columna] = ESTILO_JUGADOR;   //cargar jugador
}