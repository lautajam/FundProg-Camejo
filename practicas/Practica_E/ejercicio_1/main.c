/*

Phil, un sátiro entrenador de héroes, tiene el sueño de entrenar al mayor héroe que Grecia ha 
visto y tiene al candidato perfecto: Hércules. El problema es que Hércules es un simple adolescente 
que no puede controlar su endiosada fuerza, por lo que Phil deberá prepararlo para que esté apto 
para salvar a los ciudadanos griegos.

Es por esto que Phil te encargó preparar su patio delantero en un avanzado gimnasio en el que 
Hércules se entrenará. Se pide:

    · Implementar una función que inicialice todo el patio con mancuernas (“M”).
*/

#include <stdio.h>

#define MAX_TERRENO 10

const char MANCUAERNAS = 'M';

/*
    Pre: Recibe un gimnasio (matriz char de MAX_TERRENO x MAX_TERRENO).
    Post: Inicializa el gimnasio con mancuernas ('M').
*/
void inicializar_gimnasio(char gimnasio[MAX_TERRENO][MAX_TERRENO]) {
	
    for (int i = 0; i < MAX_TERRENO; i++) {
        for (int j = 0; j < MAX_TERRENO; j++) {
           gimnasio[i][j] = MANCUAERNAS;
        }  
    }
}

int main() {
    char gimnasio[MAX_TERRENO][MAX_TERRENO];

    inicializar_gimnasio(gimnasio);

    printf("El gimnasio quedó así:\n");
    for (int i = 0; i < MAX_TERRENO; i++) {
        for (int j = 0; j < MAX_TERRENO; j++) {
            printf("%c ", gimnasio[i][j]);
        }
        printf("\n");
    }

    return 0;
}