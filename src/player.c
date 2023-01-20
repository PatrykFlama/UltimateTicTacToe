#include "player.h"

// typedef struct Player{
//     char input_type;      // t - terminal1, g - gui1, b - bot1
// } Player;

void Player_init(Player *player, BigBoard *_board, char _input_type, char _char_){
    player->input_type = _input_type;
    player->char_ = _char_;
    player->board = _board;
    srand(time(NULL));
}

Move Player_get_move(Player *player, BigBoard *board, Ui *ui){
    Move move;
    if(player->input_type == 't'){                                  //! ------------terminal------------
        int big_row, big_col, small_row, small_col;
        if(scanf(" %d %d %d %d", &big_row, &big_col, &small_row, &small_col) != 4) goto player_wrong_move;
        --big_row, --big_col, --small_row, --small_col;
        move.board = big_row*board->board_size + big_col;
        move.cell = small_row*board->board_size + small_col;
    } else if(player->input_type == 'g'){                           //! ----------------------GUI----------------------
        if(BigBoard_choose_SmallBoard(board, 0, *board->active_board)->game_won == '.'){
            move.board = *board->active_board, move.cell = 0;
        } else{
            move.board = 0, move.cell = 0;
            Player_set_highlight_board(&move, board, 1, ui);
            Ui_update(ui, board);
            Ui_print_active_player(ui, player->char_);

            while(Player_get_move_board_gui(player, board, &move, ui)){}
        }

        Player_set_highlight_board(&move, board, 0, ui);
        Player_set_highlight_cell(&move, BigBoard_choose_SmallBoard(board, 0, move.board), 2);
        Ui_update(ui, board);
        Ui_print_active_player(ui, player->char_);

        while(Player_get_move_cell_gui(player, board, BigBoard_choose_SmallBoard(board, 0, move.board), &move, ui)){}

        Player_set_highlight_cell(&move, BigBoard_choose_SmallBoard(board, 0, move.board), 0);

        Ui_update(ui, board);
        Ui_print_active_player(ui, player->char_);
    } else{                                                     //! -----------bot-----------
        int board_size = player->board->board_size;
        int active_boards[board_size*board_size];
        int ptr = 0;

        if(BigBoard_choose_SmallBoard(player->board, 0, *player->board->active_board)->game_won != '.'){
            FOR(boards, board_size*board_size){
                if(BigBoard_choose_SmallBoard(player->board, 0, boards)->game_won == '.'){
                    active_boards[ptr++] = boards;
                }
            }

            move.board = active_boards[rand() % ptr];
        } else{
            move.board = *player->board->active_board;
        }

        ptr = 0;
        FOR(cells, board_size*board_size){
            if(BigBoard_choose_SmallBoard(player->board, 0, move.board)->tab[cells] == '.'){
                active_boards[ptr++] = cells;
            }
        }

        move.cell = active_boards[rand() % ptr];
    }

    return move;

    player_wrong_move:
    move.board = -1, move.cell = -1;

    char temp = 'w';    // flush line
    if(player->input_type == 't') while(temp != '\n') temp = getchar();
    
    return move;
}

void Player_set_highlight_board(Move *move, BigBoard *board, int val, Ui* ui){
    if(!ui->fun) BigBoard_choose_SmallBoard(board, 0, move->board)->highlight = val;
    else{
        if(val == 0){
            if(BigBoard_choose_SmallBoard(board, 0, move->board)->game_won == 'o') BigBoard_choose_SmallBoard(board, 0, move->board)->highlight = 3;
            else if(BigBoard_choose_SmallBoard(board, 0, move->board)->game_won == 'x') BigBoard_choose_SmallBoard(board, 0, move->board)->highlight = 4;
            else BigBoard_choose_SmallBoard(board, 0, move->board)->highlight = 0;
        } else BigBoard_choose_SmallBoard(board, 0, move->board)->highlight = val;
    }
}

void Player_set_highlight_cell(Move *move, SmallBoard *board, int val){
    board->highlights[move->cell] = val;
}

bool Player_get_move_board_gui(Player *player, BigBoard *board, Move *move, Ui *ui){
    int key = getch();
    Player_set_highlight_board(move, board, 0, ui);

    if(key == KEY_UP){
        if(move->board / board->board_size > 0) move->board -= board->board_size;
    } else if(key == KEY_DOWN){
        if(move->board / board->board_size < board->board_size-1) move->board += board->board_size;
    } else if(key == KEY_LEFT){
        if(move->board % board->board_size > 0) move->board -= 1;
    } else if(key == KEY_RIGHT){
        if(move->board % board->board_size < board->board_size-1) move->board += 1;
    } else if(key == '\n'){
        Player_set_highlight_board(move, board, 1, ui);
        return false;
    }

    Player_set_highlight_board(move, board, 1, ui);

    Ui_update(ui, board);
    Ui_print_active_player(ui, player->char_);

    return true;
}   

bool Player_get_move_cell_gui(Player *player, BigBoard *big_board, SmallBoard *board, Move *move, Ui *ui){
    int key = getch();
    Player_set_highlight_cell(move, board, 0);

    if(key == KEY_UP){
        if(move->cell / board->board_size > 0) move->cell -= board->board_size;
    } else if(key == KEY_DOWN){
        if(move->cell / board->board_size < board->board_size-1) move->cell += board->board_size;
    } else if(key == KEY_LEFT){
        if(move->cell % board->board_size > 0) move->cell -= 1;
    } else if(key == KEY_RIGHT){
        if(move->cell % board->board_size < board->board_size-1) move->cell += 1;
    } else if(key == '\n'){
        Player_set_highlight_cell(move, board, 2);
        return false;
    }

    Player_set_highlight_cell(move, board, 2);

    Ui_update(ui, big_board);
    Ui_print_active_player(ui, player->char_);
    // Ui_print_active_player(ui, move->cell + '0');

    return true;
}

void Player_swap(char *player){
    if(*player == 'o') *player = 'x';
    else *player = 'o'; 
}
