#ifndef BIG_BOARD
#define BIG_BOARD

#include "template.h"
#include "small_board.h"
#include "move.h"

typedef struct BigBoard{
    int board_size;
    SmallBoard *tab;
    char game_won;
    int active_board;   // from 0 to board_size*board_size
} BigBoard;

void BigBoard_init(BigBoard *board, SmallBoard *_tab, int board_size);
void BigBoard_delete(BigBoard *board);
char BigBoard_check_if_game_won(BigBoard *board);
char BigBoard_won(BigBoard *board);
bool BigBoard_move_make(BigBoard *board, int which_board, int which_cell, char player, Move last_move);
SmallBoard *BigBoard_choose_SmallBoard(BigBoard *board, int row, int col);

#endif
