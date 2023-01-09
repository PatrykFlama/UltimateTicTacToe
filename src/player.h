#ifndef PLAYER
#define PLAYER

#include "template.h"
#include "move.h"

typedef struct Player{
    char input_type;      // t - terminal1, g - gui1, b - bot1
} Player;

void Player_init(Player *player, char _input_type);
Move Player_get_move(Player *player, int game_size);
void Player_swap(char *player);

#endif
