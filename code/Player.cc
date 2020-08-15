#include <sstream>
#include "GameException.h"
#include "Player.h"


// static member construction
int Player::totalTimsCups {0};

std::map<const char, bool> Player::symbolChart
{
	{'G', false}, {'B', false}, {'D', false}, {'P', false}, {'S', false},
		{'$', false}, {'L', false}, {'T', false}
};

/* // */
/* PlayerData::PlayerData (const std::string name, const char symbol, BoardIterator it) */
/* 	: name{name}, symbol{symbol}, position{it}, cash{1500}, */
/* 	timsCups{0}, gymCount{0}, resCount{0}, bankrupt{false}, turnsTrapped{0}, */
/* 	netWorth{1500}, rolled{false} */
/* {} */

// constructor
Player::Player(const std::string name, const char symbol, BoardIterator it)
	:
		// simple fields
		name{name}, symbol{symbol}, position{it}, cash{1500},
	timsCups{0}, gymCount{0}, resCount{0}, bankrupt{false}, turnsTrapped{0},
	netWorth{1500}, rolled{false},

	// blockCount
	blockCount{std::map<std::string, int> {
		{ARTS1, 0}, {ARTS2, 0}, {ENG, 0}, {HEALTH, 0}, {ENV, 0}, {SCI1, 0}, {SCI2, 0}, {MATH, 0}}}
{
	bool & isDup = symbolChart.at(symbol);
	if (isDup) throw GameException{"Symbol already in use."};
	else isDup = true;
}

// move player:
void Player::rollAndMove() {
	Roll r = roll();
	for (int i = 0; i < r.total; ++i) {
		++position;
		if (i != r.total - 1) position->pass(this);
	}
	position->land(this);
	updateObservers();
}

void Player::move(int amount)
{
	if (amount > 0) {
		while (amount != 0) {
			++position; --amount;
		}}
	else if (amount < 0) {
		while (amount != 0) {
			--position; ++amount;
		}}
	else {}
}

//
void Player::move(const std::string name) {
	BoardIterator newPosition { position };
	while (true) {
		++newPosition;
		if (newPosition->getName() == name) break;
		if (newPosition == position)
			throw GameException{"Fatal Error Occured."};
	}
	position = newPosition;
	position->land(this);
	updateObservers();
}

//
Roll Player::roll(bool moreInfo) {
	Roll r{};
	rolled = true;
	updateObservers(r.getMessage(moreInfo));
	return r;
}

//
void Player::startTurn() {
	rolled = false;
	if (isTrapped()) {
		decrementTurnsTrapped();
		std::ostringstream ss{"You are trapped in "};
		ss << position->getName() << "(for max. ";
		ss << turnsTrapped << " more turns).\n";
		updateObservers(ss.str());
		position->throwTrap(this);
	}
	// reset any other turn related logic vars
}

// getters:
int Player::getResCount() { return resCount; }

//
int Player::getCash() { return cash; }

//
int Player::getGymCount() { return gymCount; }

//
int Player::getTimsCups() { return timsCups; }

//
int Player::getBlockCount(const std::string block) { return blockCount.find(block)->second; }

//
bool Player::isBankrupt() { return bankrupt; }

//
char Player::getSymbol() { return symbol; }

//
std::string Player::getName() { return name; }

//
Tile & Player::getPosition() { return *position; }

//
int Player::getTurnsTrapped() { return turnsTrapped; }

//
bool Player::isTrapped() { return (turnsTrapped > 0); }

//
int Player::getNetWorth() { return netWorth; }

//
bool Player::hasRolled() { return rolled; }

// setters:
void Player::setTimsCups(int amount) {
	totalTimsCups -= timsCups;
	timsCups = amount;
	totalTimsCups += timsCups;
}

//
void Player::setGymCount(int amount) { gymCount = amount; }

//
void Player::setResCount(int amount) { resCount = amount; }

//
void Player::deposit(const int amount) {
	cash += amount;
	netWorth += amount;
}

//
void Player::withdraw(const int amount) {
	if (cash < amount)
		throw GameException{"Insufficient Funds."};
	cash -= amount;
	netWorth -= amount;
}

//
void Player::changeNetWorth(int amount) {
	netWorth += amount;
}

//
void Player::setBankrupt() {
	bankrupt = true;
}

//
void Player::untrap() {
	turnsTrapped = 0;
	startTurn(); // start fresh
	updateObservers("You have been untrapped!");
}

//
void Player::trap(int turns) {
	turnsTrapped = turns;
	std::ostringstream ss{"You have been trapped in "};
	ss << position->getName() <<  " (for max. " << turns << " turns)!";
	updateObservers(ss.str());
}

//
void Player::decrementTurnsTrapped() {
	if (turnsTrapped <= 0) --(turnsTrapped);
}

// static methods:
int Player::getTotalTimsCups() { return totalTimsCups; }

//
void Player::incrementTimsCups() {
	if (totalTimsCups <= 0)
		throw GameException{"Tims cups at max. capacity."};
	++timsCups;
	--totalTimsCups;
}

//
void Player::decrementTimsCups() {
	if (timsCups <= 0)
		throw GameException{"No Tims cups."};
	--timsCups;
	++totalTimsCups;
}

//
void Player::incrementGymCount() { ++gymCount; }

//
void Player::decrementGymCount() { --gymCount; }

//
void Player::incrementResCount() { ++resCount; }

//
void Player::decrementResCount() { --resCount; }

//
void Player::incrementBlockCount(std::string name) {
	++(blockCount[name]);
}

//
void Player::decrementBlockCount(std::string name) {
	--(blockCount[name]);
}

