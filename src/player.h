#ifndef PLAYER
#define PLAYER

#include "template.h"
#include "move.h"

typedef struct Player{
    char input_type;      // t - terminal, g - gui, b - bot
    int board_size;
} Player;

void Player_init(Player *player, char _input_type, int _board_size);
Move Player_get_move(Player *player, int game_size);
void Player_swap(char *player);

#endif
