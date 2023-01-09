#include "template.h"
#include "big_board.h"

// typedef struct BigBoard{
//     int board_size;
//     SmallBoard *tab;
//     char game_won;
//     int active_board;   // from 0 to board_size*board_size
// } BigBoard;

void BigBoard_init(BigBoard *board, int board_size){
    board->board_size = board_size;
    board->tab = malloc(board_size*board_size*sizeof(SmallBoard));

    FOR(board_size*board_size) SmallBoard_init(BigBoard_choose_SmallBoard(board, 0, i), board->board_size);

    board->game_won = '.';
}

SmallBoard *BigBoard_choose_SmallBoard(BigBoard *board, int row, int col){
    return &((board->tab)[row*board->board_size + col]);
}

void BigBoard_delete(BigBoard *board){
    FOR(board->board_size*board->board_size) SmallBoard_delete(BigBoard_choose_SmallBoard(board, 0, i));
    free(board->tab);
}

bool BigBoard_move_make(BigBoard *board, int which_board, int which_cell, char player){     // ture - move succeeded, false - desired cell is occupied
    if(which_board >= board->board_size*board->board_size) return false;
    return SmallBoard_move_make(BigBoard_choose_SmallBoard(board, 0, which_board), which_cell, player);
}

char BigBoard_check_if_game_won(BigBoard *board){        // and return who won
    FOR(row, board->board_size){        // check rows
        char player = BigBoard_choose_SmallBoard(board, row, 0)->game_won;
        if(player == '.') goto row_loop;

        FOR(col, 1, board->board_size){
            if(BigBoard_choose_SmallBoard(board, row, col)->game_won != player){
                goto row_loop;
            }
        }
        return player;
        row_loop:;
    }

    FOR(col, board->board_size){        // check cols
        char player = BigBoard_choose_SmallBoard(board, 0, col)->game_won;
        if(player == '.') goto col_loop;

        FOR(row, 1, board->board_size){
            if(BigBoard_choose_SmallBoard(board, row, col)->game_won != player){
                goto col_loop;
            }
        }
        return player;

        col_loop:;
    }

    char player = BigBoard_choose_SmallBoard(board, 0, 0)->game_won;        // check diagonals
    if(player == '.') goto next_step;
    FOR(i, 1, board->board_size){
        if(BigBoard_choose_SmallBoard(board, i, i)->game_won != player){
            goto next_step;
        }
    }
    return player;

    next_step:
    player = BigBoard_choose_SmallBoard(board, 0, board->board_size - 1)->game_won;
    if(player == '.') return '.';
    FOR(i, 1, board->board_size){
        if(BigBoard_choose_SmallBoard(board, i, -i)->game_won != player){
            return '.';
        }
    }
    return player;
}

char BigBoard_won(BigBoard *board){                     // check who won, save it and return it
    char player = BigBoard_check_if_game_won(board);
    board->game_won = player;
    return player;
}
