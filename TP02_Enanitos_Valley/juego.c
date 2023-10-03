#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "granja.h"
#include "calculo_enanito.h"

static const char INIT_CHAR = ' ';
const int PERDIDO = -1;
const int GANADO  = 1;

// Metodo de prueba
void chequear_huerta(juego_t* juego){     //test
        for (int i = 0; i < MAX_HUERTA; i++) {
            for (int j = 0; j < MAX_PLANTAS; j++) {
                printf(" (%d,  ", juego->huertas[i].cultivos[j].posicion.fila);
                printf(" %d) | ", juego->huertas[i].cultivos[j].posicion.columna);
                printf(" %c \n", juego->huertas[i].cultivos[j].tipo);
            }
            printf("\n");
        }
}

/*
    Pre: recibe el juego de donde va a extraer la información
    Post: devuelve la interfaz del juego por pantalla, con los datos
            de la canasta, los movimientos, las monedas, los insecticidas
            y los fertilizantes
            Las letras corresponden a las acciones que puede realizar el jugador
            Y los precios de los cultivos con las letras correspondientes
*/
void imprimir_interfaz(juego_t juego){

    printf(" Canasta:");
    for (int i = 0; i < juego.jugador.tope_canasta; i++) {
        printf(" %c -", juego.jugador.canasta[i]);
    }
    printf("\n");

    printf(" Movimientos:  %d | Monedas: %d\n", juego.movimientos, juego.jugador.cant_monedas);
    printf(" Insecticidas: %d | Fertilizantes: %d\n", juego.jugador.cant_insecticidas, 
                                                        juego.jugador.tiene_fertilizante);
    printf(" Tomate  (t):  5 monedas | Zanahoria (z): 10 monedas \n");
    printf(" Brocilo (b): 15 monedas | Lechuga   (l): 20 monedas \n");
    printf(" Accion w/a/s/d (moverse) o t/z/b/l (comprar): ");
}

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

    //printf("Coordenadas del jugador: (%d, %d)\n", juego.jugador.posicion.fila, juego.jugador.posicion.columna);  //test
    //printf("Coordenadas del deposito: (%d, %d)\n", juego.deposito.fila, juego.deposito.columna);   //test
    //chequear_huerta(&juego);   //test
    while (estado_juego(juego) != PERDIDO && estado_juego(juego) != GANADO) {

        imprimir_terreno(juego);

        imprimir_interfaz(juego);
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
