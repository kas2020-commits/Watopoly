#include "BoardIterator.h"

BoardIterator::BoardIterator(std::array<std::shared_ptr<Tile>, MAX_TILES> & vec,
		std::array<std::shared_ptr<Tile>, MAX_TILES>::iterator it, const bool isCyclic)
	: tiles{vec}, isCyclic{isCyclic}, curTile{it}
{
}

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
