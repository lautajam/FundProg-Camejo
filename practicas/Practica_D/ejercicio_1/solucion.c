#include <stdio.h>
#include "solucion.h"

const char ANTIDOTO = 'A';

/*
    Pre:  recibe un vector (char) de pociones y su tope (int)
    Post: devuelve la posición de la posicion del antidoto (int)
          en caso de no encontrarlo devuelve -1
*/
int posicion_antidoto(char pociones[MAX_POCIONES], int tope_pociones) {
	
    for (int i = 0; i < tope_pociones; i++) {
        if (pociones[i] == ANTIDOTO) {
            return i;
        }
    }
    return -1;
}