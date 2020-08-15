#include "DCTimsLine.h"

//
DCTimsLineTrap::DCTimsLineTrap(Player* p) : player{p} {}

//
DCTimsLineTrap::DCTimsLineTrap() : player{nullptr} {}

//
void DCTimsLineTrap::useTimsCup() {
    player->decrementTimsCup();
    player->untrap();
}

//
void DCTimsLineTrap::payCash() {
    player->withdraw(50);
    player->untrap();
}

//
void DCTimsLineTrap::roll() {
    Roll r = p->roll(true);
    if (r.isDouble()) player->untrap();
}

//
DCTimsLine::DCTimsLine() : Tile{DC_TIMS_LINE} {}

//
void DCTimsLine::throwTrap(Player* p) {
    throw DCTimsLineTrap trap{p};
}