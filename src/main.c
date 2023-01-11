#include "template.h"
#include "small_board.h"
#include "big_board.h"
#include "move.h"
#include "player.h"
#include "ui.h"
#include "game.h"

int main(int argc, char** argv){
    // how to run: ./main.exe $ui_mode$ $board_size$
    int board_size = 3;
    char ui_mode = 't';
    if(argc > 1) ui_mode = argv[1][0];
    if(argc > 2) board_size = atoi(argv[2]);
    // TODO: menu

    Player player1, player2;
    Player_init(&player1, ui_mode);
    Player_init(&player2, ui_mode);
    
    Ui ui;

    SmallBoard boards[board_size*board_size];
    BigBoard board;
    board.tab = boards;
    BigBoard_init(&board, board_size);    
    
    Game game;
    Game_init(&game, &player1, &player2, &ui, ui_mode, &board, 3);

    while(!Game_tick(&game)){}
}
