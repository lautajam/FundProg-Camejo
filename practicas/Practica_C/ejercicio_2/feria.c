#include <stdio.h>
#include "feria.h"

static const char SMALL    = 'S';
static const char MEDIUM   = 'M';
static const char LARGE    = 'L';
const int  INIT_INT = 0;

/*
    Pre: Recibe el array con los talles de las prendas y el tope (cuantas prendas hay)
    Post: Imprime el talle de la prenda n
*/
void mostrar_talle_prendas(char prendas[], int* tope_prendas){

    for (int i = 0; i < *tope_prendas; i++) {
        if (prendas[i] == SMALL)
            printf("La prenda %d es talle Small\n", (i + 1));
        if (prendas[i] == MEDIUM)
            printf("La prenda %d es talle Medium\n", (i + 1));
        if (prendas[i] == LARGE)
            printf("La prenda %d es talle Large\n", (i + 1));
    } 
}

/*
    Pre: Recibe el array con los talles de las prendas y el tope (cuantas prendas hay)
    Post: Imprime por pantalla la cantidad de prendas de cada talle que hay
*/
void contar_talles(char prendas[], int* tope_prendas){

    int cantid_small = INIT_INT, cantid_medium = INIT_INT, cantid_large = INIT_INT; 

    for (int i = 0; i < *tope_prendas; i++) {
        if (prendas[i] == SMALL)
            cantid_small++;
        if (prendas[i] == MEDIUM)
            cantid_medium++;
        if (prendas[i] == LARGE)
            cantid_large++;
    }

    printf("Cantidad de prendas Small: %d\n", cantid_small);
    printf("Cantidad de prendas Medium: %d\n", cantid_medium);
    printf("Cantidad de prendas Large: %d\n", cantid_large);
}

/*
    Pre: Recibe el array con los talles de las prendas, el tope (cuantas prendas hay) y el talle que hay que agregar
    Post: Agrega en la primer posicion vacia el talle de prenda a agregar
*/
void agregar_remera(char prendas[], int* tope_prendas, char prenda_agregar){
    prendas[*tope_prendas] = prenda_agregar;
    (*tope_prendas)++;
}