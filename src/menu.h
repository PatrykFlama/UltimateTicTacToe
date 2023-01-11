#ifndef MENU
#define MENU

#include "template.h"
#include "ui.h"

enum MenuOptions{
    StartGame,
    ChangeColor,
};

typedef struct Menu{
    Ui *ui;
} Menu;

void Menu_init(Menu *menu, Ui *_ui);
bool Menu_loop(Menu *menu);
void Menu_print_options(Menu *menu);
enum MenuOptions Menu_get_option(Menu *menu);

void Menu_change_player_color(Menu *menu);

#endif
