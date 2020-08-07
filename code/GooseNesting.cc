#include "GooseNesting.h"

//
GooseNesting::GooseNesting(std::string name) : NonProperty{name} {}

//
void GooseNesting::applyEffect(std::shared_ptr<Player> p){
    updateObservers("You are attacked by Mr.Goose!");
}

