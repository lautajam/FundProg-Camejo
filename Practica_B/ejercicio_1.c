/*
Los tres mosqueteros tienen que rescatar a la princesa, la cual se encuentra encerrada en una torre, detrás de una 
puerta con seguro. Ésta misma sólo se abre si se ingresa el código correcto, que consiste en la suma de las edades 
de los tres. El problema es que ninguno de los 3 es bueno con las sumas. Ayudalos implementando un procedimiento que 
les diga el código a ingresar.

-Implementar el procedimiento 'imprimir_codigo', la cual reciba tres números e imprima por pantalla el resultado 
de la suma de estos.

Ejemplos:

Si se recibe 15, 18 y 17, debe imprimirse "50".
Si se recibe 21, 20 y 24, debe imprimirse "65".

*/

#include <stdio.h>

const int INIT_INT = 0;

void imprimir_codigo(int edad_mickey, int edad_goofy, int edad_donald) {

    int edad_total = INIT_INT;

    edad_total = edad_mickey + edad_goofy + edad_donald;

    printf("%i", edad_total);
}

int main(){
    int edad_mickey = INIT_INT;
	scanf("%i", &edad_mickey);

	int edad_goofy = INIT_INT;
	scanf("%i", &edad_goofy);
    
	int edad_donald = INIT_INT;
	scanf("%i", &edad_donald);

    imprimir_codigo(edad_mickey, edad_goofy, edad_donald);

    return 0;
}