#include "Player.h"

int Player::totalTimsCups = 0;

Player::Player(const std::string name, const char symbol, BoardIterator it)
	:
		name{name}, symbol{symbol}, cash{500}, position{it},
		timsCups{0}, gymCount{0}, resCount{0}, // set counts to 0
		blockCount{std::map<std::string, int>()} // create blockCount map
{
	blockCount.emplace(ARTS1, 0);
	blockCount.emplace(ARTS2, 0);
	blockCount.emplace(ENG, 0);
	blockCount.emplace(HEALTH, 0);
	blockCount.emplace(ENV, 0);
	blockCount.emplace(SCI1, 0);
	blockCount.emplace(SCI2, 0);
	blockCount.emplace(MATH, 0);
}

// move player:
void Player::move(int amount)
{
	for (int i = 0; i < amount; ++i) {
		++position;
		position->pass(this);
	}
	position->land(this);
	updateObservers();
}

void Player::move(const std::string name)
{
	const std::string oldLocation { position->getName() };
	std::string midval;
	while (true)
	{
		position->getName();
		if (midval.compare(name) == 0) break;
		else if (midval.compare(oldLocation) == 0) throw PlayerException();
		else ++position;
	}
	position->land(this);
	updateObservers();
}

// getters:
int Player::getResCount() { return resCount; }
int Player::getGymCount() { return gymCount; }
int Player::getTimsCups() { return timsCups; }
int Player::getBlockCount(const std::string block) { return blockCount.find(block)->second; }
bool Player::isBankrupt() { return bankrupt; }
char Player::getSymbol() { return symbol; }
std::string Player::getName() { return name; }
Tile & Player::getPosition() { return *position; }

// setters:
void Player::changeTimsCups(const int amount) { timsCups += amount; }
void Player::deposit(const int amount) { cash += amount; }
void Player::withdraw(const int amount) { cash -= amount; }
void Player::setBankrupt() { bankrupt = true; }

// static methods:
int Player::getTotalTimsCups() { return totalTimsCups; }

