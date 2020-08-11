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
    int die1 = rollDie();
    int die2 = rollDie();
    std::ostringstream os{""};
    if (die1 == die2) player->untrap();
}

//
DCTimsLine::DCTimsLine() : Tile{DC_TIMS_LINE} {}