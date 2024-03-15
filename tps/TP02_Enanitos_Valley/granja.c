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

const int MONEDAS_TOMATE_VENTA    = 30;
const int MONEDAS_ZANAHORIA_VENTA = 50;
const int MONEDAS_BROCLI_VENTA    = 70;
const int MONEDAS_LECHUGA_VENTA   = 80;
<<<<<<< HEAD
=======

const int MAX_CANASTA_REAL = MAX_CANASTA - 4;
const int DISTANCIA_MANHATTAN_DEPOSITO = 2;
>>>>>>> 33e3a445ac419e45e1081f20e1446ca49f2ef083

const int MAX_CANASTA_REAL = MAX_CANASTA - 4;
const int DISTANCIA_MANHATTAN_DEPOSITO = 2;

const int MOVIMIENTOS_TOMATE_CRECER    = 20;
const int MOVIMIENTOS_ZANAHORIA_CRECER = 15;
const int MOVIMIENTOS_BROCOLI_CRECER   = 10;
const int MOVIMIENTOS_LECHUGA_CRECER   = 10;

const int MOVIMIENTOS_TOMATE_PUDRIR    = 10; 
const int MOVIMIENTOS_ZANAHORIA_PUDRIR = 10;
const int MOVIMIENTOS_BROCOLI_PUDRIR   = 10;
const int MOVIMIENTOS_LECHUGA_PUDRIR   = 5;

const int MOVIMIENTOS_VIDA_TOMATE    = MOVIMIENTOS_TOMATE_CRECER    + MOVIMIENTOS_TOMATE_PUDRIR;
const int MOVIMIENTOS_VIDA_ZANAHORIA = MOVIMIENTOS_ZANAHORIA_CRECER + MOVIMIENTOS_ZANAHORIA_PUDRIR;
const int MOVIMIENTOS_VIDA_BROCOLI   = MOVIMIENTOS_BROCOLI_CRECER   + MOVIMIENTOS_BROCOLI_PUDRIR;
const int MOVIMIENTOS_VIDA_LECHUGA   = MOVIMIENTOS_LECHUGA_CRECER   + MOVIMIENTOS_LECHUGA_PUDRIR;

// Valores iniciales de los atributos
static const int INIT_INT               = 0;
static const int INIT_CONTADOR_CULTIVOS = 1;
<<<<<<< HEAD
const char ESPINAS              = 'E';
const char SIN_CULTIVO          = ' ';
static const char CULTIVO_VACIO = 'C';
static const bool CULTIVO_DESOCUPADO = false;
=======
//static const char INIT_OBJETOS = ' ';
const char ESPINAS = 'E';
const char SIN_CULTIVO = ' ';
>>>>>>> 33e3a445ac419e45e1081f20e1446ca49f2ef083

// Valores De ganar y perder
const int MONEDAS_PARA_PERDER    = 0;
const int MONEDAS_PARA_GANAR     = 1000;
const int PERDISTE               = -1;
const int GANASTE                = 1;
const int CONTINUA_JUGANDO       = 0;
const int MONEDAS_ESPINAS        = 5;
const int JUEGO_RECIEN_INICIADO  = 0;

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

/*
    Pre: se le pasa el cultivo (en forma de puntero para modificarlo)
    Post: si el cultivo es un TOMATE y está para CRECER (ya pasaron los movimientos necesarios), crece:
            se le cambia el tipo a TOMATE_CRECIDO y se le resta un movimiento plantado
*/
void crecer_tomate(cultivo_t* cultivo){
    if (cultivo->movimiento_plantado == MOVIMIENTOS_TOMATE_CRECER) {
        if (cultivo->tipo == TOMATE)  {
            cultivo->tipo = TOMATE_CRECIDO;
            cultivo->movimiento_plantado--;  
        }
    }
}

/*
    Pre: se le pasa el cultivo (en forma de puntero para modificarlo)
    Post: si el cultivo es una ZANAHORIA y está para CRECER (ya pasaron los movimientos necesarios), crece:
            se le cambia el tipo a ZANAHORIA_CRECIDO y se le resta un movimiento plantado
*/
void crecer_zanahoria(cultivo_t* cultivo){
    if (cultivo->movimiento_plantado == MOVIMIENTOS_ZANAHORIA_CRECER) {
        if (cultivo->tipo == ZANAHORIA)  {
            cultivo->tipo = ZANAHORIA_CRECIDA;
            cultivo->movimiento_plantado--;  
        }
    }
}

/*
    Pre: se le pasa el cultivo (en forma de puntero para modificarlo)
    Post: si el cultivo es un BROCOLI y está para CRECER (ya pasaron los movimientos necesarios), crece:
            se le cambia el tipo a BROCOLI_CRECIDO y se le resta un movimiento plantado
*/
void crecer_brocoli(cultivo_t* cultivo){
    if (cultivo->movimiento_plantado == MOVIMIENTOS_BROCOLI_CRECER) {
        if (cultivo->tipo == BROCOLI)  {
            cultivo->tipo = BROCOLI_CRECIDO;
            cultivo->movimiento_plantado--;  
        }
    }
}

/*
    Pre: se le pasa el cultivo (en forma de puntero para modificarlo)
    Post: si el cultivo es una LECHUGA y está para CRECER (ya pasaron los movimientos necesarios), crece:
            se le cambia el tipo a LECHUGA_CRECIDO y se le resta un movimiento plantado
*/
void crecer_lechuga(cultivo_t* cultivo){
    if (cultivo->movimiento_plantado == MOVIMIENTOS_LECHUGA_CRECER) {
        if (cultivo->tipo == LECHUGA)  {
            cultivo->tipo = LECHUGA_CRECIDA;
            cultivo->movimiento_plantado--;  
        }
    }
}

/*
    Pre:  recibe el juego (en forma de puntero para modificarlo)
    Post: se recorren los cultivos verificando si están para crecer, si lo están, crecen, llamando al metodo
            correspondiente a cada cultivo
*/
void crecer_cultivos(juego_t* juego){

    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        for (int j = INIT_INT; j < MAX_PLANTAS; j++) {

            crecer_tomate(&juego->huertas[i].cultivos[j]);

            crecer_zanahoria(&juego->huertas[i].cultivos[j]);

            crecer_brocoli(&juego->huertas[i].cultivos[j]);
            
            crecer_lechuga(&juego->huertas[i].cultivos[j]);

           juego->huertas[i].cultivos[j].movimiento_plantado++;  
        }    
    }
}

/*
    Pre: se le pasa el cultivo (en forma de puntero para modificarlo)
    Post: si el cultivo es un TOMATE y está para pudrirse (ya pasaron los movimientos necesarios), se pudre:
            se le cambia el tipo a CULTIVO_VACIO, se reinicia el contador de movimientos plantados y se le cambia
            el estado de ocupado a CULTIVO_DESOCUPADO
*/
void pudrir_tomate(cultivo_t* cultivo){
    if (cultivo->movimiento_plantado == MOVIMIENTOS_VIDA_TOMATE) {
        if (cultivo->tipo == TOMATE_CRECIDO)  {
            cultivo->tipo = CULTIVO_VACIO;
            cultivo->movimiento_plantado = INIT_CONTADOR_CULTIVOS;
            cultivo->ocupado = CULTIVO_DESOCUPADO;
        }
    }
}

/*
    Pre: se le pasa el cultivo (en forma de puntero para modificarlo)
    Post: si el cultivo es una ZANAHORIA y está para pudrirse (ya pasaron los movimientos necesarios), se pudre:
            se le cambia el tipo a CULTIVO_VACIO, se reinicia el contador de movimientos plantados y se le cambia
            el estado de ocupado a CULTIVO_DESOCUPADO
*/
void pudrir_zanahoria(cultivo_t* cultivo){
    if (cultivo->movimiento_plantado == MOVIMIENTOS_VIDA_ZANAHORIA) {
        if (cultivo->tipo == ZANAHORIA_CRECIDA)  {
            cultivo->tipo = CULTIVO_VACIO;
            cultivo->movimiento_plantado = INIT_CONTADOR_CULTIVOS;
            cultivo->ocupado = CULTIVO_DESOCUPADO;
        }
    }
}

/*
    Pre: se le pasa el cultivo (en forma de puntero para modificarlo)
    Post: si el cultivo es un BROCOLI y está para pudrirse (ya pasaron los movimientos necesarios), se pudre:
            se le cambia el tipo a CULTIVO_VACIO, se reinicia el contador de movimientos plantados y se le cambia
            el estado de ocupado a CULTIVO_DESOCUPADO
*/
void pudrir_brocoli(cultivo_t* cultivo){
    if (cultivo->movimiento_plantado == MOVIMIENTOS_VIDA_BROCOLI) {
        if (cultivo->tipo == BROCOLI_CRECIDO)  {
            cultivo->tipo = CULTIVO_VACIO;
            cultivo->movimiento_plantado = INIT_CONTADOR_CULTIVOS;
            cultivo->ocupado = CULTIVO_DESOCUPADO;
        }
    }
}

/*
    Pre: se le pasa el cultivo (en forma de puntero para modificarlo)
    Post: si el cultivo es una LECHUGA y está para pudrirse (ya pasaron los movimientos necesarios), se pudre:
            se le cambia el tipo a CULTIVO_VACIO, se reinicia el contador de movimientos plantados y se le cambia
            el estado de ocupado a CULTIVO_DESOCUPADO
*/
void pudrir_lechuga(cultivo_t* cultivo){
    if (cultivo->movimiento_plantado == MOVIMIENTOS_VIDA_LECHUGA) {
        if (cultivo->tipo == LECHUGA_CRECIDA)  {
            cultivo->tipo = CULTIVO_VACIO;
            cultivo->movimiento_plantado = INIT_CONTADOR_CULTIVOS;
            cultivo->ocupado = CULTIVO_DESOCUPADO;
        }
    }
}

/*
    Pre:  recibe el juego (en forma de puntero para modificarlo)
    Post: se recorren los cultivos verificando si están para pudrirse, si lo están, se pudren, llamando al metodo
            correspondiente a cada cultivo
*/
void pudrir_cultivos(juego_t* juego){

    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        for (int j = INIT_INT; j < MAX_PLANTAS; j++) {

            pudrir_tomate(&juego->huertas[i].cultivos[j]);

            pudrir_zanahoria(&juego->huertas[i].cultivos[j]);

            pudrir_brocoli(&juego->huertas[i].cultivos[j]);
            
            pudrir_lechuga(&juego->huertas[i].cultivos[j]);


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

        pudrir_cultivos(juego);

        /*if (hay_que_plagar(juego))
            plagar_cultivos(juego);

        if(hay_fertilizante(juego))
            generar_fertilizante(juego);*/
}

/* MEJORAR
    Pre:  recibe el juego (en forma de puntero para modificarlo)
    Post: si el jugador, al moverse, se encuentra en el deposito, se le lo deja en la posicion en la que estaba
            y se le resta un movimiento (para que no se quede en el deposito)
*/
/*
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
*/

/*
    * Pre:  recibe el tipo de cultivo
    * Post: devuelve true si el cultivo está crecido o false si no lo está
*/
bool cultivo_crecido(char tipo){
    return  tipo == TOMATE_CRECIDO || 
            tipo == ZANAHORIA_CRECIDA || 
            tipo == BROCOLI_CRECIDO || 
            tipo == LECHUGA_CRECIDA;
}

/*
    * Pre:  recibe el jugador y la lista de huertas
    * Post: devuelve true si el jugador está en una posición de un cultivo crecido o false si no lo está
*/
bool personaje_en_cultivo_crecido(personaje_t jugador, huerta_t huertas[MAX_HUERTA]){
    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        for (int j = INIT_INT; j < MAX_PLANTAS; j++) {
            if (cultivo_crecido(huertas[i].cultivos[j].tipo) 
                && posicion_igual(jugador.posicion, huertas[i].cultivos[j].posicion)) {
                return true;
            }
        }
    }
    return false;
}

/*
    * Pre:  recibe el tope canasta
    * Post: devuelve true si la canasta esta llena o false si no lo esta
*/
bool canasta_llena(int tope_canasta) {
    return tope_canasta == MAX_CANASTA_REAL;
}

/*
    * Pre:  recibe el tope canasta
    * Post: devuelve true si la canasta esta vacia o false si lo está
*/
bool canasta_vacia(int tope_canasta) {
    return tope_canasta == INIT_INT;
}

/*
    Pre:  recibira el juego (en forma de puntero para modificarlo)
    Post: Si el cultivo está crecido y la posicion del jugador es igual a la del cultivo crecido
          cosechará el cultivo y lo guardará en la canasta, reiniciando el movimiento plantado, el tipo del cultivo
            y el estado de ocupado del cultivo
*/
void cosechar_cultivo(juego_t* juego){
    for (int i = INIT_INT; i < MAX_HUERTA; i++) {
        for (int j = INIT_INT; j < MAX_PLANTAS; j++) {
            if (cultivo_crecido(juego->huertas[i].cultivos[j].tipo) 
                && posicion_igual(juego->jugador.posicion, juego->huertas[i].cultivos[j].posicion)) {
                juego->jugador.canasta[juego->jugador.tope_canasta] = juego->huertas[i].cultivos[j].tipo;
                juego->huertas[i].cultivos[j].movimiento_plantado = INIT_INT;
                juego->huertas[i].cultivos[j].ocupado = false;
                juego->huertas[i].cultivos[j].tipo = 'C';
            }
        }
    }
}

/*
    Pre:  recibe las coordenadas del jugador y del deposito
    Post: devuelve la distancia manhattan entre el jugador y el deposito
*/
int distancia_vender_cultivo(coordenada_t posicion_jugador, coordenada_t posicion_deposito){
    return abs(posicion_deposito.fila - posicion_jugador.fila ) + abs(posicion_deposito.columna - posicion_jugador.columna );
}

/*
    Pre:  recibe el juego (en forma de puntero para modificarlo)
    Post: vende los cultivos de la canasta, la vacìa y suma las monedas correspondientes al jugador
*/
void vender_cultivo(juego_t* juego){
    for (int i = INIT_INT; i < juego->jugador.tope_canasta; i++) {
        switch (juego->jugador.canasta[i])
        {
        case TOMATE_CRECIDO:
            juego->jugador.cant_monedas += MONEDAS_TOMATE_VENTA;
            break;
        case ZANAHORIA_CRECIDA:
            juego->jugador.cant_monedas += MONEDAS_ZANAHORIA_VENTA;
            break;
        case BROCOLI_CRECIDO:
            juego->jugador.cant_monedas += MONEDAS_BROCLI_VENTA;
            break;
        case LECHUGA_CRECIDA:
            juego->jugador.cant_monedas += MONEDAS_LECHUGA_VENTA;
            break;
        default:
            break;
        }
        juego->jugador.canasta[i] = SIN_CULTIVO;
    }
    juego->jugador.tope_canasta = INIT_INT;

}

/*  MEJORAR
    Pre:  recibe el juego (en forma de puntero para modificarlo) y la accion realizada
    Post: si el jugador esta en los limites del terreno y realiza un movimiento hacia el limite
            se le resta un movimiento para quedar en el lugar y no salirse del terreno
*/
void chequear_limite(juego_t* juego, char accion) {
    if (accion == ARRIBA && juego->jugador.posicion.fila == MIN_MOVE_Y) {
        juego->movimientos--;
    } else if (accion == ABAJO && juego->jugador.posicion.fila == MAX_MOVE_Y) {
        juego->movimientos--;
    } else if (accion == IZQUIERDA && juego->jugador.posicion.columna == MIN_MOVE_X) {
        juego->movimientos--;
    } else if (accion == DERECHA && juego->jugador.posicion.columna == MAX_MOVE_X) {
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
    } else if(accion == ABAJO && juego->jugador.posicion.fila < MAX_MOVE_Y){
        juego->jugador.posicion.fila++;
    } else if(accion == IZQUIERDA && juego->jugador.posicion.columna > MIN_MOVE_X ){
        juego->jugador.posicion.columna--;
    } else if(accion == DERECHA && juego->jugador.posicion.columna < MAX_MOVE_X ){
        juego->jugador.posicion.columna++;
    }

<<<<<<< HEAD
    //chequear_deposito(juego, accion);
=======
    chequear_deposito(juego, accion);
>>>>>>> 33e3a445ac419e45e1081f20e1446ca49f2ef083

    chequear_limite(juego, accion);

    if (jugador_en_espinas(juego->jugador.posicion, juego->objetos))
        juego->jugador.cant_monedas -= MONEDAS_ESPINAS;
    
    if(juego->movimientos != JUEGO_RECIEN_INICIADO)
        actualizar_juego(juego);

    if(personaje_en_cultivo_crecido(juego->jugador, juego->huertas) && !canasta_llena(juego->jugador.tope_canasta)){
        cosechar_cultivo(juego);
        juego->jugador.tope_canasta++;
    }

    if(distancia_vender_cultivo(juego->jugador.posicion, juego->deposito) <= DISTANCIA_MANHATTAN_DEPOSITO)
        vender_cultivo(juego);
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

    imprimir_interfaz(juego);
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