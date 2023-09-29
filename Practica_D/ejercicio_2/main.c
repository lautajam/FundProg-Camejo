/*
Maggie, Grace, y la Sra. Calloway están necesitando $750 para saldar la deuda que 
Pearl Gesner, la dueña de la granja, tiene con el banco, y así evitar que la 
granja sea rematada. Es por esto que por el último mes han estado ahorrando 
dinero día por día, anotando lo que juntan en un vector. Se pide:

Implementar una función que dado un vector de ahorros y su tope, devuelva true si 
son capaces de saldar la deuda con el banco, o false en caso contrario.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_AHORROS 31
const double PLATA_NECESARIA = 750.00;

/*
    Pre:  recibe un vector (int) de ahorros y su tope (int)
    Post: devuelve true si se puede saldar la deuda o false en caso contrario
*/
bool se_salda_la_deuda(int ahorros[MAX_AHORROS], int tope_ahorros) {
	
    int plata_ahorrada = 0;

    for (int i = 0; i < tope_ahorros; i++) {
       plata_ahorrada += ahorros[i];
    }
    
    return (plata_ahorrada >= PLATA_NECESARIA) ? true : false;
}

int main() {

    int ahorros[MAX_AHORROS] = {100, 150, 10, 20, 50, 5, 90, 1, 24, 10, 
                                0, 0, 0, 0, 0, 0, 0, 0, 4, 34,
                                200, 0, 0, 0, 0, 100, 0, 0, 0, 0, 50};

    int tope_ahorros = 31;

    printf("Se puede pagar la deuda? %s\n", se_salda_la_deuda(ahorros, tope_ahorros) ? "true" : "false");

    return 0;
}
