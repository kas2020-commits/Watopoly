#ifndef __BOARD_ITERATOR_H__
#define __BOARD_ITERATOR_H__
#include <string>
#include <memory>
#include <array>
#include "../logic/util.h"

class Board;
class Tile;

class BoardIterator {
	bool isCyclic;
	std::array<std::shared_ptr<Tile>, MAX_TILES>::iterator curTile;
	std::array<std::shared_ptr<Tile>, MAX_TILES> & tiles;
	void swap(BoardIterator &);
	public:

	// generic constructor
	BoardIterator(std::array<std::shared_ptr<Tile>, MAX_TILES> &,
			std::array<std::shared_ptr<Tile>, MAX_TILES>::iterator, bool isCyclic = false);

	// copy constructor
	BoardIterator(const BoardIterator &);

	// move constructor
	BoardIterator(BoardIterator &&);

	// Increments the itterator. Before incrementing however the method will
	// check if the cyclic varibale was chosen. If it was, then it will
	// move the itterator to the first item when called on an itterator
	// pointing the end.
	BoardIterator & operator++();
	BoardIterator & operator--();

	// derefernce the itterator to get the reference to the specific tile on
	// the board
	Tile & operator*();

	// derefernce the itterator and call a specfic method in Tile.
	Tile * operator->();

	// copy constructor implemented
	BoardIterator & operator=(const BoardIterator &);
	BoardIterator & operator=(BoardIterator &&);

	// Standard itterator behavior. No major changes have been made.
	bool operator==(const BoardIterator &);
	bool operator!=(const BoardIterator &);
};

#endif

