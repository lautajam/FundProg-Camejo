/*
Brandy está catalogando su ropa para una feria americana y le pidió al Señor Bigotes ayuda
para ir organizando la ropa por talles. Sólo tiene talles S (small), M(medium) o L (large)
(espera conseguir prendas de talles más variados para la próxima).
Se pide:
1. Dado un vector de prendas y su tope, hacer un procedimiento que muestre el talle
de cada prenda de la siguiente manera:
La prenda 1 es talle S
La prenda 2 es talle M
...
2. Dado un vector de prendas, donde cada posición tiene el talle de cada una, contar la
cantidad de prendas que hay de cada talle y mostrar un mensaje por pantalla.
3. Brandy se dió cuenta que se olvidó de separar una para la feria. Hacer un
procedimiento que reciba el talle de la remera olvidada y agregarla al vector.
4. Hacer una biblioteca feria.h con los procedimientos pedidos en los puntos 1, 2 y 3.
*/

#include <stdio.h>
#include "feria.h"

#define CANTIDAD_PRENDAS_MAX 25
static const char SMALL    = 'S';
static const char MEDIUM   = 'M';
static const char LARGE    = 'L';

int main(){

    char prendas[CANTIDAD_PRENDAS_MAX] = {LARGE, MEDIUM, SMALL, SMALL, MEDIUM, SMALL, SMALL, MEDIUM, LARGE, 
                                          SMALL, MEDIUM, LARGE, MEDIUM, MEDIUM, LARGE, SMALL, SMALL, LARGE, 
                                          MEDIUM, MEDIUM};
    int tope_prendas = 20;
    char prenda_agregar = SMALL;

    mostrar_talle_prendas(prendas, &tope_prendas);
    contar_talles(prendas, &tope_prendas);

    printf("Agregando prenda talle %c \n", prenda_agregar);

    agregar_remera(prendas, &tope_prendas, prenda_agregar);

    mostrar_talle_prendas(prendas, &tope_prendas);
    contar_talles(prendas, &tope_prendas);
    return 0;
}