#include <sstream>
#include "Roll.h"
#include "util.h"

//
Roll::Roll() die1{getRand(1, 6)}, die2{getRand(1, 6)},
  total{die1 + die2} {
    std::ostringstream ss{""};
    ss << "You rolled: " << r.die1 << " + " << r.die2 << " = " << r.total << "\n";
    message = ss.str();
}

//
bool Roll:isDouble() { return (die1 == die2); }

//
std::string getMessage(moreInfo = false) {
    if (!moreInfo) return message;
    std::ostringstream ss{""};
    ss << message;
    if (isDouble()) << "A double!\n";
    else ss << "Not a double.\n"
    return ss.str();
}