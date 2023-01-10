#ifndef UI
#define UI

#include "template.h"
#include "big_board.h"

typedef struct Ui{
    char ui_mode;       // t - terminal, g - gui
} Ui;

void Ui_init(Ui *ui, char _ui_mode);
void Ui_update(Ui *ui, BigBoard *board);

void Ui_clear(char mode);
void Ui_draw(BigBoard *board, char mode);
void Ui_draw_BigBoard(BigBoard *board, char mode);
void Ui_draw_SmallBoard(SmallBoard *board, char mode, int line);

void Ui_print(char c, char mode);
void Ui_print_string(char *str, char mode);
void Ui_print_terminal(char c);
void Ui_print_gui(char c);

#endif
