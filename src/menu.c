#include "menu.h"

void Menu_init(Menu *menu, Ui* _ui, bool _debug){
    menu->ui = _ui;
    menu->debug = _debug;
    menu->menu_option = 'm';

    menu->board_size = 3;
    menu->player1 = 't';
    menu->player2 = 't';
}

bool Menu_loop(Menu *menu){
    Menu_print(menu);

    if(menu->menu_option == 'm'){
        menu->menu_option = Menu_get_option(menu, 'c');
    } else if(menu->menu_option == 'g'){
        Menu_action_change_gamemode(menu);
        menu->menu_option = 'm';
    } else if(menu->menu_option == 'b'){
        Menu_action_change_board_size(menu);
        menu->menu_option = 'm';
    } else if(menu->menu_option == 'h'){
        Menu_action_help_page(menu);
        menu->menu_option = 'm';
    } else {
        return true;
    }

    return false;
}

char Menu_get_option(Menu *menu, char type){
    if(type == 'c'){        // get char
        return Ui_get_char(menu->ui->ui_mode);
    } else if(type == 'i'){ // get int
        return Ui_get_int(menu->ui->ui_mode);
    }
}

void Menu_print(Menu *menu){
    if(!menu->debug) Ui_clear(menu->ui);

    if(menu->menu_option == 'm'){
        Ui_print_string("Select menu option:\n", menu->ui->ui_mode);
        Ui_print_string("s - start game!\n", menu->ui->ui_mode);
        Ui_print_string("g - change gamemode\n", menu->ui->ui_mode);
        Ui_print_string("b - change board size\n", menu->ui->ui_mode);
        Ui_print_string("h - how to play\n", menu->ui->ui_mode);
    } else if(menu->menu_option == 'g'){
        Ui_print_string("Select gamemode:\n", menu->ui->ui_mode);
        Ui_print_string("1 - player vs player\n", menu->ui->ui_mode);
        Ui_print_string("2 - player vs bot\n", menu->ui->ui_mode);
        Ui_print_string("3 - bot vs bot\n", menu->ui->ui_mode);
    } else if(menu->menu_option == 'b'){
        Ui_print_string("Input new board size:\n", menu->ui->ui_mode);
    } else if(menu->menu_option == 'h'){
        if(menu->ui->ui_mode == 't'){
            Ui_print_string("How to play:\n", menu->ui->ui_mode);
            Ui_print_string("When it is your turn, input row and column of big board,\n", menu->ui->ui_mode);
            Ui_print_string("followed by row and column of small board, in which you want to play.\n", menu->ui->ui_mode);
            Ui_print_string("Active board is marked by yellow color and you have to play in it,\n", menu->ui->ui_mode);
            Ui_print_string("if there is no active board, then you can play in any board.\n", menu->ui->ui_mode);
            Ui_print_string("TL;DR first goes [row] [col] for big board, then [row] [col] for small board\n", menu->ui->ui_mode);
            Ui_print_string("\nPress q to return to main menu\n", menu->ui->ui_mode);
        } else{
            Ui_print_string("How to play:\n", menu->ui->ui_mode);
            Ui_print_string("When it is your turn, select row and column of big board and cell in small board.\n", menu->ui->ui_mode);
            Ui_print_string("Active board is highlighted. For input use arrow keys and enter key.\n", menu->ui->ui_mode);
            Ui_print_string("\nPress q to return to main menu\n", menu->ui->ui_mode);
        }
    }
}

void Menu_action_change_gamemode(Menu *menu){
    char gamemode = Menu_get_option(menu, 'c');
    if(gamemode == '1'){        // player vs player
        menu->player1 = 'p';
        menu->player2 = 'p';
    } else if(gamemode == '2'){     // player vs bot
        menu->player1 = 'p';
        menu->player2 = 'b';
    } else if(gamemode == '3'){     // bot vs bot
        menu->player1 = 'b';
        menu->player2 = 'b';
    }
}

void Menu_action_change_board_size(Menu *menu){
    int size = Menu_get_option(menu, 'i');
    menu->board_size = size;
}

void Menu_action_help_page(Menu *menu){
    Menu_get_option(menu, 'c');
}

void Menu_end(Menu *menu, char ui_mode){
    if(ui_mode == 't'){
        if(menu->player1 == 'p') menu->player1 = 't';
        if(menu->player2 == 'p') menu->player2 = 't';
    } else if(ui_mode == 'g'){
        if(menu->player1 == 'p') menu->player1 = 'g';
        if(menu->player2 == 'p') menu->player2 = 'g';
    }
}
