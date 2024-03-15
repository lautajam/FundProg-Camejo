/*
Pooh está jugando con Tiger al típico juego de los magos de esconder una pelota debajo de un vaso y mezclarlo junto 
con otros vasos. Solo que su versión del juego es mucho más rica, ya que esconden miel en vez de una pelota y usan 
cajas en vez de vasos (porque los potes de miel no entran en los vasos).
Si el que elige encuentra la miel se la puede comer, sino, se la queda el que la mezcló.
Después de un par de rondas están un poco demasiado llenos como para mezclar, así que te pidieron implementar un 
algoritmo que la realice.

Implementar un procedimiento que dado tres cajas realice la mezcla. Cada caja va a ser pasada por referencia y 
guardan un char que representa si tienen miel(H) o si están vacías (V). El algoritmo para mezclar sigue las 
siguientes reglas:
    · Si la hamburguesa estaba en la primera caja, esta pasa a estar en la tercera.
    · Si la hamburguesa estaba en la segunda caja esta pasa a estar en la primera.
    · Y si la hamburguesa estaba en la tercera caja, esta pasa a estar en la segunda.
*/

#include <stdio.h>

// CONSTANTES
const char CON_MIEL   = 'H';
const char VACIA      = 'V';

void mezclar_cajas(char* primer_caja, char* segunda_caja, char* tercera_caja) {
    
    printf("Mezclando cajas...\n");

    if(*primer_caja == CON_MIEL){
        *primer_caja = VACIA;
        *tercera_caja = CON_MIEL;
    } else if (*segunda_caja == CON_MIEL){
        *segunda_caja = VACIA;
        *primer_caja = CON_MIEL;
    } else {
        *tercera_caja = VACIA;
        *segunda_caja = CON_MIEL;
    }
}

int main(){

    char caja_1 = VACIA;
    char caja_2 = VACIA;
    char caja_3 = CON_MIEL;

    printf("Caja 1: %c\n", caja_1);
    printf("Caja 2: %c\n", caja_2);
    printf("Caja 3: %c\n", caja_3);

    mezclar_cajas(&caja_1, &caja_2, &caja_3);

    printf("Caja 1: %c\n", caja_1);
    printf("Caja 2: %c\n", caja_2);
    printf("Caja 3: %c\n", caja_3);

    return 0;
}