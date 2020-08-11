#include <sstream>
#include <string>
#include "DCTimsLine.h"

//
DCTimsLineTrapped::DCTimsLineTrapped(Player* p) : 
  Trapped {p, ""} {
    p->decrementTurnsTrapped();
    std::ostringstream ss{""};
    ss << "You are trapped in the DC Tims line (for max ";
    ss << p->getTurnsTrapped() << " more turns).";
    message = ss.str();
}

//
void DCTimsLineTrapped::useTimsCup() {
    player->removeTimsCup();
    player->untrap();
}

//
void DCTimsLineTrapped::payCash() {
    player->withdraw(50);
    player->untrap();
}

//
void DCTimsLineTrapped::roll() {
    int die1 = rollDie();
    int die2 = rollDie();
    std::ostringstream ss{""};
    ss << "You rolled: " << die1 << " & " << die2 << ".\n";
    if (die1 == die2) {
        ss << "You rolled a double (rolled " << die1 << "&" << die2 << ")";
        updateObservers(ss.str());
        player->untrap();
    }
    else {
        ss << "You didn't roll a double (rolled " << die1 << "&" << die2 << ")";
        updateObservers(ss.str());
    }
}

//
DCTimsLine::DCTimsLine() : Tile{DC_TIMS_LINE} {}

//
void DCTimsLine::throwTrapped(Player* p) {
    throw DCTimsLineTrapped{p};
}