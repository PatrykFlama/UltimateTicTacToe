#include "template.h"
#include "small_board.h"
#include "big_board.h"

typedef struct BigBoard{
    int board_size;
    SmallBoard *tab;
    char game_won;
} BigBoard;

void BigBoard_init(BigBoard *board, int board_size){
    board->board_size = board_size;
    SmallBoard *tab = malloc(board_size*board_size*sizeof(SmallBoard));
    // board->tab = malloc(board_size*board_size*sizeof(SmallBoard));
    // FOR(board_size*board_size) *(board->tab + i) = '.';

    board->game_won = false;
}

void BigBoard_delete(BigBoard *board){
    free(board->tab);
}
