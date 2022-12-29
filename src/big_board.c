#include "template.h"
#include "small_board.h"
#include "big_board.h"

// typedef struct BigBoard{
//     int board_size;
//     SmallBoard *tab;
//     char game_won;
//     int active_board;   // from 0 to board_size*board_size
// } BigBoard;

void BigBoard_init(BigBoard *board, int board_size){
    board->board_size = board_size;
    // TODO: dynamically allocate SmallBoard tab memory
    // board->tab = malloc(board_size*board_size*sizeof(SmallBoard));
    // https://stackoverflow.com/questions/19613752/how-to-properly-malloc-for-array-of-struct-in-c
    board->tab = (SmallBoard*)malloc(board_size*board_size*sizeof(SmallBoard));

    FOR(board_size*board_size) SmallBoard_init((board->tab + i * sizeof(SmallBoard)), board->board_size);

    board->game_won = '.';
}

void BigBoard_delete(BigBoard *board){
    FOR(board->board_size*board->board_size) SmallBoard_delete((board->tab + i * sizeof(SmallBoard)));
    free(board->tab);
}

bool BigBoard_move_make(BigBoard *board, int which_board, int which_cell, char player){     // ture - move succeeded, false - desired cell is occupied
    return SmallBoard_move_make((board->tab + which_board*sizeof(SmallBoard)), which_cell, player);
}

char BigBoard_check_if_game_won(BigBoard *board){        // and return who won
    FOR(row, board->board_size){        // check rows
        char player = (board->tab + row*board->board_size)->game_won;
        if(player == '.') goto row_loop;

        FOR(col, 1, board->board_size){
            if((board->tab + row*board->board_size + col)->game_won != player){
                goto row_loop;
            }
        }
        return player;
        row_loop:;
    }

    FOR(col, board->board_size){        // check cols
        char player = (board->tab + col)->game_won;
        if(player == '.') goto col_loop;

        FOR(row, 1, board->board_size){
            if((board->tab + col + row*board->board_size)->game_won != player){
                goto col_loop;
            }
        }
        return player;

        col_loop:;
    }

    char player = (board->tab)->game_won;        // check diagonals
    if(player == '.') goto next_step;
    FOR(i, 1, board->board_size){
        if((board->tab + i + i*board->board_size)->game_won != player){
            goto next_step;
        }
    }
    return player;

    next_step:
    player = (board->tab + board->board_size - 1)->game_won;
    if(player == '.') return '.';
    FOR(i, 1, board->board_size){
        if((board->tab - i + i*board->board_size)->game_won != player){
            return '.';
        }
    }
    return player;
}

char BigBoard_won(SmallBoard *board){                     // check who won, save it and return it
    char player = BigBoard_check_if_game_won(board);
    board->game_won = player;
    return player;
}
