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

    while (estado_juego(juego) != PERDIDO && estado_juego(juego) != GANADO) {

        realizar_jugada(&juego, accion);

        imprimir_terreno(juego);

        printf(" Canasta:");
        for (int i = 0; i < juego.jugador.tope_canasta; i++) {
            printf(" %c ", juego.jugador.canasta[i]);
        }
        printf("\n");

        printf(" Movimientos:  %d | Monedas: %d\n", juego.movimientos, juego.jugador.cant_monedas);
        printf(" Insecticidas: %d | Fertilizantes: %d\n", juego.jugador.cant_insecticidas, 
                                                          juego.jugador.tiene_fertilizante);
        printf(" Tomate  (t):  5 monedas | Zanahoria (z): 10 monedas \n");
        printf(" Brocilo (b): 15 monedas | Lechuga   (l): 20 monedas \n");
        printf(" Accion w/a/s/d (moverse) o t/z/b/l (comprar): ");
        scanf("%c", &accion);
        printf("\n");
        system("clear");
    }
    
    if (estado_juego(juego) == PERDIDO) {
        printf("\n ¡Perdiste! ¡Suerte para la próxima!\n");
    } else {
        printf("\n ¡Ganaste! ¡Felicitaciones!\n");
    }
    return 0;
}
