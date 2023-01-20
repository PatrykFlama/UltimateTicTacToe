#ifndef MENU
#define MENU

#include "template.h"
#include "ui.h"

typedef struct Menu{
    Ui *ui;
    char menu_option;   // m - main, 
                        // g - change gamemode, 
                        // u - change ui mode
    bool fun;

    int board_size;
    char player1, player2;
} Menu;

void Menu_init(Menu *menu, Ui* _ui, bool _fun);     // set default values

bool Menu_loop(Menu *menu);
void Menu_end(Menu *menu, char ui_mode);

char Menu_get_option(Menu *menu, char type);
void Menu_print(Menu *menu);
void Menu_action_menu(Menu *menu);
void Menu_action_change_gamemode(Menu *menu);
void Menu_action_change_board_size(Menu *menu);
void Menu_action_help_page(Menu *menu);

#endif