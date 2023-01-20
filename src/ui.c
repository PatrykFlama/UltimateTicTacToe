#include "ui.h"

// typedef struct Ui{
//     char ui_mode;       // t - terminal, g - gui
//     enum TerminalColors color_x, color_o, color_empty, color_empty_active;
//     int *active_board;
// } Ui;


void Ui_init(Ui *ui, char _ui_mode){
    ui->ui_mode = _ui_mode;
    ui->color_x = Red;
    ui->color_o = Green;
    ui->color_empty = Blue;
    ui->color_empty_active = Yellow;
    ui->debug = false;

    if(ui->ui_mode == 'g'){
        initscr();
        Ui_init_colors();
    }
}

void Ui_init_colors(){
    start_color();
    init_pair(Clear, COLOR_WHITE, A_NORMAL);
    init_pair(Black, COLOR_BLACK, A_NORMAL);
    init_pair(Red, COLOR_RED, A_NORMAL);
    init_pair(Green, COLOR_GREEN, A_NORMAL);
    init_pair(Yellow, COLOR_YELLOW, A_NORMAL);
    init_pair(Blue, COLOR_BLUE, A_NORMAL);
    init_pair(Purple, COLOR_MAGENTA, A_NORMAL);
    init_pair(Cyan, COLOR_CYAN, A_NORMAL);
    init_pair(White, COLOR_WHITE, A_NORMAL);
}

void Ui_end(){
    endwin();
}

void Ui_clear(Ui *ui){
    if(ui->ui_mode == 't'){            // terminal clear
        if(ui->debug) return;
        printf("\e[1;1H\e[2J");
    } else{                     // gui clear
        clear();
    }
}

void Ui_update(Ui *ui, BigBoard *board){
    Ui_clear(ui);
    Ui_draw(ui, board);
    if(ui->ui_mode == 'g') refresh();
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
    FOR(col, board->board_size){
        char player = board->tab[col + row*board->board_size];

        if(player == 'o') Ui_print_color(player, ui->ui_mode, ui->color_o);
        else if(player == 'x') Ui_print_color(player, ui->ui_mode, ui->color_x);
        else if(board->game_won == 'x')  Ui_print_color(player, ui->ui_mode, ui->color_x);
        else if(board->game_won == 'o')  Ui_print_color(player, ui->ui_mode, ui->color_o);
        else if(board->board_number == *(ui->active_board))  Ui_print_color(player, ui->ui_mode, ui->color_empty_active);
        else Ui_print_color(player, ui->ui_mode, ui->color_empty);
        
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
    attron(COLOR_PAIR(color));
    printw("%c", c);
    attroff(COLOR_PAIR(color));
}

char Ui_get_char(char mode){
    if(mode == 't'){
        char c; scanf(" %c", &c);
        return c;
    } else{     // gui
        return getch();
    }
}

int Ui_get_int(char mode){
    if(mode == 't'){
        int n; scanf(" %d", &n);
        return n;
    } else{     // gui
        int n; scanw(" %d", &n);
        return n;
    }
}
