#include "template.h"
#include "player.h"

// typedef struct Player{
//     char input_type;      // t - terminal1, g - gui1, b - bot1
// } Player;

void Player_init(Player *player, char _input_type){
    player->input_type = _input_type;
}

Move Player_get_move(Player *player, int game_size){
    Move move;
    if(player->input_type == 't'){
        int big_row, big_col, small_row, small_col;
        scanf(" %d %d %d %d", &big_row, &big_col, &small_row, &small_col);
        --big_row, --big_col, --small_row, --small_col;
        move.board = big_row*game_size + big_col;
        move.cell = small_row*game_size + small_col;
    } else if(player->input_type == 'g'){
        // TODO gui input
    } else{
        // TODO bot input
    }

    return move;
}

void Player_swap(char *player){
    if(*player == 'o') *player = 'x';
    else *player = 'o'; 
}
