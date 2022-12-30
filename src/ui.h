#ifndef UI
#define UI

#include "template.h"
#include "game.h"

typedef struct Ui{
    char ui_mode;       // t - terminal, g - gui
} Ui;

void Ui_init(Ui *ui, char _ui_mode);
void Ui_update(Ui *ui, Game *game);
void Ui_draw_BigBoard(BigBoard *board);
void Ui_draw_SmallBoard(SmallBoard *board);
void Ui_draw_terminal(Game *game);
void Ui_draw_gui(Game *game);

#endif
