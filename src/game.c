#include "template.h"
#include "big_board.h"
#include "move.h"
#include "player.h"
#include "game.h"

// typedef struct Game{
//     Player playero, playerx;
//     char active_player;     // player, whos turn is now
// } Game;


void Game_init(Game *game, Player *_playero, Player *_playerx, int game_size){   // start and initialize game
    BigBoard_init(&(game->board), game_size);
    game->playero = _playero;   // player 'o'
    game->playerx = _playerx;   // player 'x'
    game->active_player = 'o';
}

void Game_end(Game *game){    // end game
    BigBoard_delete(&(game->board));
}

Player* Game_give_player(Game *game){
    if(game->active_player == 'o') return game->playero;
    return game->playerx;
}

bool Game_player_move(Game *game){   // TODO: execute player move, true/false == success/or not
    Move move = Player_move(Game_give_player(game));
    if(!Move_is_empty(&move)){     // if player made move
        return BigBoard_move_make(game->board, move.board, move.cell, game->active_player);
        Game_player_made_move(game);
    }
}

void Game_player_made_move(Game *game){     // check if game won, switch active players
    game->game_won = BigBoard_won(&(game->board));
    if(game->game_won == '.') Player_swap(game->active_player);
}
