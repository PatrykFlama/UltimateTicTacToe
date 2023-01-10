#include "template.h"
#include "small_board.h"
#include "big_board.h"
#include "move.h"
#include "player.h"
#include "ui.h"
#include "game.h"

int main(int argc, char** argv){
    int board_size = 3;
    if(argc > 1) board_size = atoi(argv[1]);
    // TODO: menu

    Player player1, player2;
    Player_init(&player1, 't');
    Player_init(&player2, 't');
    
    Ui ui;
    Game game;

    SmallBoard boards[board_size*board_size];
    BigBoard board;
    board.tab = boards;
    BigBoard_init(&board, board_size);    
    
    Game_init(&game, &player1, &player2, &ui, 3, &board);


    while(!Game_tick(&game)){}
    Game_end(&game);
    printf("Out of main loop\n");
}
