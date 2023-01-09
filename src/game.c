#include "template.h"
#include "game.h"


// typedef struct Game{
//     Player *playero, *playerx;
//     BigBoard board;
//     Ui *ui;
//     char active_player;     // player, whos turn is now
//     char game_won;          // '.' -> no, 'x' / 'o'
// } Game;


void Game_init(Game *game, Player *_playero, Player *_playerx, Ui *_ui, int game_size, BigBoard *_board){   // start and initialize game
    // BigBoard_init(&(game->board), game_size);
    game->board = _board;
    game->playero = _playero;   // player 'o'
    game->playerx = _playerx;   // player 'x'
    game->active_player = 'o';  // 'o' makes first move
    game->ui = _ui;
    game->game_won = '.';

    Ui_update(game->ui, game->board);
}

void Game_end(Game *game){    // end game
    BigBoard_delete(game->board);
}

Player* Game_give_active_player(Game *game){
    if(game->active_player == 'o') return game->playero;
    return game->playerx;
}

bool Game_player_move(Game *game){
    if(game->ui->ui_mode == 't'){
        char *str = "Give coordinates of big board, then small board (first row, then column): ";
        Ui_print_string(str, 't');
    }
    Move move = Player_get_move(Game_give_active_player(game), game->board->board_size);

    // TODO: force player to play in appropriate cell

    bool success = BigBoard_move_make(game->board, move.board, move.cell, game->active_player);
    if(success) Game_player_made_move(game);
    return success;
}

void Game_player_made_move(Game *game){     // check if game won, switch active players
    game->game_won = BigBoard_won(game->board);
    if(game->game_won == '.') Player_swap(&(game->active_player));
    Ui_update(game->ui, game->board);

    if(game->game_won != '.') Game_end(game);
}

bool Game_tick(Game *game){
    Game_player_move(game);
    if(game->game_won != '.') return true;
    return false;
}

void Game_over(Game *game){
    printf("Game over\n");  // TODO: print game over screen

    Game_end(game);
}
