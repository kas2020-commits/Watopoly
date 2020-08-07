#ifndef __PLAYER_H_
#define __PLAYER_H_
#include <string>
#include <map>
#include "Subject.h"
#include "BoardIterator.h"
#include "Tile.h"
#include "util.h"

class Player;

class PlayerException {};

class Player : public Subject {
	// static fields
	static int totalTimsCups;

	// fields
	const std::string name;
	const char symbol;
	int cash;
	BoardIterator position;
	int timsCups;
	int gymCount;
	int resCount;
	std::map<std::string, int> blockCount;
	bool bankrupt;

	public:
	Player(const std::string name, const char symbol, BoardIterator);

	// moves the player either by a number of tiles or to a location.
	void move(const int);
	void move(const std::string);

	// getters:
	int getResCount();
	int getGymCount();
	int getTimsCups();
	int getBlockCount(const std::string);
	bool isBankrupt();
	char getSymbol();
	std::string getName();
	Tile & getPosition();

	// setters:
	void changeTimsCups(const int);
	void deposit(const int);
	void withdraw(const int);
	void setBankrupt();

	// static methods
	static int getTotalTimsCups();
};

#endif
