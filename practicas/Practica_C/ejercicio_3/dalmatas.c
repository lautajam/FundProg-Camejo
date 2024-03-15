#include <stdio.h>
#include <stdbool.h>
#include "dalmatas.h"

// CONSTANTES
const int MINIMO_AÑOS     = 5;
const int INIT_INT        = 0;
const int MINIMO_DALAMTAS = 15;

/*
*   Recibe un array de enteros con las edades de los dalmatas y el tope de ese array, 
*   ademas de un array de enteros vacio (donde se guardarán los que tengan edades < 5) y el tope de ese array.
*/
void cargar_dalmatas_sirven(int dalmatas_edades[CANTIDAD_DALMATAS], int tope_dalmatas_edades,
                            int dalmatas_posiciones[CANTIDAD_DALMATAS], int* tope_dalamtas_posiciones){

    for (int i = 0; i < tope_dalmatas_edades; i++) {
        if(dalmatas_edades[i] < 5) {
            dalmatas_posiciones[*tope_dalamtas_posiciones] = dalmatas_edades[i];
            (*tope_dalamtas_posiciones)++;
        }
    }
}

/*
*   Recibe un array de enteros con las posiciones de los dalmatas que sirven y el tope de ese array.
*   Devuelve true si hay al menos 15 dalmatas, false en caso contrario.
 */
bool revisar_cantidad_dalmatas(int dalmatas_posiciones[CANTIDAD_DALMATAS], int tope_dalamtas_posiciones){

    int contador_dalamtas = INIT_INT;
    for (int i = 0; i < tope_dalamtas_posiciones; i++) {
        contador_dalamtas++;
        if (contador_dalamtas == 15) return true;
    }

    return false;

}

