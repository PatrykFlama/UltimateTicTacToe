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
        char player = *(board->tab + (col + row*board->board_size)*sizeof(char));
        Ui_print_color(player, mode, (player == 'x' ? Red : (player == 'o' ? Green : Cyan)));
        if(col != board->board_size-1){
            Ui_print_color('|', mode, Black);
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
