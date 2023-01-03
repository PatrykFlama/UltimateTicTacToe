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
    Game_init(&game, &player1, &player2, &ui, 3);

    while(Game_tick(&game)){}
    printf("Out of main loop\n");
}
