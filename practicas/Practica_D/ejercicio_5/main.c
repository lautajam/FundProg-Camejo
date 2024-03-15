/*

Lilo y Stitch llevan registro de todos los experimentos extraviados del Dr. Jumba que encuentran, 
y para hacerlo los tienen en un vector donde a cada experimento lo representan con un id que es un entero.
Últimamente están encontrando muchos experimentos nuevos y se les complica un poco estar agregándolos 
a mano a este vector, por lo que nos pidieron ayuda para que creemos un algoritmo que lo haga por ellos. 
Pero como nosotros nos dormimos en esas clases te lo pedimos a vos.

Implementar una función que dado un vector, su tope y un id agregue al nuevo experimento al vector.
Además si no es posible agregarlo porque el vector ya está al máximo de su capacidad se pide que 
devuelva false y en caso contrario que devuelva true.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_EXPERIMENTOS 10

/*
    Pre: Recibe un vector de experimentos, su tope y un id de experimento.
    Post: Devuelve true si se pudo agregar el experimento al vector, false en caso contrario.
*/
bool registrar_experimento(int experimentos[MAX_EXPERIMENTOS], int* tope_experimentos, int id_experimento) {

    if (*tope_experimentos < MAX_EXPERIMENTOS) {
        experimentos[*tope_experimentos] = id_experimento;
        (*tope_experimentos)++;
        return true;
    }

    return false;
}

int main() {
    int experimentos[MAX_EXPERIMENTOS] = { 0 };
    int tope_experimentos = 0;

    printf("Se registraron los siguientes experimentos: \n");
    printf("Experimento 1: %d\n", registrar_experimento(experimentos, &tope_experimentos, 1));
    printf("Experimento 2: %d\n", registrar_experimento(experimentos, &tope_experimentos, 2));
    printf("Experimento 3: %d\n", registrar_experimento(experimentos, &tope_experimentos, 3));
    printf("Experimento 4: %d\n", registrar_experimento(experimentos, &tope_experimentos, 4));
    printf("Experimento 5: %d\n", registrar_experimento(experimentos, &tope_experimentos, 5));
    printf("Experimento 6: %d\n", registrar_experimento(experimentos, &tope_experimentos, 6));
    printf("Experimento 7: %d\n", registrar_experimento(experimentos, &tope_experimentos, 7));
    printf("Experimento 8: %d\n", registrar_experimento(experimentos, &tope_experimentos, 8));
    printf("Experimento 9: %d\n", registrar_experimento(experimentos, &tope_experimentos, 9));
    printf("Experimento 10: %d\n", registrar_experimento(experimentos, &tope_experimentos, 10));
    printf("Experimento 11: %d\n", registrar_experimento(experimentos, &tope_experimentos, 11));

    return 0;
}