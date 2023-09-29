/*
Oliver y su pandilla se tienen que enfrentar a Sykes y sus dobermans, quienes secuestraron a 
Jenny. Es por esto que deciden organizarse para poder hacerles frente. Considerando que solo
Dodger, Einstein, y Francis son aptos para pelear, deciden averiguar quién es el más hábil 
para que, en caso de que haya una pelea, éste luche primero.

Considerando que las habilidades de los perros se dividen en: 
    inteligencia (posición 0), 
    resistencia física (posición 1),
    agilidad (posición 2),
    y fuerza (posición 3), 
    y que la capacidad de pelea se calcula como la suma de la inteligencia, 
        el triple de la resistencia física, el doble de la agilidad, y la fuerza, se pide:

Implementar una función que calcule la capacidad de pelea de cada perro, y devuelva la habilidad del que peleará primero.
Ejemplo:

Si se reciben los vectores Dodger: [4,3,8,2], Einstein: [5,1,9,3] y Francis: [4,8,7,1], siendo el resultado de cada 
uno 31, 29 y 43 respectivamente, se debe devolver 43.
*/

#include <stdio.h>

#define MAX_HABILIDADES 4

/*
    Pre:  recibe un vector (int) de habilidades de un perro
    Post: devuelve el puntaje de habilidad del perro
*/
int puntaje_habilidad_perro(int habilidades_perro[MAX_HABILIDADES]) {

    int inteligencia       = habilidades_perro[0];
    int resistencia_fisica = habilidades_perro[1];
    int agilidad           = habilidades_perro[2];
    int fuerza             = habilidades_perro[3];

    return inteligencia + (3 * resistencia_fisica) + (2 * agilidad) + fuerza;
}

/*
    Pre:  recibe tres vectores (int) de habilidades de tres perros
    Post: devuelve el puntaje de habilidad del perro mas habilidoso
*/
int perro_mas_habilidoso(int habilidades_dodger[MAX_HABILIDADES], int habilidades_einstein[MAX_HABILIDADES], 
                         int habilidades_francis[MAX_HABILIDADES]) { 

    int puntaje_dodger   = puntaje_habilidad_perro(habilidades_dodger);
    int puntaje_einstein = puntaje_habilidad_perro(habilidades_einstein);
    int puntaje_francis  = puntaje_habilidad_perro(habilidades_francis);

    if (puntaje_dodger > puntaje_einstein && puntaje_dodger > puntaje_francis) {
        return puntaje_dodger;
    } else if (puntaje_einstein > puntaje_dodger && puntaje_einstein > puntaje_francis) {
        return puntaje_einstein;
    } else {
        return puntaje_francis;
    }
}


int main() {
    int habilidades_dodger[]   = {4, 3, 8, 2};
    int habilidades_einstein[] = {5, 1, 9, 3};
    int habilidades_francis[]  = {4, 8, 7, 1};

    int puntaje_mas_habilidoso = perro_mas_habilidoso(habilidades_dodger, habilidades_einstein, habilidades_francis);

    printf("El puntaje del perro mas habilidoso es: %d\n", puntaje_mas_habilidoso);

    return 0;
}
