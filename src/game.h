#ifndef GAME
#define GAME

#include "template.h"
#include "big_board.h"
#include "move.h"
#include "player.h"
#include "ui.h"

typedef struct Game{
    Player *playero, *playerx;
    BigBoard board;
    Ui *ui;
    char active_player;     // player, whos turn is now
    char game_won;          // '.' -> no, 'x' / 'o'
} Game;

//? ------ GAMEPLAY ------
void Game_init(Game *game, Player *_playero, Player *_playerx, Ui *_ui, int game_size);   // start and initialize game
void Game_end(Game *game);    // end game
Player* Game_give_active_player(Game *game);
bool Game_player_move(Game *game);   // execute player move, true/false == success/or not
void Game_player_made_move(Game *game);     // check if game won, switch active players
bool Game_tick(Game *game);

// TODO: functions to give info for bot

#endif
