#include <stdio.h>
#include <stdlib.h>
#include "granja.h"
#include "calculo_enanito.h"

static const char INIT_CHAR = ' ';

int main(void) {

    juego_t juego;

    system("clear");

    char inicial_enanito = INIT_CHAR;

    printf("Bienvenido al juego Enanito Valley\n");
    printf("Este es un juego sobre ayudar a blanca nieves a cultivar verduras\n");
    printf("Para comenzar, vamos a hacerte un test.\n");

    calcular_enanito(&inicial_enanito);

    inicializar_juego(&juego, inicial_enanito);

    printf("Juego inicializado\n");
    printf("Posicion iniicial pj %d %d\n", juego.jugador.posicion.fila, juego.jugador.posicion.columna);

    return 0;
}
