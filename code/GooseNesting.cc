#include "GooseNesting.h"

GooseNesting::GooseNesting(std::string name){
    NonProperty(name);
}
void GooseNesting::land(Player* p){
    applyEffect(p);
}
void GooseNesting::applyEffect(Player* p){
    updateObservers("You are attacked by Mr.Goose!");
}

