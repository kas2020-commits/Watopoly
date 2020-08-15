#include "DCTimsLine.h"
#include "Roll.h"

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
    if (player->getTurnsTrpped() == 0) {
        throw GameException{"Must leave Tim's line 
          this turn, pay or use Tims cup.\n"};
    }
    else if (player->hasRolled()) 
        throw GameException{"Already rolled.\n"};
    Roll r = player->roll(true);
    if (r.isDouble()) player->untrap();
}

//
void DCTimsLineTrap::roll(int die1, int die2) {
    Roll::loadNextRoll(die1, die2);
    try () { roll(); }
    catch (GameException& e) { 
        Roll::discardNextRoll();
        throw e;
    }
}

//
DCTimsLine::DCTimsLine() : Tile{DC_TIMS_LINE} {}

//
void DCTimsLine::throwTrap(Player* p) {
    throw DCTimsLineTrap trap{p};
}