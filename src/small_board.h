#include "template.h"

typedef struct SmallBoard{
    int board_size;
    char *tab;  //? convention: '.'-> empty, 'x' -> x, 'o' -> o
    char game_won;      // and who won
} SmallBoard;

void SmallBoard_init(SmallBoard *board, int board_size);
void SmallBoard_delete(SmallBoard *board);
bool SmallBoard_move_make(SmallBoard *board, int move, char player);
char SmallBoard_check_if_game_won(SmallBoard *board);
char SmallBoard_won(SmallBoard *board);