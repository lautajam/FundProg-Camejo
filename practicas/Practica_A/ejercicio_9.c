/*
Clayton, cansado de los métodos de Jane y el profesor Porter, decide emplear un método más arcaico para hacerle entender a Tarzán que quieren ver gorilas. El método se basa en decir la palabra “gorila” y hacer que Tarzán la repita hasta que este entendiera a qué se refiere, aumentando el tono con cada repetición (https://www.youtube.com/watch?v=533JK0BrGOQ). El profesor Porter, sorprendido, decide contar cuántas veces se repitió este diálogo entre los dos. Por eso se pide:

Imprimir por pantalla esta discusión, sabiendo la cantidad total que contó el profesor Porter.
Ejemplos:

Si se recibe 1, debe imprimirse:
GO-RI-LA
GO-RI-LA!

Si se recibe 2, debe imprimirse:
GO-RI-LA
GO-RI-LA!
GO-RI-LA!!
GO-RI-LA!!!
*/

#include <stdio.h>

int main(){
	int veces_repetidas;
	scanf("%i", &veces_repetidas);
	
    for (int i = 0; i < veces_repetidas * 2; i++) {
            printf("GO-RI-LA");
            for (int k = 0; k <= i; k++) {
                if (k != 0){
                printf("!");
                }
            }
            printf("\n");
    }

	return 0;
}