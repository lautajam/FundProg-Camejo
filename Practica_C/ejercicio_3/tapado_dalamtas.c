/*
Cruella está planeando el secuestro de los dálmatas para poder hacerse un tapado. Ella
necesita únicamente dálmatas que tengan menos de 5 años.
1. Dado un vector en donde cada posición contiene la edad de un dálmata, se necesita
cargar otro con las posiciones en el vector anterior de los dálmatas que le sirven a
Cruella.
2. Cruella sabe que necesita al menos 15 dálmatas para hacer el tapado, crear una
función que devuelva si Cruella podrá o no hacerlo.
3. Realizar una biblioteca llamada dalmatas.h con las funciones creadas anteriormente.
*/

#include <stdio.h>
#include <stdbool.h>
#include "dalmatas.h"

// CONSTANTES
static const int INIT_INT = 0;

int main(){

    int dalmatas_edades[CANTIDAD_DALMATAS] = {4,7,2,2,2,4,6,8,1,3,3,4,1,6,1,1,9,10,1,2,3,4,5,6,7,8};
    int tope_dalmatas_edades = INIT_INT + 26;


    int dalmatas_posiciones[CANTIDAD_DALMATAS];
    int tope_dalamtas_posiciones = INIT_INT;

    cargar_dalmatas_sirven(dalmatas_edades, tope_dalmatas_edades, dalmatas_posiciones, &tope_dalamtas_posiciones);

    // recorre ambos arrays y los imprime

    for(int i = 0; i < tope_dalmatas_edades; i++){
        printf("Dalmata %d: %d años\n", (i + 1), dalmatas_edades[i]);
    }

    for(int i = 0; i < tope_dalamtas_posiciones; i++){
        printf("Dalmata %d: %d años\n", (i + 1), dalmatas_posiciones[i]);
    }

    if(revisar_cantidad_dalmatas(dalmatas_posiciones, tope_dalamtas_posiciones)){
        printf("Cruella puede hacer el tapado\n");
    } else {
        printf("Cruella no puede hacer el tapado\n");
    }
    return 0;
}