#include "Board.h"

BoardIterator::BoardIterator(std::vector<std::shared_ptr<Tile>> & vec,
		std::vector<std::shared_ptr<Tile>>::iterator it, const bool isCyclic)
	: tiles{vec}, isCyclic{isCyclic}, curTile{it}
{}

BoardIterator &  BoardIterator::operator++()
{
	++curTile;
	if (curTile == tiles.end() && isCyclic) curTile = tiles.begin();
	return *this;
}

Tile & BoardIterator::operator*()
{
	return **curTile;
}

bool BoardIterator::operator==(const BoardIterator & other)
{
	return *curTile == *other.curTile;
}

bool BoardIterator::operator!=(const BoardIterator & other)
{
	return !(*this == other);
}

Board::Board()
	: tiles{std::vector<std::shared_ptr<Tile>>()}
{}

BoardIterator Board::begin()
{
	BoardIterator retval {tiles, tiles.begin()};
	return retval;
}

BoardIterator Board::end()
{
	BoardIterator retval {tiles, tiles.end()};
	return retval;
}

