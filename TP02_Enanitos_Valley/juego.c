#include <stdio.h>
#include <stdlib.h>
#include "granja.h"
#include "calculo_enanito.h"

static const char INIT_CHAR = ' ';

// Metodos de prueba
void chequear_jugador(personaje_t* jugador){
    printf("Posicion iniicial pj: (%d;%d)\n", (*jugador).posicion.fila, (*jugador).posicion.columna);
    printf("Monedas iniciales pj: %d\n", (*jugador).cant_monedas);
    printf("Insecticidas iniciales pj: %d\n", (*jugador).cant_insecticidas);
    printf("Fertilizante inicial pj: %d\n", (*jugador).tiene_fertilizante);

    for (int i = 0; i < MAX_CANASTA; i++) {
        printf("Canasta[%d]: %c\n", i, (*jugador).canasta[i]);
    }

    printf("Tope canasta pj: %d\n", (*jugador).tope_canasta);
}



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

    chequear_jugador(&juego.jugador);

    return 0;
}
