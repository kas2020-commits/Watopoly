#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <map>
#include <stdexcept>
#include <memory>
#include "Subject.h"
#include "BoardIterator.h"
#include "Tile.h"
#include "util.h"
#include "Roll.h"

//
class Player : public Subject {
	// static fields
	static int totalTimsCups;
	static std::map<const char, bool> symbolChart;

	// fields

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

	std::map<std::string, int> blockCount;

	public:
	friend class IO;
	Player(const std::string name, const char symbol, BoardIterator);

	// moves the player either by a number of tiles or to a location.
	Roll roll(bool moreInfo = false);
	void move(int);
	void move(const std::string);
	void rollAndMove();
	void startTurn();

	// getters:
	static int getTotalTimsCups();
	int getResCount();
	int getGymCount();
	int getTimsCups();
	int getBlockCount(const std::string);
	bool isBankrupt();
	char getSymbol();
	std::string getName();
	Tile & getPosition();
	bool isTrapped();
	int getTurnsTrapped();
	int getNetWorth();
	int getCash();
	bool hasRolled();

	// setters:
	// deposit and withdraw automatically change the player's net worth, so do
	// not change it twice!
	void deposit(const int);
	void withdraw(const int);
	void setBankrupt();
	void untrap();
	void trap(int);
	void setTimsCups(int);
	void setGymCount(int);
	void setResCount(int);
	void changeNetWorth(int);

	// incrementers / decrementers
	void incrementTimsCups();
	void decrementTimsCups();
	void incrementGymCount();
	void decrementGymCount();
	void incrementResCount();
	void decrementResCount();
	void incrementBlockCount(std::string name);
	void decrementBlockCount(std::string name);
	void decrementTurnsTrapped();
};

#endif
