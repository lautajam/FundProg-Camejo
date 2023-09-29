#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> // Para usar rand
#include <time.h>   // Para obtener una semilla desde el reloj

// Constants, definitions, structs and matrices
#define MAP_SIZE  20
#define UP       'w' 
#define LEFT     'a'
#define DOWN     's'
#define RIGHT    'd'

const char EMPTY_SPACES      = '-';
const char PLAYER_BODY_STYLE = 'S';
const char COIN              = 'C';
const char EXIT              = 'x';

const int MIN_MOVE_X = 0;
const int MAX_MOVE_X = MAP_SIZE - 1;
const int MIN_MOVE_Y = 0;
const int MAX_MOVE_Y = MAP_SIZE - 1;

const int MAX_POINTS = 5;
const int MOVES_NEW_OBSTACLE = 10;

const int PLAYER_X_INIT = 0;
const int PLAYER_Y_INIT = 0;

const int  INIT_INT = 0;
const char INIT_CHAR = ' '; 

char map[MAP_SIZE][MAP_SIZE];
 
typedef struct player {
    char body;
    int x;
    int y;
} player_t;

typedef struct coin {
    int x;
    int y;
} coin_t;

/*
    (It's like a Class Constructor in Java, but in C and for a Struct)
    Pre: player is not null, body is a valid body style int, x and y are valid coordinates int
    Post: player is initialized with the given values (pos(x,y) and body style)
*/
void player_constructor(player_t *player, char body, int x, int y) {
    player->body = body;
    player->x = x;
    player->y = y;
}

/*
    Pre: map is a valid 2D array of int
    Post: map is filled with 0s (empty spaces)
*/
void fill_start_mape(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) { // y
        for (int j = 0; j < MAP_SIZE; j++) { // x
            map[i][j] = EMPTY_SPACES;
        }
    }
}

/*
    Pre: min and max are valid int
    Post: returns a random int between min and max
*/
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/*
    Pre: coin is valid coin, player is a valid player_t
    Post: x and y are filled with a valid position for an coin
*/
void generate_position_coin(coin_t *coin, player_t player, int moveCount) {
    if (moveCount % MOVES_NEW_OBSTACLE == 0 && moveCount != 0)
    {
        do {
            coin->x = random_number(MIN_MOVE_X, MAX_MOVE_X);
            coin->y = random_number(MIN_MOVE_Y, MAX_MOVE_Y);
        } while (coin->x == player.x && coin->y == player.y);
    }
    
}

/*
    Pre: map is a valid 2D array of int, player is a valid player_t
    Post: map is printed with the player in the given position
*/
void draw_map(char map[MAP_SIZE][MAP_SIZE], player_t player, int moveCount, coin_t* coin) {

    for (int i = INIT_INT; i < MAP_SIZE; i++) { // y
        for (int j = INIT_INT; j < MAP_SIZE; j++) { // x
            if (i == player.y && j == player.x) {
                printf(" %c", player.body);
            }
            else if (i == coin->y && j == coin->x && moveCount % MOVES_NEW_OBSTACLE == 0 && moveCount != 0) {
                printf(" %c", COIN);
            } else {
                printf(" %c", map[i][j]);
            }
        }
        printf("\n");
    }
}

/*
    Pre: player y coin son punteros a estructuras válidas, points es un puntero a int válido
    Post: Si player está en la misma posición que coin, points se incrementa en 1
*/
void check_coin(player_t player, coin_t *coin, int *points) {
    printf("Player: (%d, %d) | Coin: (%d, %d)", player.x, player.y, coin->x, coin->y);
    if (player.x == coin->x && player.y == coin->y) {
        (*points)++;
        printf(" Points: %d\n", *points);
        generate_position_coin(&coin, player, INIT_INT);
    }
}

int main() {

    system("clear");
    fill_start_mape(map);
    player_t player;
    player_constructor(&player, PLAYER_BODY_STYLE, PLAYER_X_INIT, PLAYER_Y_INIT);

    coin_t coin;

    char input     = INIT_CHAR;
    int  moveCount = INIT_INT;
    int  points    = INIT_INT;

    draw_map(map, player, moveCount, &coin);
    printf(" Moves: %d | Points: %d\n", moveCount, points);

    // JUEGO
    while (input != EXIT) {

        generate_position_coin(&coin, player, moveCount);

        check_coin(player, &coin, &points);

        scanf("%c", &input);
        system("clear");

        switch (input)
        {
        case UP:
            if (player.y > MIN_MOVE_Y){
                player.y--;
                moveCount++;
            } break;
        case LEFT:
            if (player.x > MIN_MOVE_X){
                player.x--;
                moveCount++;
            } break;
        case DOWN:
            if (player.y < MAX_MOVE_Y){
                player.y++;
                moveCount++;
            } break;
        case RIGHT:
            if (player.x < MAX_MOVE_X){
                player.x++;
                moveCount++;
            } break;
        }


        draw_map(map, player, moveCount, &coin);

        printf(" Moves: %d | Points: %d\n", moveCount, points);
        if (input == 'x') printf(" Exit\n");
    }

    return 0;
}