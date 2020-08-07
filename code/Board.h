#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include <memory>
#include <string>

#include "AcademicBuilding.h"
#include "Tutition.h"
#include "SLC.h"
#include "NeedlesHall.h"
#include "DCTimsLine.h"
#include "Gym.h"
#include "Res.h"
#include "GooseNesting.h"
#include "GoToTims.h"
#include "CoopFee.h"

/* #include "util.h" */

class Board;
class SLC;

class BoardIterator {
	const bool isCyclic;
	std::vector<std::shared_ptr<Tile>>::iterator curTile;
	std::vector<std::shared_ptr<Tile>> & tiles;
	public:

	BoardIterator(std::vector<std::shared_ptr<Tile>> &,
			std::vector<std::shared_ptr<Tile>>::iterator, const bool isCyclic = false);

	BoardIterator & moveTo(const std::string);

	// Increments the itterator. Before incrementing however the method will
	// check if the cyclic varibale was chosen. If it was, then it will
	// move the itterator to the first item when called on an itterator
	// pointing the end.
	BoardIterator & operator++();

	// derefernce the itterator to get the reference to the specific tile on
	// the board
	Tile & operator*();

	// Standard itterator behavior. No major changes have been made.
	bool operator==(const BoardIterator &);
	bool operator!=(const BoardIterator &);
};

class Board {
	std::vector<std::shared_ptr<Tile>> tiles;
	public:
	Board();
	~Board();

	// Standard behavior. begin and end construct and return an itterator which
	// starts at either the first or last
	BoardIterator begin(const bool isCyclic = false);
	BoardIterator end();
};

#endif
