#include <sstream>
#include "Player.h"

// static member construction
int Player::totalTimsCups {0};
std::map<const char, bool> Player::symbolChart {
	{'G', false}, {'B', false}, {'D', false}, {'P', false}, {'S', false},
		{'$', false}, {'L', false}, {'T', false}
};

//
struct Player::PlayerImpl {
	const std::string name;
	const char symbol;
	BoardIterator position;
	int cash;
	int timsCups;
	int gymCount;
	int resCount;
	bool bankrupt;
	int turnsTrapped;
	int netWorth;
	int rolled;
	PlayerImpl(const std::string name, const char symbol, BoardIterator it);
	~PlayerImpl();
};

//
Player::PlayerImpl::~PlayerImpl() {}

//
Player::PlayerImpl::PlayerImpl(const std::string name, const char symbol, BoardIterator it)
	: name{name}, symbol{symbol}, position{it}, cash{1500},
	timsCups{0}, gymCount{0}, resCount{0}, bankrupt{false}, turnsTrapped{0},
	netWorth{1500}, rolled{false}
{}

// constructor
Player::Player(const std::string name, const char symbol, BoardIterator it)
	:
		data{std::make_shared<PlayerImpl>(name, symbol, it)},
		blockCount{std::map<std::string, int>
			{{ARTS1, 0}, {ARTS2, 0}, {ENG, 0}, {HEALTH, 0}, {ENV, 0}, {SCI1, 0},
				{SCI2, 0}, {MATH, 0}}}
{
	try {
		bool & isDup = symbolChart.at(symbol);
		if (isDup) throw PlayerException();
		else isDup = true;
	}
	catch (std::out_of_range &) { throw PlayerException(); };
}

// move player:
void Player::rollAndMove() {
	Roll r = roll();
	for (int i = 0; i < r.total; ++i) {
		++data->position;
		if (i != r.total - 1) data->position->pass(this);
	}
	data->position->land(this);
	updateObservers();
}

//
void Player::move(const std::string name) {
	const std::string oldLocation { data->position->getName() };
	std::string midval;
	while (true) {
		data->position->getName();
		if (midval.compare(name) == 0) break;
		else if (midval.compare(oldLocation) == 0) throw PlayerException();
		else ++data->position;
	}
	data->position->land(this);
	updateObservers();
}

//
Roll Player::roll(moreInfo = false) {
	data->rolled = true;
	Roll r{};
	updateObservers(r.getMessage(moreInfo));
	return r;
}

//
void startTurn() {
	data->rolled = false;
	if (isTrapped) decrementTurnsTrapped();
	// reset any other turn related logic vars
}

// getters:
int Player::getResCount() { return data->resCount; }

//
int Player::getCash() { return data->cash; }

//
int Player::getGymCount() { return data->gymCount; }

//
int Player::getTimsCups() { return data->timsCups; }

//
int Player::getBlockCount(const std::string block) { return blockCount.find(block)->second; }

//
bool Player::isBankrupt() { return data->bankrupt; }

//
char Player::getSymbol() { return data->symbol; }

//
std::string Player::getName() { return data->name; }

//
Tile & Player::getPosition() { return *data->position; }

//
int Player::getTurnsTrapped() { return data->turnsTrapped; }

//
bool Player::isTrapped() { return (turnsTrapped > 0); }

//
int Player::getNetWorth() { return data->netWorth; }

// setters:
void Player::setTimsCups(int amount) {
	totalTimsCups -= data->timsCups;
	data->timsCups = amount;
	totalTimsCups += data->timsCups;
}

//
void Player::setGymCount(int amount) { data->gymCount = amount; }

//
void Player::setResCount(int amount) { data->resCount = amount; }

//
void Player::deposit(const int amount) {
	data->cash += amount;
	data->netWorth += amount;
	updateObservers("Gave $" + amount + " to " + name + ".");
}

//
void Player::withdraw(const int amount) {
	data->cash -= amount;
	data->netWorth -= amount;
	updateObservers("Withdrew $" + amount + " from " + name + ".");
}

//
void Player::changeNetWorth(int amount) {
	data->netWorth += amount;
}

//
void Player::setBankrupt() { data->bankrupt = true; }

//
void Player::untrap() { 
	data->turnsTrapped = 0;
	startTurn(); // start fresh
	updateObservers("You have been untrapped!");
}

//
void Player::trap(int turns) {
	data->turnsTrapped = turns;
	std::ostringstream ss{"You have been trapped in "};
	ss << position->getName() <<  " (for max. " << turns << " turns)!"
	updateObservers(ss.str());
}

//
void Player::decrementTurnsTrapped() {
	--(data->turnsTrapped)
	if (turnsTrapped <= 0) untrap(); // start fresh
	else {
		std::ostringstream ss{"You are sill trapped in "};
    	ss << position->getName() << "(for max. ";
    	ss << data->turnsTrapped << " more turns).\n";
		updateObservers(ss.str());
	}
}

// static methods:
int Player::getTotalTimsCups() { return totalTimsCups; }

//
void Player::addTimsCup() {
	if (data->timsCups + 1 > 4 || totalTimsCups + 1 > 4) throw PlayerException();
	++data->timsCups;
	--totalTimsCups;
}

//
void Player::removeTimsCup() {
	if (data->timsCups - 1 < 0 || totalTimsCups - 1 < 0) throw PlayerException();
	--data->timsCups;
	++totalTimsCups;
}