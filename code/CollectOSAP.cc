#include "CollectOSAP.h"

//
CollectOSAP::CollectOSAP() : NonProperty{COLLECT_OSAP} {}

//
void CollectOSAP::land(Player* p) {}

//
void CollectOSAP::pass(Player* p) {
    p->deposit(200);
    updateObservers("You get OSAP $200 !");
}

