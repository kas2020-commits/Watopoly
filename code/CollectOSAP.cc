#include "CollectOSAP.h"

//
CollectOSAP::CollectOSAP() : NonProperty() {}

//
void CollectOSAP::land(std::shared_ptr<Player> p) {}

//
void CollectOSAP::pass(std::shared_ptr<Player> p) {
    applyEffect(p);
}

//
void CollectOSAP::applyEffect(std::shared_ptr<Player> p){
    p->deposit(200);
    updateObservers("You get OSAP $200 !");
}

