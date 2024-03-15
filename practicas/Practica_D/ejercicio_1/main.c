/*
Kuzco, el emperador Inca, está buscando desesperadamente un antídoto para convertirse en 
humano. El problema es que Yzma tiene una enorme colección de pociones, y Kuzco no sabe 
por dónde empezar. Considerando la colección de pociones como un vector, se pide:

Encontrar el antídoto para Kuzco, sabiendo que este está representado por el caracter 
“A”, y devolver la posición del vector en la que se encuentra. Se puede asumir que 
siempre se va a encontrar el antidoto.
Ejemplos

Si se recibe un vector [T,R,P,A,L,E,S,B], se debe devolver la posición 3.
Si se recibe un vector [A,L,M,S,W,Q], se debe devolver la posición 0.

*/

#include <stdio.h>
#include "solucion.h"

int main() {
    char pociones[MAX_POCIONES] = {'T','R','P','A','L','E','S','B'};
    int tope_pociones = 8;
    int posicion = posicion_antidoto(pociones, tope_pociones);
    printf("La posicion del antidoto es: %d\n", posicion);
    return 0;
}