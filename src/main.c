#include "template.h"
#include "small_board.h"
#include "big_board.h"
#include "move.h"
#include "player.h"
#include "ui.h"
#include "game.h"

int main(){
    // TODO: menu

    Player player1, player2;
    Player_init(&player1, 't', 'o');
    Player_init(&player2, 't', 'o');
    
    Ui ui;
    Ui_init(&ui, 't');

    Game game;

    printf("Running smth\n");
    SmallBoard boards[9];
    BigBoard board;
    board.tab = boards;

    BigBoard_init(&board, 3);
    game.board = &board;
    *((*(game.board)).tab[0].tab) = 'y';
    *(board.tab[0].tab+1) = 'z';
    // *((*(game.board)).tab[1].tab) = 'z';
    // printf("Char: %c\n", *((*(game.board)).tab[1].tab));
    *(board.tab[1].tab) = 'x';
    printf("Char: %c\n", *(board.tab[1].tab));
    
    //! Game_init(&game, &player1, &player2, &ui, 3);
    Game_init(&game, &player1, &player2, &ui, 3, &board);


    while(Game_tick(&game)){}
    Game_end(&game);
    printf("Out of main loop\n");
}
