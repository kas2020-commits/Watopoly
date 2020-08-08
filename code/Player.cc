#include "Player.h"

// static member construction
int Player::totalTimsCups {0};
std::map<const char, bool> Player::symbolChart {
	{'G', false}, {'B', false}, {'D', false}, {'P', false}, {'S', false},
		{'$', false}, {'L', false}, {'T', false}
};

/* struct PlayerImpl { */
/* 	const std::string name; */
/* 	const char symbol; */
/* 	int cash; */
/* 	BoardIterator position; */
/* 	int timsCups; */
/* 	int gymCount; */
/* 	int resCount; */
/* 	std::map<std::string, int> blockCount; */
/* 	bool bankrupt; */
/* 	bool trapped; */
/* 	int turnsTrapped; */
/* 	PlayerImpl(const std::string name, const char symbol, BoardIterator it); */
/* }; */

/* PlayerImpl(const std::string name, const char symbol, BoardIterator it) */
/* 	: */
/* {} */

// constructor
Player::Player(const std::string name, const char symbol, BoardIterator it)
	:
		name{name}, symbol{symbol}, cash{500}, position{it},
		timsCups{0}, gymCount{0}, resCount{0}, trapped{false}, turnsTrapped{0}, // set counts to 0
		blockCount{std::map<std::string, int>
			{{ARTS1, 0}, {ARTS2, 0}, {ENG, 0}, {HEALTH, 0}, {ENV, 0}, {SCI1, 0},
				{SCI2, 0}, {MATH, 0}}}
{
	bool & isDup = symbolChart.find(symbol)->second;
	if (isDup) throw PlayerException();
	else isDup = false;
}

// move player:
void Player::move(int amount)
{
	for (int i = 0; i < amount; ++i) {
		++position;
		/* position->pass(static_cast<std::shared_ptr<Player>>(this)); */
		position->pass(this);
	}
	/* position->land(static_cast<std::shared_ptr<Player>>(this)); */
	position->land(this);
	updateObservers();
}

void Player::move(const std::string name, bool trap)
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
	position->land(static_cast<std::shared_ptr<Player>>(this));
	trap = trapped;
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
void Player::untrap() { trapped = false; }
void Player::trap() { trapped = true; }

// static methods:
int Player::getTotalTimsCups() { return totalTimsCups; }

