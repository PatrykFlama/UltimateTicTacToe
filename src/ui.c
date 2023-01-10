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

void Ui_clear(char mode){
    if(mode == 't'){            // terminal clear
        printf("\e[1;1H\e[2J");
    } else{                     // gui clear

    }
}

void Ui_update(Ui *ui, BigBoard *board){
    Ui_clear(ui->ui_mode);
    Ui_draw(board, ui->ui_mode);
}

void Ui_draw_BigBoard(BigBoard *board, char mode){
    FOR(row, board->board_size){
        FOR(line, board->board_size){
            FOR(col, board->board_size){
                Ui_draw_SmallBoard(BigBoard_choose_SmallBoard(board, row, col), mode, line);
                if(col != board->board_size-1){
                    Ui_print('|', mode);     // print *THICK* perpendicular lines
                    Ui_print('|', mode);
                }
            }
            Ui_print('\n', mode);
        }

        if(row != board->board_size-1){
            FOR(2){
                FOR(cell, board->board_size){       // print *THICK* parallel lines
                    FOR(cells, board->board_size-1){
                        Ui_print('-', mode);
                        Ui_print('-', mode);
                    }
                    Ui_print('-', mode);
                    if(cell < board->board_size-1){
                        Ui_print('+', mode);
                        Ui_print('+', mode);
                    }
                }
                Ui_print('\n', mode);
            }
        }
    }
}

void Ui_draw_SmallBoard(SmallBoard *board, char mode, int row){
    FOR(col, board->board_size){
        Ui_print(*(board->tab + (col + row*board->board_size)*sizeof(char)), mode);
        if(col != board->board_size-1){
            Ui_print('|', mode);
        }
    }
}

void Ui_print(char c, char mode){
    if(mode == 't') Ui_print_terminal(c);
    else Ui_print_gui(c);
}

void Ui_print_string(char *str, char mode){
    int ptr = 0;
    while(*(str+ptr) != '\0') Ui_print(*(str+ptr++), mode);
}

void Ui_print_terminal(char c){
    putchar(c);
}

void Ui_print_gui(char c){
    // TODO
}
