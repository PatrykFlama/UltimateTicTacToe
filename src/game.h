#include "template.h"
#include "big_board.h"
#include "move.h"       // TODO
#include "player.h"     // TODO

typedef struct Game{
    Player player1, player2;
    BigBoard board;
    char active_player;     // player, whos turn is now
    char game_won;
} Game;

//? ------ GAMEPLAY ------
void Game_init(Game *game, Player *_player1, Player *_player2, int game_size);   // start and initialize game
void Game_end(Game *game);    // end game
bool Game_player_move(Game *game, Move move);   // execute player move, true/false == success/or not
void Game_player_made_move(Game *game);     // check if game won, switch active players

// TODO: functions to give info for bot
