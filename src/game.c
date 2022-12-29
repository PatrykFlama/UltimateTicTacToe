#include "template.h"
#include "big_board.h"
#include "player.h"
#include "game.h"

// typedef struct Game{
//     Player player1, player2;
//     char active_player;     // player, whos turn is now
// } Game;


void Game_init(Game *game, Player *_player1, Player *_player2, int game_size){   // start and initialize game
    BigBoard_init(game->board, game_size);
    game.player1 = _player1;
    game.player2 = _player2;
    game->active_player = 'o';
}

void Game_end(Game *game){    // end game
    BigBoard_delete(game->board);
}

bool Game_player_move(Game *game){   // TODO: execute player move, true/false == success/or not
    Move move = Player.move();
    if(!Move.empty(move)){     // if player made move
        return BigBoard_move_make(game->board, move.board, move.cell, game->active_player);
        Game_player_made_move(game);
    }
}

void Game_player_made_move(Game *game){     // check if game won, switch active players
    game->game_won = BigBoard_won(game->board);
    if(game->game_won == '.') Player_swap(game->active_player);
}
