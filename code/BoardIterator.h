#ifndef __BOARD_ITERATOR_H__
#define __BOARD_ITERATOR_H__
#include <vector>
#include <string>
#include <memory>

class Board;
class Tile;

class BoardIterator {
	const bool isCyclic;
	std::vector<std::shared_ptr<Tile>>::iterator curTile;
	std::vector<std::shared_ptr<Tile>> & tiles;
	public:

	BoardIterator(std::vector<std::shared_ptr<Tile>> &,
			std::vector<std::shared_ptr<Tile>>::iterator, const bool isCyclic = false);

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
