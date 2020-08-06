#include "Board.h"
#include "AcademicBuilding.h"

BoardIterator::BoardIterator(std::vector<std::shared_ptr<Tile>> & vec,
		std::vector<std::shared_ptr<Tile>>::iterator it, const bool isCyclic)
	: tiles{vec}, isCyclic{isCyclic}, curTile{it}
{
	tiles.push_back(std::make_shared<AcademicBuilding>("AL", "Arts1", 40, 50, 2, 10, 30, 90, 160, 250));
	tiles.push_back(std::make_shared<AcademicBuilding>("ML", "Arts1", 60, 50, 4, 20, 60, 180, 320, 450));
	tiles.push_back(std::make_shared<AcademicBuilding>("ECH", "Arts2", 100, 50, 6, 30, 90, 270, 400, 550));
	tiles.push_back(std::make_shared<AcademicBuilding>("PAS", "Arts2", 100, 50, 6, 30, 90, 270, 400, 550));
	tiles.push_back(std::make_shared<AcademicBuilding>("HH", "Arts2", 120, 50, 8, 40, 100, 300, 450, 600));
	tiles.push_back(std::make_shared<AcademicBuilding>("RCH", "Eng", 140, 100, 10, 50, 150, 450, 625, 750));
	tiles.push_back(std::make_shared<AcademicBuilding>("DWE", "Eng", 140, 100, 10, 50, 150, 450, 625, 750));
	tiles.push_back(std::make_shared<AcademicBuilding>("CPH", "Eng", 160, 100, 12, 60, 180, 500, 700, 900));
	tiles.push_back(std::make_shared<AcademicBuilding>("LHI", "Health", 180, 100, 14, 70, 200, 550, 750, 950));
	tiles.push_back(std::make_shared<AcademicBuilding>("BMH", "Health", 180, 100, 14, 70, 200, 550, 750, 950));
	tiles.push_back(std::make_shared<AcademicBuilding>("OPT", "Health", 200, 100, 16, 80, 220, 600, 800, 1000));
	tiles.push_back(std::make_shared<AcademicBuilding>("EV1", "Env", 220, 150, 18, 90, 250, 700, 875, 1050));
	tiles.push_back(std::make_shared<AcademicBuilding>("EV2", "Env", 220, 150, 18, 90, 250, 700, 875, 1050));
	tiles.push_back(std::make_shared<AcademicBuilding>("EV3", "Env", 240, 150, 20, 100, 300, 750, 925, 1100));
	tiles.push_back(std::make_shared<AcademicBuilding>("PHYS", "Sci1", 260, 150, 22, 110, 330, 800, 975, 1150));
	tiles.push_back(std::make_shared<AcademicBuilding>("B1", "Sci1", 260, 150, 22, 110, 330, 800, 975, 1150));
	tiles.push_back(std::make_shared<AcademicBuilding>("B2", "Sci1", 280, 150, 24, 120, 360, 850, 1025, 1200));
	tiles.push_back(std::make_shared<AcademicBuilding>("EIT", "Sci2", 300, 200, 26, 130, 390, 900, 1100, 1275));
	tiles.push_back(std::make_shared<AcademicBuilding>("ESC", "Sci2", 300, 200, 26, 130, 390, 900, 1100, 1275));
	tiles.push_back(std::make_shared<AcademicBuilding>("C2", "Sci2", 320, 200, 28, 150, 450, 1000, 1200, 1400));
	tiles.push_back(std::make_shared<AcademicBuilding>("MC", "Math", 350, 200, 35, 175, 500, 1100, 1300, 1500));
	tiles.push_back(std::make_shared<AcademicBuilding>("DC", "Math", 400, 200, 50, 200, 600, 1400, 1700, 2000));
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

