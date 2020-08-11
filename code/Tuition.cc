#include "Tuition.h"
#include <iostream>
#include <string>

//
TuitionPayment::TuitionPayment(Player* p) : player{p} {}

//
void TuitionPayment::payCash() {
    player->withdraw(300);
}

//
void TuitionPayment::payPercent() {
    int netWorth = player->getNetWorth();
    player->withdraw(netWorth / 10);
}

//
Tuition::Tuition() : Tile{TUITION} {}

//
void Tuition::landEffect(Player* p){
    throw TuitionPayment(p);
}