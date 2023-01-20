#ifndef PLAYER
#define PLAYER

#include "template.h"
#include "move.h"
#include "big_board.h"
#include "ui.h"

typedef struct Player{
    char input_type, char_;      // t - terminal, g - gui, b - bot
    BigBoard *board;
} Player;

void Player_init(Player *player, BigBoard *_board, char _input_type, char _char_);
Move Player_get_move(Player *player, BigBoard *board, Ui *ui);
void Player_swap(char *player);
bool Player_get_move_board_gui(Player *player, BigBoard *board, Move *move, Ui *ui);
bool Player_get_move_cell_gui(Player *player, BigBoard *big_board, SmallBoard *board, Move *move, Ui *ui);
void Player_set_highlight_board(Move *move, BigBoard *board, int val);
void Player_set_highlight_cell(Move *move, SmallBoard *board, int val);

#endif
