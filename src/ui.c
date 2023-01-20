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
    ui->fun = false;

    if(ui->ui_mode == 'g'){
        initscr();
        Ui_init_colors();
        keypad(stdscr, TRUE);
    }
}

void Ui_init_colors(){
    start_color();
    init_color(COLOR_MAGENTA, 200, 200, 0);     // yellow background
    init_color(COLOR_CYAN, 0, 300, 300);        // cyan background

    init_pair(Clear, COLOR_WHITE, A_NORMAL);
    init_pair(Black, COLOR_BLACK, A_NORMAL);
    init_pair(Red, COLOR_RED, A_NORMAL);
    init_pair(Green, COLOR_GREEN, A_NORMAL);
    init_pair(Yellow, COLOR_YELLOW, A_NORMAL);
    init_pair(Blue, COLOR_BLUE, A_NORMAL);
    init_pair(White, COLOR_WHITE, A_NORMAL);

    init_pair(Highlight1Clear, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(Highlight1Black, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(Highlight1Red, COLOR_RED, COLOR_MAGENTA);
    init_pair(Highlight1Green, COLOR_GREEN, COLOR_MAGENTA);
    init_pair(Highlight1Yellow, COLOR_YELLOW, COLOR_MAGENTA);
    init_pair(Highlight1Blue, COLOR_BLUE, COLOR_MAGENTA);
    init_pair(Highlight1White, COLOR_WHITE, COLOR_MAGENTA);

    init_pair(Highlight2Clear, COLOR_WHITE, COLOR_CYAN);
    init_pair(Highlight2Black, COLOR_BLACK, COLOR_CYAN);
    init_pair(Highlight2Red, COLOR_RED, COLOR_CYAN);
    init_pair(Highlight2Green, COLOR_GREEN, COLOR_CYAN);
    init_pair(Highlight2Yellow, COLOR_YELLOW, COLOR_CYAN);
    init_pair(Highlight2Blue, COLOR_BLUE, COLOR_CYAN);
    init_pair(Highlight2White, COLOR_WHITE, COLOR_CYAN);

    init_pair(Highlight3Clear, COLOR_WHITE, COLOR_GREEN);
    init_pair(Highlight3Black, COLOR_BLACK, COLOR_GREEN);
    init_pair(Highlight3Red, COLOR_RED, COLOR_GREEN);
    init_pair(Highlight3Green, COLOR_GREEN, COLOR_GREEN);
    init_pair(Highlight3Yellow, COLOR_YELLOW, COLOR_GREEN);
    init_pair(Highlight3Blue, COLOR_BLUE, COLOR_GREEN);
    init_pair(Highlight3White, COLOR_WHITE, COLOR_GREEN);

    init_pair(Highlight4Clear, COLOR_WHITE, COLOR_RED);
    init_pair(Highlight4Black, COLOR_BLACK, COLOR_RED);
    init_pair(Highlight4Red, COLOR_RED, COLOR_RED);
    init_pair(Highlight4Green, COLOR_GREEN, COLOR_RED);
    init_pair(Highlight4Yellow, COLOR_YELLOW, COLOR_RED);
    init_pair(Highlight4Blue, COLOR_BLUE, COLOR_RED);
    init_pair(Highlight4White, COLOR_WHITE, COLOR_RED);
}

void Ui_end(){
    endwin();
}

void Ui_clear(Ui *ui){
    if(ui->ui_mode == 't'){            // terminal clear
        if(ui->fun) return;
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
        int color_offset_cell = max(board->highlights[row*board->board_size+col], board->highlight);

        if(player == 'o') Ui_print_color_offset(player, ui->ui_mode, (ui->color_o), color_offset_cell);
        else if(player == 'x') Ui_print_color_offset(player, ui->ui_mode, (ui->color_x), color_offset_cell);
        else if(board->game_won == 'x')  Ui_print_color_offset(player, ui->ui_mode, (ui->color_x), color_offset_cell);
        else if(board->game_won == 'o')  Ui_print_color_offset(player, ui->ui_mode, (ui->color_o), color_offset_cell);
        else if(board->board_number == *(ui->active_board))  Ui_print_color_offset(player, ui->ui_mode, (ui->color_empty_active), color_offset_cell);
        else Ui_print_color_offset(player, ui->ui_mode, (ui->color_empty), color_offset_cell);
        
        if(col != board->board_size-1){
            Ui_print_color_offset('|', ui->ui_mode, Black, board->highlight);
        }
    }
}

void Ui_print_color_offset(char c, char mode, enum TerminalColors color, int color_offset){
    if(mode == 't') {
        Ui_print_terminal(c, color);
    }
    else Ui_print_gui(c, color+(color_offset*number_of_colors));
    // else if(c == '\n') Ui_print_gui(c, color);
    // else Ui_print_gui(color_offset+'0', color);
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

void Ui_print_active_player(Ui *ui, char player){
    Ui_print_string("Active player ", ui->ui_mode);
    Ui_print(player, ui->ui_mode);
    Ui_print_string(": ", ui->ui_mode);
}
