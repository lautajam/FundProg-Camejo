/*
El señor Bigotes está medio frustrado porque su último experimento, un control remoto para controlar a Brandy es un fracaso.
Este suceso está haciendo que, cada vez que se toca la cabeza, se le caigan 78 pelos.

Crear un programa que, dadas las veces que el señor Bigotes se tocó la cabeza, imprima por pantalla cuántos pelos perdió.
*/

#include <stdio.h>

const int PELOS_CAIDOS_POR_VEZ = 78;

int main(){

    int pelos_caidos_totales = 0;
	int veces;
	scanf("%i", &veces);
	
    pelos_caidos_totales = PELOS_CAIDOS_POR_VEZ * veces;

    printf("%i pelos.\n", pelos_caidos_totales);
    

	return 0;
}