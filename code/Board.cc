#include "Board.h"

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

Board::Board()
	: tiles{std::vector<std::shared_ptr<Tile>> {
		std::make_shared<AcademicBuilding>(AL,		ARTS1,	40 , 50 , 2 , 10 , 30 , 90  , 160 , 250 ),
			std::make_shared<SLC>(),
			std::make_shared<AcademicBuilding>(ML,		ARTS1,	60 , 50 , 4 , 20 , 60 , 180 , 320 , 450 ),
			std::make_shared<Tuition>(),
			std::make_shared<SLC>(),
			std::make_shared<AcademicBuilding>(ECH,		ARTS2,	100, 50 , 6 , 30 , 90 , 270 , 400 , 550 ),
			std::make_shared<NeedlesHall>(),
			std::make_shared<AcademicBuilding>(PAS,		ARTS2,	100, 50 , 6 , 30 , 90 , 270 , 400 , 550 ),
			std::make_shared<AcademicBuilding>(HH, 		ARTS2,	120, 50 , 8 , 40 , 100, 300 , 450 , 600 ),
			std::make_shared<DCTimsLine>(),
			std::make_shared<AcademicBuilding>(RCH,		ENG,	140, 100, 10, 50 , 150, 450 , 625 , 750 ),
			std::make_shared<Gym>(PAC),
			std::make_shared<AcademicBuilding>(DWE,		ENG,	140, 100, 10, 50 , 150, 450 , 625 , 750 ),
			std::make_shared<AcademicBuilding>(CPH,		ENG,	160, 100, 12, 60 , 180, 500 , 700 , 900 ),
			std::make_shared<Res>(UWP),
			std::make_shared<AcademicBuilding>(LHI,		HEALTH,	180, 100, 14, 70 , 200, 550 , 750 , 950 ),
			std::make_shared<SLC>(),
			std::make_shared<AcademicBuilding>(BMH,		HEALTH,	180, 100, 14, 70 , 200, 550 , 750 , 950 ),
			std::make_shared<AcademicBuilding>(OPT,		HEALTH,	200, 100, 16, 80 , 220, 600 , 800 , 1000),
			std::make_shared<GooseNesting>(),
			std::make_shared<AcademicBuilding>(EV1,		ENV,	220, 150, 18, 90 , 250, 700 , 875 , 1050),
			std::make_shared<NeedlesHall>(),
			std::make_shared<AcademicBuilding>(EV2,		ENV,	220, 150, 18, 90 , 250, 700 , 875 , 1050),
			std::make_shared<AcademicBuilding>(EV3,		ENV,	240, 150, 20, 100, 300, 750 , 925 , 1100),
			std::make_shared<Res>(V1),
			std::make_shared<AcademicBuilding>(PHYS,	SCI1,	260, 150, 22, 110, 330, 800 , 975 , 1150),
			std::make_shared<AcademicBuilding>(B1,		SCI1,	260, 150, 22, 110, 330, 800 , 975 , 1150),
			std::make_shared<Gym>(PAC),
			std::make_shared<AcademicBuilding>(B2,		SCI1,	280, 150, 24, 120, 360, 850 , 1025, 1200),
			std::make_shared<GoToTims>(),
			std::make_shared<AcademicBuilding>(EIT,		SCI2,	300, 200, 26, 130, 390, 900 , 1100, 1275),
			std::make_shared<AcademicBuilding>(ESC,		SCI2,	300, 200, 26, 130, 390, 900 , 1100, 1275),
			std::make_shared<SLC>(),
			std::make_shared<AcademicBuilding>(C2,		SCI2,	320, 200, 28, 150, 450, 1000, 1200, 1400),
			std::make_shared<Res>(REV),
			std::make_shared<NeedlesHall>(),
			std::make_shared<AcademicBuilding>(MC,		MATH,	350, 200, 35, 175, 500, 1100, 1300, 1500),
			std::make_shared<CoopFee>(),
			std::make_shared<AcademicBuilding>(DC,		MATH,	400, 200, 50, 200, 600, 1400, 1700, 2000)
	}}
{}

Board::~Board() {}

BoardIterator Board::begin(const bool isCyclic)
{
	BoardIterator retval {tiles, tiles.begin(), isCyclic};
	return retval;
}

BoardIterator Board::end()
{
	BoardIterator retval {tiles, tiles.end()};
	return retval;
}

