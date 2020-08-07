#include "GooseNesting.h"

//
GooseNesting::GooseNesting() : NonProperty{GOOSE_NESTING} {}

//
void GooseNesting::land(std::shared_ptr<Player> p){
    updateObservers("You are attacked by Mr.Goose!");
}

