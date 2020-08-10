#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <map>
#include <stdexcept>
#include "Subject.h"
#include "BoardIterator.h"
#include "Tile.h"
#include "util.h"

class PlayerException {};

class Player : public Subject {
	// static fields
	static int totalTimsCups;
	static std::map<const char, bool> symbolChart;

	// data structure used for player. Mainly just for organization purposes.
	struct Data {
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
			Data(const std::string name, const char symbol, BoardIterator it);
	};

	// fields
	Data data;
	std::map<std::string, int> blockCount;

	public:
	Player(const std::string name, const char symbol, BoardIterator);

	// moves the player either by a number of tiles or to a location.
	void move(const int);
	void move(const std::string, bool trap = false);

	// getters:
	int getResCount();
	int getGymCount();
	int getTimsCups();
	int getBlockCount(const std::string);
	bool isBankrupt();
	char getSymbol();
	std::string getName();
	Tile & getPosition();
	bool isTrapped();

	// setters:
	void changeTimsCups(const int);
	void deposit(const int);
	void withdraw(const int);
	void setBankrupt();
	void untrap();
	void trap();

	// static methods
	static int getTotalTimsCups();
};

#endif
