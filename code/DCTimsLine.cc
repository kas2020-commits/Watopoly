#include <sstream>
#include "DCTimsLine.h"
#include "Roll.h"
#include "Debt.h"
#include "GameException.h"

//
DCTimsLineTrap::DCTimsLineTrap(Player* p) : player{p} {}

//
DCTimsLineTrap::DCTimsLineTrap() : player{nullptr} {}

//
void DCTimsLineTrap::useTimsCup() {
    player->decrementTimsCups();
    player->untrap();
}

//
void DCTimsLineTrap::pay() {
    if (player->getTurnsTrapped() == 0) { // throw a debt if on last turn,
        try { player->withdraw(50); }     // player cannot pay
        catch (GameException&) {
            if (player->getTimsCups() > 0) {
                throw GameException{"Must use Tims cup.\n"};
            }
            throw Debt{player, 50};
        }
    }
    player->withdraw(50);
    player->untrap();
}

//
void DCTimsLineTrap::roll() {
    if (player->getTurnsTrapped() == 0) {
        throw GameException{
            "Must leave Tim's line this "
            "turn, pay or use Tims cup.\n"
        };
    }
    else if (player->hasRolled())
        throw GameException{"Already rolled.\n"};
    Roll r = player->roll(true);
    if (r.isDouble()) player->untrap();
}

//
void DCTimsLineTrap::roll(int die1, int die2) {
    Roll::loadNextRoll(die1, die2);
    try { roll(); }
    catch (GameException& e) {
        Roll::discardNextRoll();
        throw e;
    }
}

//
std::string DCTimsLineTrap::getMessage() {
    std::ostringstream ss{};
    if (player->getTurnsTrapped() == 0) {
        ss << "Must leave Tims line this ";
        ss << "turn, pay or use Tims cup.\n";
    }
    else if (player->isTrapped()) {
		ss << "You are trapped in \"" << DC_TIMS_LINE;
		ss << "\" (for max. " << player->getTurnsTrapped();
        ss << " more turns). Pay $50, Use Tims cup, or ";
        ss << "roll doubles to escape.\n";
    }
    else {
        ss << "You are are no longer trapped.\n";
    }
    return ss.str();
}

//
DCTimsLine::DCTimsLine() : Tile{DC_TIMS_LINE} {}

//
void DCTimsLine::throwTrap(Player* p) {
    throw DCTimsLineTrap{p};
}

