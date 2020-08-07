#include "CollectOSAP.h"

//
CollectOSAP::CollectOSAP() : NonProperty{COLLECT_OSAP} {}

//
void CollectOSAP::land(std::shared_ptr<Player> p) {}

//
void CollectOSAP::pass(std::shared_ptr<Player> p) {
    p->deposit(200);
    updateObservers("You get OSAP $200 !");
}

