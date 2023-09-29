#include <stdio.h>
#include <stdlib.h>
#include "granja.h"
#include "calculo_enanito.h"

static const char INIT_CHAR = ' ';

// Metodos de prueba
void chequear_jugador(personaje_t* jugador){
    printf("\n·Chequeo personaje\n");
    printf("    Posicion iniicial pj: (%d;%d)\n", (*jugador).posicion.fila, (*jugador).posicion.columna);
    printf("    Monedas iniciales pj: %d\n", (*jugador).cant_monedas);
    printf("    Insecticidas iniciales pj: %d\n", (*jugador).cant_insecticidas);
    printf("    Fertilizante inicial pj: %d\n", (*jugador).tiene_fertilizante);

    printf("    Canasta inicial personaje: \n");
    for (int i = 0; i < MAX_CANASTA; i++) {
        printf("        Canasta[%d]: %c\n", i, (*jugador).canasta[i]);
    }

    printf("    Tope canasta pj: %d\n", (*jugador).tope_canasta);
}

/*
void chequear_objetos(objeto_t* objetos){
    for (int i = 0; i < MAX_OBJETOS; i++) {
        printf("Objeto[%d] tipo: %c\n", i, (*objetos).tipo);
        printf("Objeto[%d] posicion: (%d;%d)\n", i, (*objetos).posicion.fila, (*objetos).posicion.columna);
    }
}

void chequear_huertas(huerta_t* huertas){
    for (int i = 0; i < MAX_HUERTA; i++) {
        printf("Huerta[%d] plagada: %d\n", i, (*huertas).plagado);
        printf("Huerta[%d] mov plagado: %d\n", i, (*huertas).movimientos_plagado);
        printf("Huerta[%d] tope cultivos: %d\n", i, (*huertas).tope_cultivos);

        for (int j = 0; j < MAX_PLANTAS; j++) {
            printf("Huerta[%d] cultivo[%d] mov plantado: %d\n", i, j, (*huertas).cultivos[j].movimiento_plantado);
            printf("Huerta[%d] cultivo[%d] tipo: %c\n", i, j, (*huertas).cultivos[j].tipo);
            printf("Huerta[%d] cultivo[%d] ocupado: %d\n", i, j, (*huertas).cultivos[j].ocupado);
            printf("Huerta[%d] cultivo[%d] posicion: (%d;%d)\n", i, j, (*huertas).cultivos[j].posicion.fila, (*huertas).cultivos[j].posicion.columna);
        }
    }
}
*/

void chequear_deposito(coordenada_t* deposito){
    printf("\n·Chequeo deposito\n");
    printf("    Deposito posicion: (%d;%d)\n", (*deposito).fila, (*deposito).columna);
}

int main(void) {

    juego_t juego;

    system("clear");

    char inicial_enanito = INIT_CHAR;

    printf("\nBienvenido al juego Enanito Valley\n");
    printf("Este es un juego sobre ayudar a blanca nieves a cultivar verduras\n");
    printf("Para comenzar, vamos a hacerte un test.\n");

    calcular_enanito(&inicial_enanito);

    inicializar_juego(&juego, inicial_enanito);

    printf("\nJuego inicializado\n"); // mensaje de prueba

    chequear_jugador(&juego.jugador); // metodo de prueba

    chequear_deposito(&juego.deposito); // metodo de prueba


    /* hay que revisar todo esto
    chequear_objetos(&juego.objetos[MAX_OBJETOS]); // metodo de prueba

    chequear_huertas(&juego.huertas[MAX_HUERTA]); // metodo de prueba
    */

    return 0;
}
