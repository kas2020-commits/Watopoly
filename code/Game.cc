#include <iostream>
#include <sstream>
#include "AcademicBuilding.h"
#include "Board.h"
#include "Game.h"
#include "GameException.h"
#include "Gym.h"
#include "Property.h"
#include "Residence.h"
#include "Roll.h"
#include "util.h"

// Constructor
Game::Game()
	: board{std::make_unique<Board>()}, started{false}
{
	curPlayer = players.begin();
}

// destructor
Game::~Game() {}

// virtual override of subject class, attaches subject members to Observer
void Game::attachMembers(Observer* ob) {
	for (auto it = players.begin(); it != players.end(); ++it) (*it)->attach(ob);
	for (auto it = board->begin(); it != board->end(); ++it) it->attach(ob);
}

// adds a player to the game
void Game::addPlayer(std::string name, char symbol) {
	if (started) throw GameException{"Can't add players after game has started.\n"};
	auto p = std::make_shared<Player>(name, symbol, board->begin(true));
	players.emplace_back(p);
	attachObservers(p.get());
	updateObservers("Added player \"" + name + "\" to the game!\n");
}

// adds a player to the game
std::shared_ptr<Player> Game::getPlayer(std::string name) {
	for (auto it = players.begin(); it != players.end(); it++) {
		if ((*it)->getName() == name) return *it;
	}
	return nullptr;
}

// starts "game", all players must be added before game started
void Game::start() {
	if (started) throw GameException{"Game already started.\n"};
	curPlayer = players.end() - 1;
	started = true;
	next();
}

//
void Game::roll() {
	if ((*curPlayer)->hasRolled()) throw GameException{"Already rolled.\n"};
	(*curPlayer)->rollAndMove();
}

void Game::roll(int die1, int die2) {
	Roll::loadNextRoll(die1, die2);
	try { roll(); }
	catch (GameException& e) {
		Roll::discardNextRoll();
		throw e;
	}
}

//
void Game::next() {
	while (true) {
		curPlayer++;
		if (curPlayer == players.end()) curPlayer = players.begin();
		if (!(*curPlayer)->isBankrupt()) break;
	}
	updateObservers("Current turn: " + (*curPlayer)->getName() + "\n");
	(*curPlayer)->startTurn();
}

//
void Game::trade(std::string name, std::string giveProp, std::string receiveProp) {
	// exception checking:
	auto otherPlayer = getPlayer(name);
	if (!otherPlayer) throw GameException{"\"" + name + "\" is not a valid player.\n"};
	Property* gpr = dynamic_cast<Property*>(&(board->at(giveProp)));
	if (!gpr) throw GameException{"\"" + giveProp +  "\" is not a valid property.\n"};
	if (!gpr->isOwner(curPlayer->get()))
		throw GameException{"You do not own \"" + giveProp + "\".\n"};
	Property* rpr = dynamic_cast<Property*>(&(board->at(receiveProp)));
	if (!rpr) throw GameException{"\"" + receiveProp +  "\" is not a valid property.\n"};
	if (!rpr->isOwner(curPlayer->get()))
		throw GameException{"Player \"" + name
			+ "\" does not own \"" + receiveProp + "\".\n"};
	// trade is valid
	gpr->setOwner(otherPlayer.get());
	rpr->setOwner(curPlayer->get());
}

//
void Game::trade(std::string name, std::string giveProp, int receiveCash) {
	// exception checking:
	auto otherPlayer = getPlayer(name);
	if (!otherPlayer) throw GameException{"\"" + name +
		"\" is not a valid player.\n"};
	Property* gpr = dynamic_cast<Property*>(&(board->at(giveProp)));
	if (!gpr) throw GameException{"\"" + giveProp +  "\" is not a valid property.\n"};
	if (!gpr->isOwner(curPlayer->get()))
		throw GameException{"You do not own \"" + giveProp + "\".\n"};
	otherPlayer->withdraw(receiveCash); // will throw exception if insufficient funds
	// trade is valid
	(*curPlayer)->deposit(receiveCash);
	gpr->setOwner(otherPlayer.get());
}

//
void Game::trade(std::string name, int giveCash, std::string receiveProp) {
	// exception checking:
	auto otherPlayer = getPlayer(name);
	if (!otherPlayer) throw GameException{"\"" + name
		+ "\" is not a valid player.\n"};
	Property* rpr = dynamic_cast<Property*>(&(board->at(receiveProp)));
	if (!rpr) throw GameException{"\"" + receiveProp +  "\" is not a valid property.\n"};
	if (!rpr->isOwner(curPlayer->get()))
		throw GameException{"Player \"" + name
			+"\" does not own \"" + receiveProp + "\"."};
	(*curPlayer)->withdraw(giveCash);
	// trade is valid
	otherPlayer->deposit(giveCash);
	rpr->setOwner(curPlayer->get());
}

//
void Game::mortgage(std::string name) {
	Property* pr = dynamic_cast<Property*>(&(board->at(name)));
	if (!pr) throw GameException("\"" + name + "\" is not a valid property.\n");
	if (pr->isOwner(curPlayer->get())) pr->mortgage();
	else throw GameException{"You do not own \"" + name + "\".\n"};
}

//
void Game::unmortgage(std::string name) {
	Property* pr = dynamic_cast<Property*>(&(board->at(name)));
	if (!pr) throw GameException("\"" + name + "\" is not a valid property.\n");
	if (pr->isOwner(curPlayer->get())) pr->unmortgage();
	else throw GameException{"You do not own \"" + name + "\".\n"};
}

//
void Game::buyImprovement(std::string name) {
	AcademicBuilding* ab = dynamic_cast<AcademicBuilding*>(&(board->at(name)));
	if (ab) throw GameException("\"" + name + "\" is not a valid academic building.\n");
	if (ab->isOwner(curPlayer->get())) ab->buyImprovement();
	else throw GameException{"You do not own \"" + name + "\".\n"};
}

//
void Game::sellImprovement(std::string name) {
	AcademicBuilding* ab = dynamic_cast<AcademicBuilding*>(&(board->at(name)));
	if (!ab) throw GameException("\"" + name + "\" is not a valid academic building.\n");
	if (ab->isOwner(curPlayer->get())) ab->sellImprovement();
	else throw GameException{"You do not own \"" + name + "\".\n"};
}

//
void Game::assets(std::shared_ptr<Player> p) {
	std::string name = p->getName();

	//
	std::vector<AcademicBuilding*> ownedABs{};
	std::vector<Residence*> ownedResidences{};
	std::vector<Gym*> ownedGyms{};

	//
	for (auto it = board->begin(); it != board->end(); ++it) {
		auto pr = dynamic_cast<Property*>(&(*it));
		if (!pr || pr->hasOwner()) continue; // cotinue to next tile if not a property
		AcademicBuilding* ab = dynamic_cast<AcademicBuilding*>(pr);
		if (ab) {
			if (ab->isOwner(p.get())) ownedABs.emplace_back(ab);
			continue;
		}
		Residence* r = dynamic_cast<Residence*>(pr);
		if (r) {
			if (r->isOwner(p.get())) ownedResidences.emplace_back(r);
			continue;
		}
		Gym* g = dynamic_cast<Gym*>(pr);
		if (g) {
			if (g->isOwner(p.get())) ownedGyms.emplace_back(g);
			continue;
		}
	}

	//
	std::ostringstream ss{""};
	ss << "Player: " << name << "\n";
	ss << "\tTotal Tims Cups: " << p->getTimsCups() << "\n";
	ss << "\tOwned Academic Buildings:\n";
	if (ownedABs.size() <= 0) ss << "\t\tNone\n";
	else {
		for (size_t i = 0; i < ownedABs.size(); i++) {
			ss << "\t\t" << i <<  ". " << ownedABs[i]->getName() << "\n";
			ss << "\t\t\tImprovements: " << ownedABs[i]->getImprovementLevel() << "\n";
		}
	}
	ss << "\tOwned Residences:\n";
	if (ownedResidences.size() <= 0) ss << "\t\tNone\n";
	else {
		for (size_t i = 0; i < ownedResidences.size(); i++) {
			ss << "\t\t" << i << ". " << ownedResidences[i]->getName() << "\n";
		}
	}
	ss << "\tOwned Gyms:\n";
	if (ownedGyms.size() <= 0) ss << "\t\tNone\n";
	else {
		for (size_t i = 0; i < ownedGyms.size(); i++) {
			ss << "\t\t" << i << ". " << ownedGyms[i]->getName() << "\n";
		}
	}

	//
	updateObservers(ss.str());
}

//
void Game::assets() { assets(*curPlayer); }

//
void Game::all() {
	for (auto it = players.begin(); it != players.end(); it++) {
		assets(*it);
	}
}

//
void Game::populateAuction(Auction& au) {
	for (auto it = players.begin(); it != players.end(); it++) {
		au.addBidder((*it)->getName(), it->get());
	}
}
