#include "GooseNesting.h"

//
GooseNesting::GooseNesting() : Tile{GOOSE_NESTING} {}

//
void GooseNesting::landEffect(Player* p){
    updateObservers("You are attacked by Mr.Goose!");
}

