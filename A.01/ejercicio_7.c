/*
Una vez que Chip y Dale por fin tienen un destino a donde ir, decidieron contarle a su amiga Gadget. Al escuchar los planes, se quiso sumar a sus vacaciones. Pero no le convencía el destino, por lo que tuvieron que hacer el sorteo nuevamente. Y para ser justos y que cada uno tenga la posibilidad de elegir, incorporaron como opción el mes de marzo y la vista de una laguna.

En esta oportunidad elige:
Chip: Si el mes es enero y la vista es laguna, si el mes es marzo y la vista es playa, o si el mes es febrero y la vista es montaña.
Dale: Si el mes es marzo y la vista es laguna, si el mes es febrero y la vista es playa, o si el mes es enero y la vista es montaña.
Gadget: Si el mes es febrero y la vista es laguna, si el mes es enero y la vista es playa, o si el mes es marzo y la vista es montaña.

-Imprimir por pantalla “Chip ”, “Dale” o “Gadget” según a quien le toque elegir esta vez.

-Convenciones:
Enero(E), febrero(F), marzo(X), playa(P), montaña (M), laguna (L).
*/

#include <stdio.h>

const char ENERO = 'E';
const char FEBRERO = 'F';
const char MARZO = 'X';
const char MONTANIA = 'M';
const char PLAYA = 'P';
const char LAGUNA = 'L';

int main(){
    
    char epoca;
    char paisaje;
    scanf(" %c", &epoca);
    scanf(" %c", &paisaje);
    
    if ((epoca == ENERO && paisaje == LAGUNA) || (epoca == MARZO && paisaje == PLAYA) || (epoca == FEBRERO && paisaje == MONTANIA)){
        printf("Chip\n");
    }

    else if ((epoca == ENERO && paisaje == MONTANIA) || (epoca == MARZO && paisaje == LAGUNA) || (epoca == FEBRERO && paisaje == PLAYA)){
        printf("Dale\n");
    }

    else{
        printf("Gadget\n");
    }

	return 0;
}