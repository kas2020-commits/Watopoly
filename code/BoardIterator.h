#ifndef __BOARD_ITERATOR_H__
#define __BOARD_ITERATOR_H__
#include <string>
#include <memory>
#include <array>
#include "util.h"

class Board;
class Tile;

class BoardIterator {
	const bool isCyclic;
	std::array<std::shared_ptr<Tile>, MAX_TILES>::iterator curTile;
	std::array<std::shared_ptr<Tile>, MAX_TILES> & tiles;
	public:

	BoardIterator(std::array<std::shared_ptr<Tile>, MAX_TILES> &,
			std::array<std::shared_ptr<Tile>, MAX_TILES>::iterator, const bool isCyclic = false);

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

#endif
