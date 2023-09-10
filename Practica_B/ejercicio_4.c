/*
Luego de observar con su espejo mágico, la reina ideó un plan para engañar a Blancanieves y darle la manzana envenenada,
el cual se basa en atacar el día que todos los enanitos estén trabajando, para que así no logren descubrirla. 
Ella sabe que todos trabajan siempre los días lunes, miércoles, viernes y domingo.
Para este ejercicio, se pide implementar tanto la función estan_trabajando como el procedimiento imprimir_plan:
Implementar la función estan_trabajando, que según un caracter devuelva true si ese día están trabajando o false 
en caso contrario.
Los días están representados con los siguientes caracteres:

Lunes (L).
Martes (M).
Miércoles (X).
Jueves (J).
Viernes (V).
Sábado (S).
Domingo (D).

Implementar el procedimiento puede_atacar, el cual recibe un caracter que representa el día de la semana y las horas 
que descansó, devolviendo true si es que todos los enanos están trabajando ese día y descansó 8 horas o más.
*/

#include <stdio.h>
#include <stdbool.h>

// CONSTANTES
const int  INIT_INT = 0;
const int  HORAS_NECESARIAS_SUENIO = 8;
const char INIT_CHAR = ' ';
const char LUNES     = 'L';
const char MARTES    = 'M';
const char MIERCOLES = 'X';
const char JUEVES    = 'J';
const char VIERNES   = 'V';
const char SABADO    = 'S';
const char DOMINGO   = 'D';


bool estan_trabajando(char dia) {
    
    switch (dia){
        case 'L':
            return true;
            break;
        case 'X':
            return true;
            break;
        case 'V':
            return true;
            break;
        case 'D':
            return true;
            break;
    }

    return false;
}

bool puede_atacar(char dia, int horas_que_durmio) {

    bool trabajan = estan_trabajando(dia);

    return (trabajan == true && horas_que_durmio >= HORAS_NECESARIAS_SUENIO) ? true : false;

}

int main(){

    char dia = INIT_CHAR;
    int horas_que_durmio = INIT_INT;

    printf("Ingrese el dia de la semana: ");
    scanf("%c", &dia);

    printf("Ingrese las horas que durmio: ");
    scanf("%i", &horas_que_durmio);

    bool puede_atacar_ = puede_atacar(dia, horas_que_durmio);

    if (puede_atacar_ == true){
        printf("La reina puede atacar\n");
    } else {
        printf("La reina no puede atacar\n");
    }

    return 0;
}