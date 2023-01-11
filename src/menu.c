#include "menu.h"

void Menu_init(Menu *menu, Ui *_ui){
    menu->ui = _ui;
}

bool Menu_loop(Menu *menu){
    Menu_print_options(menu);
    enum MenuOptions option = Menu_get_option(menu);

    switch (option){
        case StartGame:
            return true;
            break;
        case ChangeColor:
            Menu_change_player_color(menu);
            break;
    }
}

void Menu_print_options(Menu *menu){

}

enum MenuOptions Menu_get_option(Menu *menu){

}


void Menu_change_player_color(Menu *menu){
    enum TerminalColors color;  // TODO get colors
    char player = 'o';          // TODO get player

    if(player == 'o'){
        menu->ui->color_o = color;
    } else{
        menu->ui->color_x = color;
    }
}
