#include "Tuition.h"
#include <iostream>
#include <string>
#include <sstream>

//
TuitionPayment::TuitionPayment() : player{nullptr}, payed{false} {}

//
TuitionPayment::TuitionPayment(Player* p) : player{p}, payed{false} {}

//
void TuitionPayment::payCash() {
    player->withdraw(300);
    payed = true;
}

//
void TuitionPayment::payPercent() {
    player->withdraw(player->getNetWorth() / 10);
    payed = true;
}

//
void TuitionPayment::bankrupt() {
    int cash = player->getCash();
    if (cash >= 300 || cash >= player->getNetWorth()) {
        throw GameException{
            "You are able to pay tuition with one of the "
            "payment options, no reason to go bankrupt."
        };
    }
    // otherwise, allow bankruptcy
    player->setBankrupt();
}

//
std::string TuitionPayment::getMessage() {
    std::ostringstream ss{};
    if (!payed) ss << "Must pay tuition. Can either pay $300 or 10% net worth.\n";
    else ss << "You are have payed your tuition!\n";
    return ss.str();
}

//
Tuition::Tuition() : Tile{TUITION} {}

//
void Tuition::landEffect(Player* p){
    throw TuitionPayment(p);
}

