#include "Player.h"

int Player::totalTimsCups = 0;

Player::Player(const std::string name, const char symbol, BoardIterator it)
	: name{name}, symbol{symbol}, cash{500}, position{it},
	timsCups{0}, gymCount{0}, resCount{0}, // set counts to 0
	blockCount{std::map<std::string, int>()} // create blockCount map
{
	blockCount.emplace("Arts1", 0);
	blockCount.emplace("Arts2", 0);
	blockCount.emplace("Eng", 0);
	blockCount.emplace("Health", 0);
	blockCount.emplace("Env", 0);
	blockCount.emplace("Sci1", 0);
	blockCount.emplace("Sci2", 0);
	blockCount.emplace("Math", 0);
}

// move player:
void Player::move(int amount)
{
	for (int i = 0; i < amount; ++i) {
		++position;
		(*position).pass(this);
	}
	(*position).land(this);
	updateObservers();
}

void Player::move(const std::string name)
{
	const std::string oldLocation { (*position).getName() };
	while (true)
	{
		std::string newLocation = (*position).getName();
		if (newLocation == oldLocation) throw PlayerException();
		else if (newLocation == name) return;
		else ++position;
	}
	updateObservers();
}

// getters:
int Player::getResCount() { return resCount; }
int Player::getGymCount() { return gymCount; }
int Player::getTimsCups() { return timsCups; }
int Player::getBlockCount(const std::string block) { return blockCount.find(block)->second; }
bool Player::isBankrupt() { return bankrupt; }

// setters:
void Player::changeTimsCups(const int amount) { timsCups += amount; }
void Player::deposit(const int amount) { cash += amount; }
void Player::withdraw(const int amount) { cash -= amount; }
void Player::setBankrupt() { bankrupt = true; }

// static methods:
int Player::getTotalTimsCups() { return totalTimsCups; }

