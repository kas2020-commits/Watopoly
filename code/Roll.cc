#include <sstream>
#include "Roll.h"
#include "util.h"

//
Roll nextRoll = Roll{};

//
bool nextRollLoaded = false;

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
        nextRollLoaded = false;
    }
}

//
Roll::Roll(int die1, int die2) : die1{die1}, die2{die2},
    total{die1 + die2} {}

//
loadNextRoll(int die1, die2) {
    nextRoll = Roll{die1, die2};
    nextRollLoaded = true;
}

//
discardNextRoll() { nextRollLoaded = false; }

//
bool Roll:isDouble() { return (die1 == die2); }

//
std::string getMessage(moreInfo = false) {
    std::ostringstream ss{""};
    ss << "You rolled: " << r.die1 << " + " << r.die2 << " = " << r.total;
    if (!moreInfo) return ss.str() + "\n";
    if (isDouble()) << ", a double!\n";
    else ss << ", not a double.\n"
    return ss.str();
}