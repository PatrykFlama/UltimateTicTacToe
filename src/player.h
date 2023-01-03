#ifndef PLAYER
#define PLAYER

#include "template.h"
#include "move.h"

typedef struct Player{
    char input_type;      // t - terminal1, g - gui1, b - bot1
    char player_char;     // 'o' / 'x'
} Player;

void Player_init(Player *player, char _input_type, char _player_char);
void Player_get_move(Player *player, Move *move);
void Player_swap(char *player);

#endif
