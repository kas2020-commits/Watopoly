#include <sstream>
#include "Roll.h"
#include "util.h"

//
Roll Roll::nextRoll = Roll{};

//
bool Roll::nextRollLoaded = false;

//
Roll::Roll() {
    if (!nextRollLoaded) {
        die1 = getRand(1, 6);
        die2 = getRand(1, 6);
        total = die1 + die2;
    }
    else {
        die1 = nextRoll.die1;
        die2 = nextRoll.die2;
        total = nextRoll.total;
        discardNextRoll();
    }
}

//
Roll::Roll(int die1, int die2) : die1{die1}, die2{die2},
    total{die1 + die2} {}

//
void Roll::loadNextRoll(int die1, int die2) {
    nextRoll = Roll{die1, die2};
    nextRollLoaded = true;
}

//
void Roll::discardNextRoll() { nextRollLoaded = false; }

//
bool Roll::isDouble() { return (die1 == die2); }

//
std::string Roll::getMessage(bool moreInfo) {
    std::ostringstream ss{};
    ss << "You rolled: " << die1 << " + " << die2 << " = " << total;
    if (!moreInfo) return ss.str() + "\n";
    if (isDouble()) ss << ", a double!\n";
    else ss << ", not a double.\n";
    return ss.str();
}

