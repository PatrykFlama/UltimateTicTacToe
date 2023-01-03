#include "template.h"
#include "ui.h"

// typedef struct Ui{
//     char ui_mode;       // t - terminal, g - gui
// } Ui;

void Ui_init(Ui *ui, char _ui_mode){
    ui->ui_mode = _ui_mode;
}

void Ui_draw(BigBoard *board, char mode){
    Ui_draw_BigBoard(board, mode);
}

void Ui_update(Ui *ui, BigBoard *board){
    Ui_draw(board, ui->ui_mode);
}

void Ui_draw_BigBoard(BigBoard *board, char mode){
    FOR(row, board->board_size){
        FOR(line, board->board_size*2-1){
            FOR(col, board->board_size){
                Ui_draw_SmallBoard(BigBoard_choose_SmallBoard(board, row, col), mode, line);
                if(col != board->board_size-1){
                    Ui_print('|', mode);     // print *THICK* perpendicular lines
                    Ui_print('|', mode);
                }
            }
        }

        if(row != board->board_size-1){
            FOR(2)
            FOR(cell, board->board_size){       // print *THICK* parallel lines
                FOR(cells, board->board_size){
                    Ui_print('-', mode);
                    Ui_print('-', mode);
                }
                Ui_print('+', mode);
                Ui_print('+', mode);
            }
        }

        Ui_print('\n', mode);
    }
}

void Ui_draw_SmallBoard(SmallBoard *board, char mode, int row){
    if(row%2 == 0){
        row /= 2;
        FOR(col, board->board_size){
            Ui_print(*(board->tab + (col + row*board->board_size)*sizeof(char)), mode);
            if(col != board->board_size-1){
                Ui_print('|', mode);
            }
        }
    } else{
        FOR(col, board->board_size){
            Ui_print('-', mode);
            if(col != board->board_size-1){
                Ui_print('-', mode);
            } else {
                Ui_print('+', mode);
            }
        }
    }
}

void Ui_print(char c, char mode){
    if(mode == 't') Ui_print_terminal(c);
    else Ui_print_gui(c);
}

void Ui_print_terminal(char c){
    putchar(c);
}

void Ui_print_gui(char c){
    // TODO
}
