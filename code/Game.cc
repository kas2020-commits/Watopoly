#include "Game.h"
#include "Board.h"
#include "util.h"

// Constructor
Game::Game() : board{std::make_unique<Board>()}, started{false}, rolled{false} {
    curPlayer = players.begin();
}

// destructor
Game::~Game() {}

// virtual override of subject class, attaches subject members to Observer
void Game::attachMembers(Observer* ob) {
    for (auto it = players.begin(); it != players.end(); it++) it->second->attach(ob);
    for (auto it = board->begin(); it != board->end(); it++) it->attach(ob);
}

//
bool Game::isPlayer(std::string name) { return (players.count(name) > 0); }

//
bool Game::isProperty(std::string name) {
    for (auto it = board->begin(); it != board->end(); it++) {
        if (it->isProperty() && it->getName() == name) return true;
    }
    return false;
}

// adds a player to the game
void Game::addPlayer(std::string name, char symbol) {
    if (started) throw GameException{"Can't add players after game has started."};
    auto p = std::make_shared<Player>(name, symbol, board->begin(true));
    players[p->getName()] = p;
    attachObservers(p.get());
}

// starts "game", all players must be added before game started
void Game::start() {
    if (started) throw GameException{"Game already started."};
    curPlayer = players.end();
    started = true;
    next();
}

void Game::roll() {
    if (rolled) throw GameException{"Already rolled."};
    int distance = rollDie() + rollDie();
    curPlayer->second->move(distance);
    rolled = true;
}

//
void Game::next() {
    while (true) {
        curPlayer++;
        if (curPlayer == players.end()) curPlayer = players.begin();
        if (!curPlayer->second->isBankrupt()) break;
    }
    rolled = false;
    updateObservers("Current turn: " + curPlayer->first);
}

//
void Game::trade(std::string name, std::string giveProp, std::string receiveProp) {}

//
void Game::trade(std::string name, std::string giveProp, int receiveCash) {}

//
void Game::trade(std::string name, int giveCash, std::string receiveProp) {}

//
void Game::mortgage(std::string prop) {
    board->at(prop).mortgage(curPlayer->second);
}

//
void Game::unmortgage(std::string prop) {
    board->at(prop).unmortgage(curPlayer->second);
}

//
void Game::buyImprovement(std::string prop) {
    board->at(prop).buyImprovement(curPlayer->second);
}

//
void Game::sellImprovement(std::string prop) {
    board->at(prop).sellImprovement(curPlayer->second);
}

//
void Game::bankrupt() {
    curPlayer->second->setBankrupt();
    next();
}

//
void Game::assets(std::string name) {
    for (auto it = board->begin(); it != board->end(); it++) {
        // implement this
    }
}

//
void Game::all() {
    for (auto it = players.begin(); it != players.end(); it++) {
        assets(it->first);
    }
}