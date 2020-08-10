#include "Player.h"

// static member construction
int Player::totalTimsCups {0};
std::map<const char, bool> Player::symbolChart {
	{'G', false}, {'B', false}, {'D', false}, {'P', false}, {'S', false},
		{'$', false}, {'L', false}, {'T', false}
};

struct Player::PlayerImpl {
	const std::string name;
	const char symbol;
	BoardIterator position;
	int cash;
	int timsCups;
	int gymCount;
	int resCount;
	bool bankrupt;
	bool trapped;
	int turnsTrapped;
	PlayerImpl(const std::string name, const char symbol, BoardIterator it);
	~PlayerImpl();
};

Player::PlayerImpl::~PlayerImpl() {}

Player::PlayerImpl::PlayerImpl(const std::string name, const char symbol, BoardIterator it)
	: name{name}, symbol{symbol}, position{it}, cash{1500},
	timsCups{0}, gymCount{0}, resCount{0}, bankrupt{false}, trapped{false}, turnsTrapped{0}
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
void Player::move(int amount)
{
	for (int i = 0; i < amount; ++i) {
		++data->position;
		data->position->pass(this);
	}
	data->position->land(this);
	updateObservers();
}

void Player::move(const std::string name, bool trap)
{
	const std::string oldLocation { data->position->getName() };
	std::string midval;
	while (true)
	{
		data->position->getName();
		if (midval.compare(name) == 0) break;
		else if (midval.compare(oldLocation) == 0) throw PlayerException();
		else ++data->position;
	}
	data->position->land(this);
	trap = data->trapped;
	updateObservers();
}

// getters:
int Player::getResCount() { return data->resCount; }
int Player::getGymCount() { return data->gymCount; }
int Player::getTimsCups() { return data->timsCups; }
int Player::getBlockCount(const std::string block) { return blockCount.find(block)->second; }
bool Player::isBankrupt() { return data->bankrupt; }
char Player::getSymbol() { return data->symbol; }
std::string Player::getName() { return data->name; }
Tile & Player::getPosition() { return *data->position; }

// setters:
void Player::setTimsCups(int amount) { data->timsCups = amount; }
void Player::setGymCount(int amount) { data->gymCount = amount; }
void Player::setResCount(int amount) { data->resCount = amount; }
void Player::setTurnsTrapped(int amount) { data->turnsTrapped = amount; }

void Player::deposit(const int amount) { data->cash += amount; }
void Player::withdraw(const int amount) { data->cash -= amount; }
void Player::setBankrupt() { data->bankrupt = true; }
void Player::untrap() { data->trapped = false; }
void Player::trap() { data->trapped = true; }

// static methods:
int Player::getTotalTimsCups() { return totalTimsCups; }

