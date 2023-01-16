#include "template.h"
#include "small_board.h"
#include "big_board.h"
#include "move.h"
#include "player.h"
#include "ui.h"
#include "game.h"
#include "menu.h"

int main(int argc, char** argv){
    // how to run: ./main.exe $ui_mode$
    int board_size = 3;
    char ui_mode = 't';
    bool debug = false;

    if(argc > 1 && argv[1][1] == 'd') debug = true;
    if(argc > 1) ui_mode = argv[1][0];
    if(ui_mode != 't' && ui_mode != 'g') ui_mode = 't';

    Menu menu;
    Menu_init(&menu, debug);
    while(!Menu_loop(&menu)) {}
    Menu_end(&menu);
    board_size = menu.board_size;
    ui_mode = menu.ui_mode;

    Player player1, player2;
    Player_init(&player1, menu.player1);
    Player_init(&player2, menu.player2);
    
    Ui ui;
    Ui_init(&ui, ui_mode);
    ui.debug = debug;

    SmallBoard boards[menu.board_size*menu.board_size];
    BigBoard board;
    BigBoard_init(&board, boards, menu.board_size);    
    
    Game game;
    ui.active_board = &game.last_move.cell;
    Game_init(&game, &player1, &player2, &ui, &board, menu.board_size);

    while(!Game_tick(&game)){}
}
