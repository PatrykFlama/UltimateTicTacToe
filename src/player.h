#include "template.h"
#include "move.h"
// #include "terminal_input.h"
// #include "gui_input.h"
// #incdlue "bot_input.h"

typedef struct Player{
    char type;      // t - terminal, g - gui, b - bot
} Player;

void Player_init(Player *player, char _type){
    player->type = _type;
}

void Player_move(Move *move, Player *player){
    // TODO: get input from desired source
    move->board = 1;
    move->cell = 1;
    move->is_empty = false;
}