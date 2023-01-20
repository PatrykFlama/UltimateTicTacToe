#include "game.h"


// typedef struct Game{
//     Player *playero, *playerx;
//     BigBoard *board;
//     Ui *ui;
//     char active_player;     // player, whos turn is now
//     char game_won;          // '.' -> no, 'x' / 'o'
//     Move last_move;
// } Game;


void Game_init(Game *game, Player *_playero, Player *_playerx, Ui *_ui, BigBoard *_board, int game_size){   // start and initialize game
    // BigBoard_init(&(game->board), game_size);
    game->board = _board;
    game->playero = _playero;   // player 'o'
    game->playerx = _playerx;   // player 'x'
    game->active_player = 'o';  // 'o' makes first move
    game->ui = _ui;
    game->game_won = '.';
    Move move = {-1, -1};
    game->last_move = move;

    Ui_update(game->ui, game->board);
}

void Game_end(Game *game){    // delete game
    Ui_end();
    #ifndef _WIN32
    exit(0);
    #endif
    BigBoard_delete(game->board);
}

Player* Game_give_active_player(Game *game){
    if(game->active_player == 'o') return game->playero;
    return game->playerx;
}

bool Game_player_move(Game *game){
    if(!(game->active_player == 'x' && game->playerx->input_type == 'b') && !(game->active_player == 'o' && game->playero->input_type == 'b')){
        if(game->playero->input_type != 'b') Ui_print_string("Active player ", game->ui->ui_mode);
        Ui_print(game->active_player, game->ui->ui_mode);
        Ui_print_string(": ", game->ui->ui_mode);
    }
    Move move = Player_get_move(Game_give_active_player(game), game->board->board_size);

    bool success = BigBoard_move_make(game->board, move.board, move.cell, game->active_player, game->last_move);
    if(success){
        char player_won = SmallBoard_won(BigBoard_choose_SmallBoard(game->board, 0, move.board));
        if(player_won != '.') {
            Ui_print_string("Small game won by ", game->ui->ui_mode);
            Ui_print_color(player_won, game->ui->ui_mode, (player_won == 'o' ? game->ui->color_o : game->ui->color_x));
            Ui_print_string("!\n", game->ui->ui_mode);
        }
        game->last_move = move;
        Game_player_made_move(game);
    } else{
        Ui_update(game->ui, game->board);
        Ui_print_string("Wrong move!\n", game->ui->ui_mode);
    }
    return success;
}

void Game_player_made_move(Game *game){     // check if game won, switch active players
    game->game_won = BigBoard_won(game->board);
    if(game->game_won == '.') Player_swap(&(game->active_player));
    Ui_update(game->ui, game->board);

    if(game->game_won != '.') Game_over(game);
}

bool Game_tick(Game *game){
    Game_player_move(game);
    if(game->game_won != '.') return true;
    return false;
}

void Game_over(Game *game){
    if(game->game_won != 'd') {
        Ui_print_string("Game won by ", game->ui->ui_mode);
        Ui_print_color(game->active_player, game->ui->ui_mode, (game->active_player == 'x' ? game->ui->color_x : game->ui->color_o));
        Ui_print('\n', game->ui->ui_mode);
    } else{
        Ui_print_string("Draw! No one wins :<\n", game->ui->ui_mode);
    }

    if(game->ui->ui_mode == 'g'){
        Ui_print_string("Press any key to continue\n", game->ui->ui_mode);
        Ui_get_char(game->ui->ui_mode);
    }

    Game_end(game);
}
