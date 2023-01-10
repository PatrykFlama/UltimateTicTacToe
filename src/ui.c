#include "ui.h"

// typedef struct Ui{
//     char ui_mode;       // t - terminal, g - gui
//     enum TerminalColors color_x, color_o, color_empty, color_empty_active;
//     int *active_board;
// } Ui;


void Ui_init(Ui *ui, char _ui_mode, int *_active_board){
    ui->ui_mode = _ui_mode;
    ui->active_board = _active_board;
    ui->color_x = Red;
    ui->color_o = Green;
    ui->color_empty = Blue;
    ui->color_empty_active = Yellow;
}

void Ui_clear(char mode){
    if(mode == 't'){            // terminal clear
        printf("\e[1;1H\e[2J");
    } else{                     // gui clear

    }
}

void Ui_update(Ui *ui, BigBoard *board){
    Ui_clear(ui->ui_mode);
    Ui_draw(ui, board);
}

void Ui_draw(Ui *ui, BigBoard *board){
    Ui_draw_BigBoard(ui, board);
}

void Ui_draw_BigBoard(Ui *ui, BigBoard *board){
    FOR(row, board->board_size){
        FOR(line, board->board_size){
            FOR(col, board->board_size){
                Ui_draw_SmallBoard(ui, BigBoard_choose_SmallBoard(board, row, col), line);
                if(col != board->board_size-1){
                    Ui_print('|', ui->ui_mode);     // print *THICK* perpendicular lines
                    Ui_print('|', ui->ui_mode);
                }
            }
            Ui_print('\n', ui->ui_mode);
        }

        if(row != board->board_size-1){
            FOR(2){
                FOR(cell, board->board_size){       // print *THICK* parallel lines
                    FOR(cells, board->board_size-1){
                        Ui_print('-', ui->ui_mode);
                        Ui_print('-', ui->ui_mode);
                    }
                    Ui_print('-', ui->ui_mode);
                    if(cell < board->board_size-1){
                        Ui_print('+', ui->ui_mode);
                        Ui_print('+', ui->ui_mode);
                    }
                }
                Ui_print('\n', ui->ui_mode);
            }
        }
    }
}

void Ui_draw_SmallBoard(Ui *ui, SmallBoard *board, int row){
    // printf("Active board: %d\n", *(ui->active_board));
    FOR(col, board->board_size){
        char player = *(board->tab + (col + row*board->board_size)*sizeof(char));
        switch (player){
            case 'x':
                Ui_print_color(player, ui->ui_mode, ui->color_x);
                break;
            case 'o':
                Ui_print_color(player, ui->ui_mode, ui->color_o);
                break;
            default:
                Ui_print_color(player, ui->ui_mode, (board->board_number == *(ui->active_board) ? ui->color_empty_active : ui->color_empty));
                break;
        }
        
        if(col != board->board_size-1){
            Ui_print_color('|', ui->ui_mode, Black);
        }
    }
}

void Ui_print_color(char c, char mode, enum TerminalColors color){
    if(mode == 't') {
        Ui_print_terminal(c, color);
    }
    else Ui_print_gui(c, color);
}

void Ui_print_string_color(char *str, char mode, enum TerminalColors color){
    int ptr = 0;
    while(*(str+ptr) != '\0') Ui_print_color(*(str+ptr++), mode, color);
}

void Ui_print_terminal(char c, enum TerminalColors color){
    printf("%s", TerminalColorsNames[color]);
    putchar(c);
    printf("%s", TerminalColorsNames[Clear]);
}

void Ui_print_gui(char c, enum TerminalColors color){
    // TODO
}
