#ifndef BIG_BOARD
#define BIG_BOARD

#include "template.h"
#include "small_board.h"

typedef struct BigBoard{
    int board_size;
    SmallBoard *tab;
    char game_won;
    int active_board;   // from 0 to board_size*board_size
} BigBoard;

void BigBoard_init(BigBoard *board, int board_size);
void BigBoard_delete(BigBoard *board);
char BigBoard_check_if_game_won(BigBoard *board);
char BigBoard_won(SmallBoard *board);
SmallBoard *BigBoard_choose_SmallBoard(BigBoard *board, int row, int col);

#endif
