#ifndef PLAYER
#define PLAYER

#include "template.h"
#include "move.h"
#include "big_board.h"

typedef struct Player{
    char input_type;      // t - terminal, g - gui, b - bot
    BigBoard *board;
} Player;

void Player_init(Player *player, BigBoard *_board, char _input_type);
Move Player_get_move(Player *player, int game_size);
void Player_swap(char *player);

#endif
