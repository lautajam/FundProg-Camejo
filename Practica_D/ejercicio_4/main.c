/*
Alex se volvió fanática de la astrología por lo que empezó a leer libros y buscar información de cada 
signo. Para probar sus conocimientos, quiso hacerles unas preguntas a Justin y Max y tratar de adivinar 
de qué signo son. Para facilitarse el trabajo, les hizo las preguntas a los dos al mismo tiempo y en cada 
posición de un vector fue marcando S si ambos respondieron que sí, N si ambos respondieron que no, J si sólo 
Justin respondió que sí, y M si sólo Max respondió que sí.
Tiene como información adicional que los signos de ambos solamente pueden ser piscis, libra, acuario o cáncer.

-Implementar una función que calcule cuántas respuestas positivas tuvieron tanto Justin como Max, y a partir de 
este resultado, retorne true si son del mismo signo, o false en caso contrario.

Entre 0 y 2: Libra.
Entre 3 y 5: Piscis.
Entre 6 y 8: Acuario.
Más de 8: Cáncer.
*/


#include <stdio.h>
#include <stdbool.h>
#define MAX_RESPUESTAS 300

const char AMBOS_SI  = 'S';
const char AMBOS_NO  = 'N';
const char JUSTIN_SI = 'J';
const char MAX_SI    = 'M';

/*
    Pre: Recibe un vector de caracteres con las respuestas de Justin y Max, y el tope de respuestas.
    Post: Devuelve true si ambos tienen el mismo signo, o false en caso contrario.
*/
bool tienen_mismo_signo(char respuestas[MAX_RESPUESTAS], int tope_respuestas) {
    
    int respuestas_si_justin = 0;
    int respuestas_si_max    = 0;

    for (int i = 0; i < tope_respuestas; i++) {
        if (respuestas[i] == JUSTIN_SI || respuestas[i] == AMBOS_SI){ respuestas_si_justin++; }
        if (respuestas[i] == MAX_SI    || respuestas[i] == AMBOS_SI){ respuestas_si_max++; }

    }

    return (respuestas_si_justin == respuestas_si_max) ? true : false;
}

int main() {
    char respuestas[ MAX_RESPUESTAS ] = {AMBOS_NO, JUSTIN_SI, MAX_SI, AMBOS_SI, AMBOS_SI, AMBOS_NO };

    int tope_respuestas = 6;

    if (tienen_mismo_signo(respuestas, tope_respuestas)) {
        printf("Tienen el mismo signo\n");
    } else {
        printf("No tienen el mismo signo\n");
    }

    return 0;
}