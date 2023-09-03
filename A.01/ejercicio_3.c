/*
Roger, dueño de los 101 dálmatas, le pidió a Nanny que se encargue de comprarle alimento balanceado a los cachorros para la cena de hoy. El problema es que a Nanny se le complica sacar cuentas sobre cuántas bolsas debe comprar para que alcance para todos, por lo que le pidió ayuda a la facultad de ingeniería.

Teniendo en cuenta que cada bolsa rinde para 10 cachorros, se pide:

Crear un programa que de acuerdo a la cantidad de cachorros que querrán cenar, imprima por pantalla cuántas bolsas de alimento balanceado Nanny tendrá que comprar.
*/

#include <stdio.h>

const int CACHORROS_POR_BOLSA = 10;

int main(){
	int cachorros;
	scanf("%i", &cachorros);
	
    int cantidad_bolsas = 0;

    cantidad_bolsas = cachorros / CACHORROS_POR_BOLSA;

    if (cantidad_bolsas < 1){
		printf("1 bolsa.\n");
	} else if ((cachorros % CACHORROS_POR_BOLSA) != 0){
        cantidad_bolsas++;
    	printf("%i bolsas.\n", cantidad_bolsas);
	} else {
        printf("%i bolsas.\n", cantidad_bolsas);
    }

	return 0;
}