#include <sstream>
#include <string>
#include "DCTimsLine.h"

//
DCTimsLineTrapped::DCTimsLineTrapped(Player* p) : 
  Trapped {p, "You are trapped in the DC Tims line."} {}

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
    /*int die1 = rollDie();
    int die2 = rollDie();
    std::ostringstream ss{""};
    ss << "You rolled: " << die1 << " & " << die2 << ".\n";
    if (die1 == die2) {
        ss << "You rolled a double (rolled " << die1 << "&" << die2 << ")";
        player->untrap();
    }
    else {

    }*/
}

//
DCTimsLine::DCTimsLine() : Tile{DC_TIMS_LINE} {}