#include "template.h"

typedef struct Move{
    int board;
    int cell;
    bool is_empty;
} Move;

bool Move_is_empty(Move *move){
    return move->is_empty;
}
