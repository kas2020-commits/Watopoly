#include "GoToTims.h"

//
GoToTims::GoToTims(std::string name): NonProperty{name} {}

//
void GoToTims::land(Player* p) {
    p->move("DC Tims Line");
    updateObservers("You Go To Tims Line!");
}

