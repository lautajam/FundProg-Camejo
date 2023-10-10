#include <stdio.h>
#include <stdlib.h> // Para usar rand
#include <time.h>   // Para obtener una semilla desde el reloj
#include <stdbool.h>
#include "granja.h"
#include "manejo_juego.h"
#include "terreno.h"
#include <ctype.h>

// Letras de los movimientos
#define ARRIBA    'w'
#define IZQUIERDA 'a'
#define ABAJO     's'
#define DERECHA   'd'

// Verduras crecidas
#define TOMATE_CRECIDO    'T'
#define ZANAHORIA_CRECIDA 'Z'
#define BROCOLI_CRECIDO   'B'
#define LECHUGA_CRECIDA   'L'

const int MOVIMIENTOS_TOMATE    = 20;
const int MOVIMIENTOS_ZANAHORIA = 15;
const int MOVIMIENTOS_BROCOLI   = 10;
const int MOVIMIENTOS_LECHUGA   = 10;

// Valores iniciales de los atributos
static const int INIT_INT               = 0;
static const int INIT_CONTADOR_CULTIVOS = 1;
//static const char INIT_OBJETOS = ' ';
const char ESPINAS = 'E';

// Valores De ganar y perder
const int MONEDAS_PARA_PERDER    = 0;
const int MONEDAS_PARA_GANAR     = 1000;
const int PERDISTE               = -1;
const int GANASTE                = 1;
const int CONTINUA_JUGANDO       = 0;
const int MONEDAS_ESPINAS        = 5;
const int JUEGO_RECIEN_INICIADO  = 0;

//static const bool CULTIVO_OCUPADO    = true;
//static const bool CULTIVO_DESOCUPADO = false;

/*
 * Inicializará el juego, cargando toda la información inicial de las huertas, los obstáculos, las
    herramientas y el personaje.
 * El enanito corresponde al enanito obtenido en el TP1.
 */
void inicializar_juego(juego_t* juego, char enanito) {

    srand ((unsigned)time(NULL)); // genera la semilla que luego usará la funcion numero_random()

    /* Data de juego_t FALTA
        typedef struct juego {
            objeto_t objetos[MAX_OBJETOS]; FALTA
            int tope_objetos; FALTA
        } juego_t;
    */

    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        juego->huertas[i] = inicializar_huerta(*juego);
    }
    
    coordenada_t deposito;
    inicializar_deposito(&deposito, juego->huertas);
    juego->deposito = deposito;

    juego->movimientos = INIT_INT;

    objeto_t objetos[MAX_OBJETOS];
    juego->tope_objetos = INIT_INT;

    inicializar_objetos(objetos, &juego->tope_objetos, juego->huertas, juego->deposito);

    for (int i = INIT_INT; i < juego->tope_objetos; i++) {
        juego->objetos[i] = objetos[i];
    }

    personaje_t personaje;
    inicializar_personaje(&personaje, enanito, *juego);
    juego->jugador = personaje;

}

/* mejorar comentario
    Pre: recibe la poscicion del jugador y la lista de objetos
    Post: devuelve true si el jugador esta en una posicion de espinas
*/
bool jugador_en_espinas(coordenada_t posicion_jugador, objeto_t objetos[MAX_OBJETOS]){
    for (int i = INIT_INT; i < MAX_OBJETOS; i++) {
        if (objetos[i].tipo == ESPINAS && posicion_igual(posicion_jugador, objetos[i].posicion)) {
            return true;
        }
    }
    return false;
}


/* MEJORAR
    Pre:  recibe el juego (en forma de puntero para modificarlo)
    Post: si los movimientos del jugador son multiplos de 10, 15 o 20, crece los cultivos correspondientes
            (está mal, tiene que ser 10, 15 y 20 movimientos DESPUES de plantado)
*/
void crecer_cultivos(juego_t* juego){

    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        for (int j = INIT_INT; j < MAX_PLANTAS; j++) {

            if (juego->huertas[i].cultivos[j].movimiento_plantado != INIT_INT) {

                if(juego->huertas[i].cultivos[j].movimiento_plantado % MOVIMIENTOS_TOMATE == INIT_INT){
                    if (juego->huertas[i].cultivos[j].tipo == TOMATE)  {
                            juego->huertas[i].cultivos[j].tipo = TOMATE_CRECIDO;
                            juego->huertas[i].cultivos[j].movimiento_plantado = INIT_CONTADOR_CULTIVOS;
                    }
                }

                if(juego->huertas[i].cultivos[j].movimiento_plantado % MOVIMIENTOS_ZANAHORIA == INIT_INT){
                    if (juego->huertas[i].cultivos[j].tipo == ZANAHORIA)  {
                            juego->huertas[i].cultivos[j].tipo = ZANAHORIA_CRECIDA;
                            juego->huertas[i].cultivos[j].movimiento_plantado = INIT_CONTADOR_CULTIVOS;
                    }
                }

                if(juego->huertas[i].cultivos[j].movimiento_plantado % MOVIMIENTOS_BROCOLI == INIT_INT){
                    if(juego->huertas[i].cultivos[j].tipo == BROCOLI){
                        juego->huertas[i].cultivos[j].tipo = BROCOLI_CRECIDO; 
                        juego->huertas[i].cultivos[j].movimiento_plantado = INIT_CONTADOR_CULTIVOS;
                    }
                }
                
                if(juego->huertas[i].cultivos[j].movimiento_plantado % MOVIMIENTOS_LECHUGA == INIT_INT){
                    if(juego->huertas[i].cultivos[j].tipo == LECHUGA){
                        juego->huertas[i].cultivos[j].tipo = LECHUGA_CRECIDA;
                        juego->huertas[i].cultivos[j].movimiento_plantado = INIT_CONTADOR_CULTIVOS;
                    }
                }

            }

            juego->huertas[i].cultivos[j].movimiento_plantado++;  
        }    
        
    }
}

/* MEJORAR
    Pre:  recibe el juego (en forma de puntero para modificarlo)
    Post: acutaliza el terreno de juego, si están para crecer los cultivos, crecen, 
            si están para pudrirse, se pudren, etc
*/
 void actualizar_juego (juego_t* juego){

        crecer_cultivos(juego);

        /*if(se_pudre(juego))
            pudrir_cultivos(juego);

        if (hay_que_plagar(juego))
            plagar_cultivos(juego);

        if(hay_fertilizante(juego))
            generar_fertilizante(juego);*/
}

/* MEJORAR
    Pre:  recibe el juego (en forma de puntero para modificarlo)
    Post: si el jugador, al moverse, se encuentra en el deposito, se le lo deja en la posicion en la que estaba
            y se le resta un movimiento (para que no se quede en el deposito)
*/
void chequear_deposito(juego_t* juego, char accion){

    if(posicion_igual(juego->jugador.posicion, juego->deposito) && accion == ARRIBA){
        juego->jugador.posicion.fila++;
        juego->movimientos--;
    } else if(posicion_igual(juego->jugador.posicion, juego->deposito) && accion == ABAJO){
        juego->jugador.posicion.fila--;
        juego->movimientos--;
    } else if(posicion_igual(juego->jugador.posicion, juego->deposito) && accion == IZQUIERDA){
        juego->jugador.posicion.columna++;
        juego->movimientos--;
    } else if(posicion_igual(juego->jugador.posicion, juego->deposito) && accion == DERECHA){
        juego->jugador.posicion.columna--;
        juego->movimientos--;
    }
}


/* mejorar comentario REFACTORIZALO POR FAVOR
    Pre:  recibe el juego (en forma de puntero para modificarlo) y la accion a realizar (movimiento del jugador)
    Post: valida que el movimiento sea posible y lo realiza, tambien chequea si el jugador esta en una posicion de espinas
            en caso de estarlo le resta monedas (segun la constante MONEDAS_ESPINAS) al jugador
*/
void movimiento_jugador(juego_t* juego, char accion){

    if(accion == ARRIBA && juego->jugador.posicion.fila > MIN_MOVE_Y){
        juego->jugador.posicion.fila--;
        chequear_deposito(juego, accion);
    } else if(accion == ABAJO && juego->jugador.posicion.fila < MAX_MOVE_Y){
        juego->jugador.posicion.fila++;
        chequear_deposito(juego, accion);
    } else if(accion == IZQUIERDA && juego->jugador.posicion.columna > MIN_MOVE_X){
        juego->jugador.posicion.columna--;
        chequear_deposito(juego, accion);
    } else if(accion == DERECHA && juego->jugador.posicion.columna < MAX_MOVE_X){
        juego->jugador.posicion.columna++;
        chequear_deposito(juego, accion);
    }

    if (jugador_en_espinas(juego->jugador.posicion, juego->objetos))
        juego->jugador.cant_monedas -= MONEDAS_ESPINAS;
    
    if(juego->movimientos != JUEGO_RECIEN_INICIADO)
        actualizar_juego(juego);
         
}

/*
 * Realizará la acción recibida por parámetro. Puede ser un movimiento, con todas sus consecuencias, o sembrar, poner 
    insecticida o fertilizante.
 * La acción recibida deberá ser válida.
 */
void realizar_jugada(juego_t* juego, char accion){    
    switch (accion)
        {
        case TOMATE:
            comprar_cultivo(juego, TOMATE);
            break;
        case ZANAHORIA:
            comprar_cultivo(juego, ZANAHORIA);
            break;
        case BROCOLI:
            comprar_cultivo(juego, BROCOLI);
            break;
        case LECHUGA:
            comprar_cultivo(juego, LECHUGA); 
            break;
        case ARRIBA:
        case IZQUIERDA:
        case ABAJO:
        case DERECHA:
            movimiento_jugador(juego, accion);
            juego->movimientos++;
            break;
        default:
            break;
        }

}

/*
 * Imprime el juego por pantalla
 */
void imprimir_terreno(juego_t juego){

    char terreno[TAMAÑO_TERRENO][TAMAÑO_TERRENO];

    cargar_terreno(terreno, juego);

    for(int i = INIT_INT; i < TAMAÑO_TERRENO; i++){
        for (int j = INIT_INT; j < TAMAÑO_TERRENO; j++) {
            printf(" %c", terreno[i][j]);
        }
        printf("\n");
    }
}

/*
 * El juego se dará por ganado si se llega a 1000 monedas. Si Blancanieves se queda 
 * sin monedas, se considerará perdido.
 * Devuelve:
 * --> 1 si es ganado
 * --> -1 si es perdido
 * --> 0 si se sigue jugando
 */
int estado_juego(juego_t juego){
    if (juego.jugador.cant_monedas <= MONEDAS_PARA_PERDER) {
        return PERDISTE;
    } else if (juego.jugador.cant_monedas >= MONEDAS_PARA_GANAR) {
        return GANASTE;
    }
    return CONTINUA_JUGANDO;
}