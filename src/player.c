#include "template.h"
#include "move.h"
// #include "terminal_input.h"
// #include "gui_input.h"
// #incdlue "bot_input.h"
#include "player.h"

// typedef struct Player{
//     char input_type;      // t - terminal1, g - gui1, b - bot1
// } Player;

void Player_init(Player *player, char _input_type, char _player_char){
    player->input_type = _input_type;
    player->player_char = _player_char;
}

void Player_get_move(Player *player, Move *move){
    // TODO: get input from desired source
    if(player->input_type == 't'){
        scanf(" %d %d", move->board, move->cell);
    } else if(player->input_type == 'g'){
        // TODO gui input
    } else{
        // TODO bot input
    }

    move->is_empty = false;
}

void Player_swap(char *player){
    if(*player == 'o') *player = 'x';
    else *player = 'x'; 
}
