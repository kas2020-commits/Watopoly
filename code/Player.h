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

class PlayerException {};

class Player : public Subject {
	// static fields
	static int totalTimsCups;
	static std::map<const char, bool> symbolChart;

	struct PlayerImpl;

	// fields
	std::shared_ptr<PlayerImpl> data;
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
	void deposit(const int);
	void withdraw(const int);
	void setBankrupt();
	void untrap();
	void trap();

	void setTimsCups(int);
	void setGymCount(int);
	void setResCount(int);
	void setTurnsTrapped(int);

	// static methods
	static int getTotalTimsCups();
};

#endif
