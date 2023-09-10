/*
Baloo y Bagheera están apostando parte de sus reservas favoritas de frutas en adivinar cuántas frutas recolectará 
Mowgli en el día. El que gana se lleva 10 frutas del que pierde, y si hay empate las reservas de ambos están a salvo.

Implementar una función que dadas las reservas de Baloo, las de Bagheera y la cantidad de frutas que trajo Mowgli en 
el día modifique ambas reservas según corresponda. Tener en cuenta que:
    · Si Mowgli trajo más de 10 frutas, Baloo le da 10 frutas a Bagheera.
    · Si Mowgli trajo menos de 10 frutas, Bagheera le da 10 frutas a Baloo.
    · Si trajo exactamente 10 frutas, entonces no pasa nada.
*/

#include <stdio.h>

// CONSTANTES
const int FRUTAS_LIMITE   = 10;
const int FRUTAS_APUESTA  = 10;
const int RESERVA_INICIAL = 100;
const int FRUTAS_INICIAL  = 0; 

void realizar_apuesta(int* reserva_bagheera, int* reserva_baloo, int frutas_mowgli) {
    
    if (frutas_mowgli > FRUTAS_LIMITE && *reserva_baloo >= FRUTAS_APUESTA) {
        *reserva_baloo    -= FRUTAS_APUESTA;
        *reserva_bagheera += FRUTAS_APUESTA;
    } else if (frutas_mowgli > FRUTAS_LIMITE && *reserva_baloo < FRUTAS_APUESTA){
        *reserva_bagheera += *reserva_baloo;
        *reserva_baloo    -= *reserva_baloo;
    } else if (frutas_mowgli < FRUTAS_LIMITE && *reserva_bagheera >= FRUTAS_APUESTA) {
        *reserva_baloo    += FRUTAS_APUESTA;
        *reserva_bagheera -= FRUTAS_APUESTA;
    } else if (frutas_mowgli < FRUTAS_LIMITE && *reserva_bagheera < FRUTAS_APUESTA){
        *reserva_baloo    += *reserva_bagheera;
        *reserva_bagheera -= *reserva_bagheera;
    } else {

    }
}

int main() {
    
    int reserva_bagheera = 12;
    int reserva_baloo    = 8;
    int frutas_mowgli    = FRUTAS_INICIAL;
    
    printf("Reserva de Bagheera: %d\n", reserva_bagheera);
    printf("Reserva de Baloo: %d\n", reserva_baloo);
    
    printf("Ingrese la cantidad de frutas que trajo Mowgli: ");
    scanf("%d", &frutas_mowgli);
    
    realizar_apuesta(&reserva_bagheera, &reserva_baloo, frutas_mowgli);
    
    printf("Reserva de Bagheera: %d\n", reserva_bagheera);
    printf("Reserva de Baloo: %d\n", reserva_baloo);
    
    return 0;
}