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
    Pre: map is a valid 2D array of int, player is a valid player_t
    Post: map is printed with the player in the given position
*/
void draw_map(char map[MAP_SIZE][MAP_SIZE], player_t player, int moveCount) {

    for (int i = INIT_INT; i < MAP_SIZE; i++) { // y
        for (int j = INIT_INT; j < MAP_SIZE; j++) { // x
            if (i == player.y && j == player.x) {
                printf(" %c", player.body);
            }
            else {
                printf(" %c", map[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {

    system("clear");
    fill_start_mape(map);
    player_t player;
    player_constructor(&player, PLAYER_BODY_STYLE, PLAYER_X_INIT, PLAYER_Y_INIT);

    char input     = INIT_CHAR;
    int  moveCount = INIT_INT;

    draw_map(map, player, moveCount);
    printf(" Moves: %d\n", moveCount);

    // JUEGO
    while (input != EXIT) {

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

        draw_map(map, player, moveCount);

        printf(" Moves: %d\n", moveCount);
        if (input == 'x') printf(" Exit\n");
    }

    return 0;
}