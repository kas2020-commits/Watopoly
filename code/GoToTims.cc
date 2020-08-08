#include "GoToTims.h"

//
GoToTims::GoToTims(): NonProperty{GO_TO_TIMS} {}

//
void GoToTims::land(Player* p) {
    p->move("DC Tims Line");
    updateObservers("You Go To Tims Line!");
}

