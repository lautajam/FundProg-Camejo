#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "granja.h"
#include "calculo_enanito.h"

static const char INIT_CHAR = ' ';
const int PERDIDO = -1;
const int GANADO  = 1;

int main(void) {

    juego_t juego;
    // char inicial_enanito = INIT_CHAR; // Para el test
    
    char inicial_enanito = 'G';          // Para el test

    char accion = INIT_CHAR;

    system("clear");
 
    //printf("\nBienvenido al juego Enanito Valley\n");                                 // Para el test
    //printf("Este es un juego sobre ayudar a blanca nieves a cultivar verduras\n");    // Para el test
    //printf("Para comenzar, vamos a hacerte un test.\n");                              // Para el test

    //calcular_enanito(&inicial_enanito); // Para el test

    inicializar_juego(&juego, inicial_enanito);

    while (estado_juego(juego) != PERDIDO && estado_juego(juego) != GANADO) {

        imprimir_terreno(juego);

        scanf("%c", &accion);
        printf("\n");

        system("clear");
        
        realizar_jugada(&juego, accion);
    }
    
    if (estado_juego(juego) == PERDIDO) {
        printf("\n ¡Perdiste! ¡Suerte para la próxima!\n");
    } else {
        printf("\n ¡Ganaste! ¡Felicitaciones!\n");
   }

    return 0;
}
