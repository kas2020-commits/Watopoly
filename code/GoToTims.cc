#include "GoToTims.h"

//
GoToTims::GoToTims(): Tile{GO_TO_TIMS} {}

//
void GoToTims::landEffect(Player* p) {
    updateObservers("You go to Tims line!");
    p->move(DC_TIMS_LINE);
    p->trap(4);
}
