#include "template.h"
#include "small_board.h"

// typedef struct SmallBoard{
//     int board_size;
//     char *tab;  //? convention: '.'-> empty, 'x' -> x, 'o' -> o
//     char game_won;      // and who won
// } SmallBoard;

void SmallBoard_init(SmallBoard *board, int board_size){
    board->board_size = board_size;
    board->tab = (char*)malloc(board_size*board_size*sizeof(char));
    FOR(board_size*board_size) *(board->tab + i) = '.';

    board->game_won = false;
}

void SmallBoard_delete(SmallBoard *board){
    free(board->tab);
}

bool SmallBoard_move_make(SmallBoard *board, int move, char player){       // true - move made; false - move is illegal
    if(*(board->tab + move) == '.'){
        *(board->tab + move) = player;
        return true;
    }
    return false;
}

char SmallBoard_check_if_game_won(SmallBoard *board){        // and return who won
    FOR(row, board->board_size){        // check rows
        char player = *(board->tab + row*board->board_size);
        FOR(col, 1, board->board_size){
            if(*(board->tab + row*board->board_size + col) != player){
                goto row_loop;
            }
        }
        return player;
        row_loop:;
    }

    FOR(col, board->board_size){        // check cols
        char player = *(board->tab + col);
        FOR(row, 1, board->board_size){
            if(*(board->tab + col + row*board->board_size) != player){
                goto col_loop;
            }
        }
        return player;

        col_loop:;
    }

    char player = *(board->tab);        // check diagonals
    FOR(i, 1, board->board_size){
        if(*(board->tab + i + i*board->board_size) != player){
            goto next_step;
        }
    }
    return player;

    next_step:
    player = *(board->tab + board->board_size - 1);
    FOR(i, 1, board->board_size){
        if(*(board->tab - i + i*board->board_size) != player){
            return '.';
        }
    }
    return player;
}

char SmallBoard_won(SmallBoard *board){                     // check who won, save it and return it
    char player = SmallBoard_check_if_game_won(board);
    board->game_won = player;
    return player;
}
