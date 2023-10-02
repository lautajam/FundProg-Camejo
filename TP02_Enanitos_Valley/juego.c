#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "granja.h"
#include "calculo_enanito.h"

static const char INIT_CHAR = ' ';
const int PERDIDO = -1;
const int GANADO = 1;

int main(void) {

    juego_t juego;
    char inicial_enanito = INIT_CHAR;
    char accion = INIT_CHAR;

    system("clear");


    printf("\nBienvenido al juego Enanito Valley\n");
    printf("Este es un juego sobre ayudar a blanca nieves a cultivar verduras\n");
    printf("Para comenzar, vamos a hacerte un test.\n");

    calcular_enanito(&inicial_enanito);

    inicializar_juego(&juego, inicial_enanito);

    imprimir_terreno(juego);

    while (estado_juego(juego) != PERDIDO && estado_juego(juego) != GANADO) {

        scanf("%c", &accion);
        system("clear");

        realizar_jugada(&juego, accion);

        imprimir_terreno(juego);
        printf(" Movimientos: %d\n", juego.movimientos);


    }
    
    if (estado_juego(juego) == PERDIDO) {
        printf("\n ¡Perdiste! ¡Suerte para la próxima!\n");
    } else {
        printf("\n ¡Ganaste! ¡Felicitaciones!\n");
    }
    return 0;
}
