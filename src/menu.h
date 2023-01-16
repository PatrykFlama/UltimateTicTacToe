#ifndef MENU
#define MENU

#include "template.h"

typedef struct Menu{
    char menu_option;   // m - main, 
                        // g - change gamemode, 
                        // u - change ui mode
    bool debug;

    char ui_mode;
    int board_size;
    char player1, player2;
} Menu;

void Menu_init(Menu *menu, bool _debug);     // set default values

bool Menu_loop(Menu *menu);
void Menu_end(Menu *menu);

char Menu_get_option(char type);
void Menu_print(Menu *menu);
void Menu_action_menu(Menu *menu);
void Menu_action_change_gamemode(Menu *menu);
void Menu_action_change_ui(Menu *menu);
void Menu_action_change_board_size(Menu *menu);

#endif