#include "menu.h"

void Menu_init(Menu *menu, bool _debug){
    menu->debug = _debug;
    menu->menu_option = 'm';

    menu->ui_mode = 't';
    menu->board_size = 3;
    menu->player1 = 't';
    menu->player2 = 't';
}

bool Menu_loop(Menu *menu){
    Menu_print(menu);

    if(menu->menu_option == 'm'){
        Menu_action_menu(menu);
    } else if(menu->menu_option == 'g'){
        Menu_action_change_gamemode(menu);
        menu->menu_option = 'm';
    } else if(menu->menu_option == 'u'){
        Menu_action_change_ui(menu);
        menu->menu_option = 'm';
    } else if(menu->menu_option == 'b'){
        Menu_action_change_board_size(menu);
        menu->menu_option = 'm';
    } else {
        return true;
    }

    return false;
}

char Menu_get_option(char type){
    if(type == 'c'){
        char option;
        scanf(" %c", &option);
        return option;
    } else if(type == 'i'){
        int option;
        scanf(" %d", &option);
        return option;
    }
}

void Menu_print(Menu *menu){
    if(!menu->debug) printf("\e[1;1H\e[2J");

    if(menu->menu_option == 'm'){
        printf("Select menu option:\n");
        printf("s - start game!\n");
        printf("g - change gamemode\n");
        printf("u - change display mode\n");
        printf("b - change board size\n");
    } else if(menu->menu_option == 'g'){
        printf("Select gamemode:\n");
        printf("1 - player vs player\n");
        printf("2 - player vs bot\n");
        printf("3 - bot vs bot\n");
    } else if(menu->menu_option == 'u'){
        printf("Select display mode:\n");
        printf("t - display in terminal\n");
        printf("g - display in gui (not working)\n");       // TODO gui is wip
    } else if(menu->menu_option == 'b'){
        printf("Change board size:\n");
        printf("input new board size:\n");
    }
}

void Menu_action_menu(Menu *menu){
    menu->menu_option = Menu_get_option('c');
}

void Menu_action_change_gamemode(Menu *menu){
    char gamemode = Menu_get_option('c');
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

void Menu_action_change_ui(Menu *menu){
    char ui = Menu_get_option('c');
    menu->ui_mode = ui;
}

void Menu_action_change_board_size(Menu *menu){
    int size = Menu_get_option('i');
    menu->board_size = size;
}

void Menu_end(Menu *menu){
    if(menu->ui_mode == 't'){
        if(menu->player1 == 'p') menu->player1 = 't';
        if(menu->player2 == 'p') menu->player2 = 't';
    } else if(menu->ui_mode == 'g'){
        if(menu->player1 == 'p') menu->player1 = 'g';
        if(menu->player2 == 'p') menu->player2 = 'g';
    }
}
