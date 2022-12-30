#include "template.h"
#include "game.h"

// typedef struct Ui{
//     char ui_mode;       // t - terminal, g - gui
// } Ui;

void Ui_init(Ui *ui, char _ui_mode){
    ui->ui_mode = _ui_mode;
}

void Ui_update(Ui *ui, Game *game){
    if(ui->ui_mode == 't'){
        Ui_draw_terminal(game);
    } else{
        Ui_draw_gui(game);
    }
}


