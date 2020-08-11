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
	// fields
	struct PlayerImpl;
	std::shared_ptr<PlayerImpl> data;
	std::map<std::string, int> blockCount;

	public:
	friend class IO;
	Player(const std::string name, const char symbol, BoardIterator);

	// moves the player either by a number of tiles or to a location.
	void move(const int);
	void move(const std::string, bool trap = false);

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
	int getNetWorth();
	int getCash();
	int getTurnsTrapped();

	// setters:
	// deposit and withdraw automatically change the player's net worth, so do
	// not change it twice!
	void deposit(const int);
	void withdraw(const int);
	void setBankrupt();
	void untrap();
	void trap();
	void setTimsCups(int);
	void setGymCount(int);
	void setResCount(int);
	void setTurnsTrapped(int);
	void changeNetWorth(int);

	void addTimsCup();
	void removeTimsCup();
};

#endif
