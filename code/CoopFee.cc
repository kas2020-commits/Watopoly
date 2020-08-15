#include "CoopFee.h"

//
CoopFee::CoopFee() : Tile{COOP_FEE} {}

//
void CoopFee::landEffect(Player* p) {
    p->withdraw(150);
    updateObservers("You Paid $150 for coop!");
}

