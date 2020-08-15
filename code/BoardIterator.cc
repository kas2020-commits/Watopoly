#include "BoardIterator.h"

BoardIterator::BoardIterator(std::array<std::shared_ptr<Tile>, MAX_TILES> & vec,
		std::array<std::shared_ptr<Tile>, MAX_TILES>::iterator it, bool isCyclic)
	: isCyclic{isCyclic}, curTile{it}, tiles{vec}
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

Tile * BoardIterator::operator->()
{
	return curTile->get();
}

bool BoardIterator::operator==(const BoardIterator & other)
{
	return *curTile == *other.curTile;
}

bool BoardIterator::operator!=(const BoardIterator & other)
{
	return !(*this == other);
}

void BoardIterator::swap(BoardIterator & other)
{
	std::swap(isCyclic, other.isCyclic);
	std::swap(curTile, other.curTile);
	std::swap(tiles, other.tiles);
}

BoardIterator::BoardIterator(BoardIterator && other)
	: isCyclic{other.isCyclic}, curTile{other.curTile}, tiles{other.tiles}
{}

BoardIterator::BoardIterator(const BoardIterator & other)
	: isCyclic{other.isCyclic}, curTile{other.curTile}, tiles{other.tiles}
{}

BoardIterator & BoardIterator::operator=(const BoardIterator & other)
{
	BoardIterator tmp {other};
	swap (tmp);
	return *this;
}

BoardIterator & BoardIterator::operator=(BoardIterator && other)
{
	swap(other);
	return *this;
}

