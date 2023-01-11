#include "template.h"
#include "small_board.h"
#include "big_board.h"
#include "move.h"
#include "player.h"
#include "ui.h"
#include "menu.h"
#include "game.h"

int main(int argc, char** argv){
    // how to run: ./main.exe $ui_mode$ $board_size$
    int board_size = 3;
    char ui_mode = 't';
    if(argc > 1) ui_mode = argv[1][0];
    if(ui_mode != 't' && ui_mode != 'g') ui_mode = 't';
    if(argc > 2) board_size = atoi(argv[2]);

    Player player1, player2;
    Ui ui;
    SmallBoard boards[board_size*board_size];
    BigBoard board;
    Game game;
    Menu menu;
    
    Ui_init(game.ui, ui_mode, &(game.last_move.cell));
    // Menu_init(&menu, &ui);
    // while(!Menu_loop(&menu)){}
    // TODO: menu

    Player_init(&player1, ui_mode);
    Player_init(&player2, ui_mode);
    BigBoard_init(&board, boards, board_size);
    Game_init(&game, &player1, &player2, &ui, &board, 3);
    

    while(!Game_tick(&game)){}
}
