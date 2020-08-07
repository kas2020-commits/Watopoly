#include "BoardIterator.h"

BoardIterator::BoardIterator(std::vector<std::shared_ptr<Tile>> & vec,
		std::vector<std::shared_ptr<Tile>>::iterator it, const bool isCyclic)
	: tiles{vec}, isCyclic{isCyclic}, curTile{it}
{
}

BoardIterator & BoardIterator::moveTo(const std::string s)
{
	for (auto i = tiles.begin(); i != tiles.end(); ++i)
	{
		if (i->get()->getName() == s)
		{
			curTile = i;
			return *this;
		}
	}
	return *this;
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
