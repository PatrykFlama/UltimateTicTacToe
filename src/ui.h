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
    White,

    Highlight1Clear,
    Highlight1Black,
    Highlight1Red,
    Highlight1Green,
    Highlight1Yellow,
    Highlight1Blue,
    Highlight1White,

    Highlight2Clear,
    Highlight2Black,
    Highlight2Red,
    Highlight2Green,
    Highlight2Yellow,
    Highlight2Blue,
    Highlight2White,

    Highlight3Clear,
    Highlight3Black,
    Highlight3Red,
    Highlight3Green,
    Highlight3Yellow,
    Highlight3Blue,
    Highlight3White,

    Highlight4Clear,
    Highlight4Black,
    Highlight4Red,
    Highlight4Green,
    Highlight4Yellow,
    Highlight4Blue,
    Highlight4White,
};
#define number_of_colors 7

static const char * const TerminalColorsNames[] = {
    [Clear] = "\033[0m",
    [Black] = "\033[0;30m",
    [Red] = "\033[0;31m",
    [Green] = "\033[0;32m",
    [Yellow] = "\033[0;33m",
    [Blue] = "\033[0;34m",
    [White] = "\033[0;37m",
};

typedef struct Ui{
    char ui_mode;       // t - terminal, g - gui
    enum TerminalColors color_x, color_o, color_empty, color_empty_active;
    int *active_board;
    bool fun;
} Ui;

void Ui_init(Ui *ui, char _ui_mode);
void Ui_init_colors();
void Ui_update(Ui *ui, BigBoard *board);
void Ui_end();

void Ui_clear(Ui *ui);
void Ui_draw(Ui *ui, BigBoard *board);
void Ui_draw_BigBoard(Ui *ui, BigBoard *board);
void Ui_draw_SmallBoard(Ui *ui, SmallBoard *board, int row);

void Ui_print_color_offset(char c, char mode, enum TerminalColors color, int color_offset);
#define Ui_print_color(c, mode, color) Ui_print_color_offset(c, mode, color, 0)
#define Ui_print(c, mode) Ui_print_color(c, mode, White)
void Ui_print_string_color(char *str, char mode, enum TerminalColors color);
#define Ui_print_string(str, mode) Ui_print_string_color(str, mode, White)
void Ui_print_terminal(char c, enum TerminalColors color);
void Ui_print_gui(char c, enum TerminalColors color);
char Ui_get_char(char mode);
int Ui_get_int(char mode);
void Ui_print_active_player(Ui *ui, char player);

#endif
