/*
Los 101 dálmatas fueron al restaurante del chef de la Dama y el Vagabundo, porque
escucharon que ahí le sirven de comer a los perros. Como al chef no le quedó otra que
aceptar servirles (¿cómo hace para echar a 101 perros?), nos pidió ayuda para tomar los
pedidos. Hay 3 opciones en el menú:
    ● A - pizza con jamón
    ● B - fideos con bolognesa
    ● C - pastel de papa
Se pide:
1. Hacer un procedimiento que le vaya pidiendo platos al usuario y los vaya guardando
en un vector, hasta que ingrese ‘X’.
*/

#include <stdio.h>

#define CANTIDAD_PEDIDOS 110

const char PIZZA            = 'A';
const char FIDEOS_BOLOGNESA = 'B';
const char PASTEL_PAPA      = 'C';
const char CARACTER_CORTE   = 'X';
const int  INIT_INT  = 0;
const char INIT_CHAR = ' ';

/*
    Pre: Recibe un array char donde se guardaran los pedidos y un int que indica el tope del array (cantidad de pedidos)
    Post: Guarda los pedidos en el array de forma ordenada
*/
void tomar_pedidos(char pedidos_dalmatas[CANTIDAD_PEDIDOS], int *tope_pedidos){

    char opcion_pedido = INIT_CHAR;
    do{
        printf("Ingrese el pedido del dálmata: ");
        printf("A - pizza, B - fideos, C - pastel de papa, X - cortar\n");
        scanf(" %c", &opcion_pedido);

        if (opcion_pedido == PIZZA || opcion_pedido == FIDEOS_BOLOGNESA || opcion_pedido == PASTEL_PAPA) {
            pedidos_dalmatas[(*tope_pedidos)++] = opcion_pedido;
        } else if (opcion_pedido == CARACTER_CORTE) {
            printf("Cortando pedidos\n");
        } else {
            printf("Opción incorrecta\n");
        }

    } while (opcion_pedido != CARACTER_CORTE);

}

void mostar_pedidos(char pedidos_dalmatas[CANTIDAD_PEDIDOS], int tope_pedidos){

    for (int i = 0; i < tope_pedidos; i++) {
        if(pedidos_dalmatas[i] == PIZZA)
            printf("Pedido %d: Pizza\n", i);
        else if(pedidos_dalmatas[i] == FIDEOS_BOLOGNESA)
            printf("Pedido %d: Fideos\n", i);
        else if(pedidos_dalmatas[i] == PASTEL_PAPA)
            printf("Pedido %d: Pastel de papa\n", i);
    }

}

int main(){

    char pedidos_dalmatas[CANTIDAD_PEDIDOS];
    int tope_pedidos = INIT_INT;

    tomar_pedidos(pedidos_dalmatas, &tope_pedidos);

    mostar_pedidos(pedidos_dalmatas, tope_pedidos);

    return 0;
}

