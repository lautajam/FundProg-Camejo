/*
Como era de esperarse, la incontrolada fuerza de Hércules causó que algunas mancuernas salieran volando 
al bosque cercano, perdiéndose para siempre. Como a Phil le gusta mantener su almacén de equipamiento 
listo y preparado para el próximo héroe que toque su puerta, necesita reponer las mancuernas perdidas 
lo antes posible, por lo que se pide:

Implementar una función que recorra el bosque (ahora representado por mancuernas “M” y pasto “P”) 
y devuelva la cantidad de mancuernas perdidas.
*/

#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

const char MANCUAERNAS = 'M';
const char PASTO       = 'P';

/*
    Pre: Recibe un bosque (matriz char de MAX_FILAS x MAX_COLUMNAS).
    Post: Devuelve la cantidad de mancuernas perdidas.
*/
int mancuernas_perdidas(char bosque[MAX_FILAS][MAX_COLUMNAS]){
    
    int mancuerdas_perdidas = 0;
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            if (bosque[i][j] == PASTO){ mancuerdas_perdidas++; }
        }
    }

    return mancuerdas_perdidas;
}

int main() {
    char bosque[MAX_FILAS][MAX_COLUMNAS] = {
        {'P', 'P', 'P', 'P', 'P'},
        {'P', 'P', 'P', 'P', 'P'},
        {'P', 'P', 'P', 'P', 'P'},
        {'P', 'P', 'P', 'P', 'P'},
        {'P', 'P', 'P', 'P', 'P'}
    };

    int perdidas = mancuernas_perdidas(bosque);

    printf("Cantidad de mancuernas perdidas: %d\n", perdidas);

    return 0;
}




