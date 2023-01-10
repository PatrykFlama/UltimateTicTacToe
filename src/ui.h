#ifndef UI
#define UI

#include "template.h"
#include "big_board.h"

enum TerminalColors{
    Clear = 0,
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Purple,
    Cyan,
    White,
};

static const char * const TerminalColorsNames[] = {
    [Clear] = "\033[0m",
    [Black] = "\033[0;30m",
    [Red] = "\033[0;31m",
    [Green] = "\033[0;32m",
    [Yellow] = "\033[0;33m",
    [Blue] = "\033[0;34m",
    [Purple] = "\033[0;35m",
    [Cyan] = "\033[0;36m",
    [White] = "\033[0;37m",
};

typedef struct Ui{
    char ui_mode;       // t - terminal, g - gui
} Ui;

void Ui_init(Ui *ui, char _ui_mode);
void Ui_update(Ui *ui, BigBoard *board);

void Ui_clear(char mode);
void Ui_draw(BigBoard *board, char mode);
void Ui_draw_BigBoard(BigBoard *board, char mode);
void Ui_draw_SmallBoard(SmallBoard *board, char mode, int line);

void Ui_print_color(char c, char mode, enum TerminalColors color);
#define Ui_print(c, mode) Ui_print_color(c, mode, White)
void Ui_print_string_color(char *str, char mode, enum TerminalColors color);
#define Ui_print_string(str, mode) Ui_print_string_color(str, mode, White)
void Ui_print_terminal(char c, enum TerminalColors color);
void Ui_print_gui(char c, enum TerminalColors color);

#endif
