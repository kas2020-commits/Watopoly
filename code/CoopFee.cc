#include "CoopFee.h"

//
CoopFee::CoopFee() : NonProperty{COOP_FEE} {}

//
void CoopFee::applyEffect(std::shared_ptr<Player> p) {
    p->withdraw(150);
    updateObservers("You Paid $150 for coop!");
}

