#include "GoToTims.h"

//
GoToTims::GoToTims(std::string name): NonProperty{name} {}

//
void GoToTims::applyEffect(std::shared_ptr<Player> p){
    p->move("DC Tims Line");
    updateObservers("You Go To Tims Line!");
}

