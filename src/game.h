#ifndef GAME
#define GAME

#include "template.h"
#include "big_board.h"
#include "move.h"       // TODO
#include "player.h"     // TODO
#include "ui.h"         // TODO

typedef struct Game{
    Player *playero, *playerx;
    BigBoard board;
    char active_player;     // player, whos turn is now
    char game_won;
} Game;

//? ------ GAMEPLAY ------
void Game_init(Game *game, Player *_playero, Player *_playerx, int game_size);   // start and initialize game
void Game_end(Game *game);    // end game
bool Game_player_move(Game *game);   // execute player move, true/false == success/or not
void Game_player_made_move(Game *game);     // check if game won, switch active players

// TODO: functions to give info for bot

#endif
