
#ifndef DALMATAS_H
#define DALMATAS_H


#define CANTIDAD_DALMATAS 101

/*
*   Recibe un array de enteros con las edades de los dalmatas y el tope de ese array, 
*   ademas de un array de enteros vacio (donde se guardarán los que tengan edades < 5) y el tope de ese array.
*/
void cargar_dalmatas_sirven(int[], int, int[], int*);

/*
*   Recibe un array de enteros con las posiciones de los dalmatas que sirven y el tope de ese array.
*   Devuelve true si hay al menos 15 dalmatas, false en caso contrario.
 */
bool revisar_cantidad_dalmatas(int[], int);

#endif /* DALMATAS_H */