#include <iostream>
#include <sstream>
#include "AcademicBuilding.h"
#include "Board.h"
#include "Game.h"
#include "Gym.h"
#include "Property.h"
#include "Residence.h"
#include "util.h"

// Constructor
Game::Game() : board{std::make_unique<Board>()}, started{false}, rolled{false} {
    curPlayer = players.begin();
}

// destructor
Game::~Game() {}

// virtual override of subject class, attaches subject members to Observer
void Game::attachMembers(Observer* ob) {
    for (auto it = players.begin(); it != players.end(); ++it) it->second->attach(ob);
    for (auto it = board->begin(); it != board->end(); ++it) it->attach(ob);
}

//
bool Game::isPlayer(std::string name) { return (players.count(name) > 0); }

//
bool Game::isProperty(std::string name) {
    for (auto it = board->begin(); it != board->end(); ++it) {
        if (it->isProperty() && it->getName() == name) return true;
    }
    return false;
}

//
bool Game::isAcademicBuilding(std::string name) {
    for (auto it = board->begin(); it != board->end(); ++it) {
        if (it->isAcademicBuilding() && it->getName() == name) return true;
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

//
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
void Game::mortgage(std::string name) {
    Property* pr = static_cast<Property*>(&(board->at(name)));
    if (!pr) throw GameException("\"" + name + "\" is not a valid property.");
    pr->mortgage(curPlayer->second.get());
}

//
void Game::unmortgage(std::string name) {
    Property* pr = static_cast<Property*>(&(board->at(name)));
    if (!pr) throw GameException("\"" + name + "\" is not a valid property.");
    pr->unmortgage(curPlayer->second.get());
}

//
void Game::buyImprovement(std::string name) {
    AcademicBuilding* ab = static_cast<AcademicBuilding*>(&(board->at(name)));
    if (ab) throw GameException("\"" + name + "\" is not a valid academic building.");
    ab->buyImprovement(curPlayer->second.get());
}

//
void Game::sellImprovement(std::string name) {
    AcademicBuilding* ab = static_cast<AcademicBuilding*>(&(board->at(name)));
    if (!ab) throw GameException("\"" + name + "\" is not a valid academic building.");
    ab->sellImprovement(curPlayer->second.get());
}

//
void Game::bankrupt() {
    curPlayer->second->setBankrupt();
    next();
}

//
void Game::assets(std::string name) {
    //
    std::vector<AcademicBuilding*> ownedABs{};
    std::vector<Residence*> ownedResidences{};
    std::vector<Gym*> ownedGyms{};

    //
    for (auto it = board->begin(); it != board->end(); ++it) {
        Property* pr = dynamic_cast<Property*>(&(*it));
        if (!pr) continue; // cotinue to next tile if not a property
        AcademicBuilding* ab = dynamic_cast<AcademicBuilding*>(pr);
        if (ab) {
            if (ab->getOwner()->getName() == name) ownedABs.emplace_back(ab);
            continue;
        }
        Residence* r = dynamic_cast<Residence*>(pr);
        if (r) {
            if (r->getOwner()->getName() == name) ownedResidences.emplace_back(r);
            continue;
        }
        Gym* g = dynamic_cast<Gym*>(pr);
        if (g) {
            if (g->getOwner()->getName() == name) ownedGyms.emplace_back(g);
            continue;
        }
    }

    //
    std::stringstream ss{""};
    ss << "Player: " << name << "\n";
    ss << "Total Tims Cups: " << players[name]->getTimsCups() << "\n";
    ss << "Owned Academic Buildings:\n";
    if (ownedABs.size() <= 0) ss << "\tNone\n";
    else {
        for (int i = 0; i < ownedABs.size(); i++) {
            ss << "\t" << i + ". " << ownedABs[i]->getName() << "\n";
            ss << "\t\tImprovements: " << ownedABs[i]->getImprovementLevel() << "\n";
        }
    }
    ss << "Owned Residences:\n";
    if (ownedResidences.size() <= 0) ss << "\tNone\n";
    else {
        for (int i = 0; i < ownedResidences.size(); i++) {
            ss << "\t" << i << ". " << ownedResidences[i]->getName() << "\n";
        }
    }
    ss << "Owned Gyms:\n";
    if (ownedGyms.size() <= 0) ss << "\tNone\n";
    else { 
        for (int i = 0; i < ownedGyms.size(); i++) {
            ss << "\t" << i << ". " << ownedGyms[i]->getName() << "\n";
        }
    }
    
    //
    updateObservers(ss.str());
}

//
void Game::assets() { assets(curPlayer->second->getName()); }

//
void Game::all() {
    for (auto it = players.begin(); it != players.end(); it++) {
        assets(it->first);
    }
}
