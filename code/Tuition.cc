#include "Tuition.h"
#include <iostream>
#include <string>

//
TuitionPayment::TuitionPayment() : player{nullptr} {}

//
TuitionPayment::TuitionPayment(Player* p) : player{p} {}

//
void TuitionPayment::payCash() {
    player->withdraw(300);
}

//
void TuitionPayment::payPercent() {
    player->withdraw(player->getNetWorth() / 10);
}

//
void TuitionPayment::bankrupt() {
    int cash = player->getCash();
    if (cash >= 300 || cash >= player->getNetWorth()) {
        throw GameException{"You can pay tuition with one of the payment options, no reason to go bankrupt."};
    }
    // otherwise, allow bankruptcy
    player->setBankrupt();
}

//
Tuition::Tuition() : Tile{TUITION} {}

//
void Tuition::landEffect(Player* p){
    throw TuitionPayment(p);
}

