#include "CollectOSAP.h"

//
CollectOSAP::CollectOSAP() : Tile{COLLECT_OSAP} {}

//
void CollectOSAP::landEffect(Player* p) {
    p->deposit(400);
    updateObservers("You get $400 for landing on OSAP!");
}

//
void CollectOSAP::pass(Player* p) {
    p->deposit(200);
    updateObservers("You get $200 for passing OSAP!");
}

