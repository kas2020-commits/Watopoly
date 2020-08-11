#include "GoToTims.h"

//
GoToTims::GoToTims(): Tile{GO_TO_TIMS} {}

//
void GoToTims::landEffect(Player* p) {
    p->move(DC_TIMS_LINE);
    updateObservers("You Go To Tims Line!");
}

