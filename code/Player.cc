#include <sstream>
#include "GameException.h"
#include "Player.h"


// static member construction
int Player::totalTimsCups {0};
std::map<const char, bool> Player::symbolChart {
	{'G', false}, {'B', false}, {'D', false}, {'P', false}, {'S', false},
		{'$', false}, {'L', false}, {'T', false}
};

//
Player::PlayerData::PlayerData
(const std::string name, const char symbol, BoardIterator it)
	: name{name}, symbol{symbol}, position{it}, cash{1500},
	timsCups{0}, gymCount{0}, resCount{0}, bankrupt{false}, turnsTrapped{0},
	netWorth{1500}, rolled{false} {}

	// constructor
	Player::Player(const std::string name, const char symbol, BoardIterator it) :
		data{name, symbol, it}, blockCount{std::map<std::string, int> {
			{ARTS1, 0}, {ARTS2, 0}, {ENG, 0}, {HEALTH, 0}, {ENV, 0}, {SCI1, 0}, {SCI2, 0}, {MATH, 0}}} {
																										   bool & isDup = symbolChart.at(symbol);
																										   if (isDup) throw GameException{"Symbol already in use."};
																										   else isDup = true;
																									   }

// move player:
void Player::rollAndMove() {
	Roll r = roll();
	for (int i = 0; i < r.total; ++i) {
		++data.position;
		if (i != r.total - 1) data.position->pass(this);
	}
	data.position->land(this);
	updateObservers();
}

void Player::move(int amount)
{
	if (amount > 0) {
		while (amount != 0) {
			++data.position; --amount;
		}}
	else if (amount < 0) {
		while (amount != 0) {
			--data.position; ++amount;
		}}
	else {}
}

//
void Player::move(const std::string name) {
	BoardIterator newPosition { data.position };
	while (true) {
		++newPosition;
		if (newPosition->getName() == name) break;
		if (newPosition == data.position)
			throw GameException{"Fatal Error Occured."};
	}
	data.position = newPosition;
	data.position->land(this);
	updateObservers();
}

//
Roll Player::roll(bool moreInfo) {
	Roll r{};
	data.rolled = true;
	updateObservers(r.getMessage(moreInfo));
	return r;
}

//
void Player::startTurn() {
	data.rolled = false;
	if (isTrapped()) {
		decrementTurnsTrapped();
		std::ostringstream ss{"You are trapped in "};
		ss << data.position->getName() << "(for max. ";
		ss << data.turnsTrapped << " more turns).\n";
		updateObservers(ss.str());
		data.position->throwTrap(this);
	}
	// reset any other turn related logic vars
}

// getters:
int Player::getResCount() { return data.resCount; }

//
int Player::getCash() { return data.cash; }

//
int Player::getGymCount() { return data.gymCount; }

//
int Player::getTimsCups() { return data.timsCups; }

//
int Player::getBlockCount(const std::string block) { return blockCount.find(block)->second; }

//
bool Player::isBankrupt() { return data.bankrupt; }

//
char Player::getSymbol() { return data.symbol; }

//
std::string Player::getName() { return data.name; }

//
Tile & Player::getPosition() { return *data.position; }

//
int Player::getTurnsTrapped() { return data.turnsTrapped; }

//
bool Player::isTrapped() { return (data.turnsTrapped > 0); }

//
int Player::getNetWorth() { return data.netWorth; }

// setters:
void Player::setTimsCups(int amount) {
	totalTimsCups -= data.timsCups;
	data.timsCups = amount;
	totalTimsCups += data.timsCups;
}

//
void Player::setGymCount(int amount) { data.gymCount = amount; }

//
void Player::setResCount(int amount) { data.resCount = amount; }

//
void Player::deposit(const int amount) {
	data.cash += amount;
	data.netWorth += amount;
}

//
void Player::withdraw(const int amount) {
	if (data.cash < amount)
		throw GameException{"Insufficient Funds."};
	data.cash -= amount;
	data.netWorth -= amount;
}

//
void Player::changeNetWorth(int amount) {
	data.netWorth += amount;
}

//
void Player::setBankrupt() {
	data.bankrupt = true;
}

//
void Player::untrap() {
	data.turnsTrapped = 0;
	startTurn(); // start fresh
	updateObservers("You have been untrapped!");
}

//
void Player::trap(int turns) {
	data.turnsTrapped = turns;
	std::ostringstream ss{"You have been trapped in "};
	ss << data.position->getName() <<  " (for max. " << turns << " turns)!";
	updateObservers(ss.str());
}

//
void Player::decrementTurnsTrapped() {
	if (data.turnsTrapped <= 0) --(data.turnsTrapped);
}

// static methods:
int Player::getTotalTimsCups() { return totalTimsCups; }

//
void Player::incrementTimsCups() {
	if (totalTimsCups <= 0)
		throw GameException{"Tims cups at max. capacity."};
	++(data.timsCups);
	--totalTimsCups;
}

//
void Player::decrementTimsCups() {
	if (data.timsCups <= 0)
		throw GameException{"No Tims cups."};
	--(data.timsCups);
	++totalTimsCups;
}

//
void Player::incrementGymCount() { ++(data.gymCount); }

//
void Player::decrementGymCount() { --(data.gymCount); }

//
void Player::incrementResCount() { ++(data.resCount); }

//
void Player::decrementResCount() { --(data.resCount); }

//
void Player::incrementBlockCount(std::string name) {
	++(blockCount[name]);
}

//
void Player::decrementBlockCount(std::string name) {
	--(blockCount[name]);
}

