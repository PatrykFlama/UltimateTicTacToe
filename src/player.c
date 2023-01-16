#include "player.h"

// typedef struct Player{
//     char input_type;      // t - terminal1, g - gui1, b - bot1
// } Player;

void Player_init(Player *player, BigBoard *_board, char _input_type){
    player->input_type = _input_type;
    player->board = _board;
    srand(time(NULL));
}

Move Player_get_move(Player *player, int game_size){
    Move move;
    if(player->input_type == 't'){
        int big_row, big_col, small_row, small_col;
        if(scanf(" %d %d %d %d", &big_row, &big_col, &small_row, &small_col) != 4) goto player_wrong_move;
        --big_row, --big_col, --small_row, --small_col;
        move.board = big_row*game_size + big_col;
        move.cell = small_row*game_size + small_col;
    } else if(player->input_type == 'g'){
        // TODO gui input
    } else{
        // TODO bot input
        int board_size = player->board->board_size;
        int active_boards[board_size*board_size];
        int ptr = 0;

        if(BigBoard_choose_SmallBoard(player->board, 0, *player->board->active_board)->game_won != '.'){
            FOR(boards, board_size*board_size){
                if(BigBoard_choose_SmallBoard(player->board, 0, boards)->game_won == '.'){
                    active_boards[ptr++] = boards;
                }
            }

            move.board = active_boards[rand() % ptr];
        } else{
            move.board = *player->board->active_board;
        }

        ptr = 0;
        FOR(cells, board_size*board_size){
            if(BigBoard_choose_SmallBoard(player->board, 0, move.board)->tab[cells] == '.'){
                active_boards[ptr++] = cells;
            }
        }

        move.cell = active_boards[rand() % ptr];
    }

    return move;

    player_wrong_move:
    move.board = -1, move.cell = -1;

    char temp = 'w';    // flush line
    if(player->input_type == 't') while(temp != '\n') temp = getchar();
    
    return move;
}

void Player_swap(char *player){
    if(*player == 'o') *player = 'x';
    else *player = 'o'; 
}
