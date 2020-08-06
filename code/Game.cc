#include "Game.h"
#include "BoardIterator.h"

// Constructor
Game::Game() : board{std::make_unique<Board>{}}, started{false} {
    curPlayer = players.begin();
}

// destructor
Game::~Game() {}

// virtual override of subject class, attaches subject members to Observer
Game::attachMembers(Observer* ob) {
    for (auto it = players.begin(); it != player.end(); it++) it->attach(ob);
    for (auto it = board->begin(); it != board->end(); it++) it->attach(ob);
}

// adds a player to the game
void Game::addPlayer(std::shared_ptr<Player> p) {
    auto p = std::shared_ptr<Player>();
    players[p->getName()] = p;
    attachObservers(p.get());
}

// bankrupts a player, i.e, removes them
void Game::bankruptPlayer() {
    //implement this
}

// starts "game", all players must be added before game started
std::shared_ptr<Player> Game::start() {
    start = true;
    curPlayer = players.begin();
    return *curPlayer;
}

//
std::shared_ptr<Player> Game::nextTurn() {
    curPlayer++;
    if (curPlayer == players.end()) curPlayer = players.begin();
    return *curPlayer;
}