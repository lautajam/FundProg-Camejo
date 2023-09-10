/*
Los hermanos de Mérida (Harris, Hubert y Hamish) atraviesan varios cambios de humor a lo largo de un año 
según las estaciones. Según su hermana, por cada estación cada uno pasa por un humor diferente:
    · Primavera (P): Harris y Hubert están contentos, mientras que Hamish está meh.
    · Verano    (V): Hamish está triste, Harris está meh y Hubert está contento.
    · Otoño     (O): los tres hermanos están contentos (obvio, si es la mejor estación).
    · Invierno  (I): Hamish está contento, Harris está meh y Hubert está triste.

Implementar una función que dada la estación del año modifiqué el humor de cada hermano al correspondiente, y devuelva 
la cantidad de hermanos que están contentos.
Tener en cuenta que cada humor está representado por un caracter:
    · Contento (C)
    · Meh      (M)
    · Triste   (T)
*/

#include <stdio.h>

// CONSTANTES
const int  INIT_INT = 0;
const int  HERMANOS_CONTENTOS_PRIMAVERA = 2;
const int  HERMANOS_CONTENTOS_VERANO    = 1;
const int  HERMANOS_CONTENTOS_OTONIO     = 3;
const int  HERMANOS_CONTENTOS_INVIERNO  = 1;
const char INIT_CHAR = ' ';
const char PRIMAVERA = 'P';
const char VERANO    = 'V';
const char OTONIO     = 'O';
const char INVIERNO  = 'I';
const char CONTENTO  = 'C';
const char MEH       = 'M';
const char TRISTE    = 'T';

int definir_humor_osos(char* humor_harris, char* humor_hubert, char* humor_hamish, char estacion){
    
    int hermanos_contentos = INIT_INT;

    if (estacion == PRIMAVERA) {
        *humor_harris = CONTENTO;
        *humor_hubert = CONTENTO;
        *humor_hamish = MEH;
        hermanos_contentos = HERMANOS_CONTENTOS_PRIMAVERA;
    } else if (estacion == VERANO) {
        *humor_harris = MEH;
        *humor_hubert = CONTENTO;
        *humor_hamish = TRISTE;
        hermanos_contentos = HERMANOS_CONTENTOS_VERANO;
    } else if (estacion == OTONIO) {
        *humor_harris = CONTENTO;
        *humor_hubert = CONTENTO;
        *humor_hamish = CONTENTO;
        hermanos_contentos = HERMANOS_CONTENTOS_OTONIO;
    } else if (estacion == INVIERNO) {
        *humor_harris = MEH;
        *humor_hubert = TRISTE;
        *humor_hamish = CONTENTO;
        hermanos_contentos = HERMANOS_CONTENTOS_INVIERNO;
    } else {
        printf("ERROR!");
    }

    return hermanos_contentos;
}

int main(){

    char humor_harris = INIT_CHAR;
    char humor_hubert = INIT_CHAR;
    char humor_hamish = INIT_CHAR;
    char estacion     = INIT_CHAR;
    int  hermanos_contentos = INIT_INT;

    printf("Ingrese la estacion del año: ");
    scanf("%c", &estacion);

    hermanos_contentos = definir_humor_osos(&humor_harris, &humor_hubert, &humor_hamish, estacion);

    printf("Harris: %c\n", humor_harris);

    printf("Hubert: %c\n", humor_hubert);

    printf("Hamish: %c\n", humor_hamish);

    printf("Hermanos contentos: %d\n", hermanos_contentos);

    return 0;
}