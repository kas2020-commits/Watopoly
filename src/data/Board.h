#ifndef __BOARD_H__
#define __BOARD_H__
#include <memory>
#include <string>
#include <map>
#include <array>
#include "BoardIterator.h"
#include "../logic/util.h"

#include "../tiles/AcademicBuilding.h"
#include "../tiles/Tuition.h"
#include "../tiles/NeedlesHall.h"
#include "../tiles/SLC.h"
#include "../tiles/DCTimsLine.h"
#include "../tiles/Gym.h"
#include "../tiles/Residence.h"
#include "../tiles/GooseNesting.h"
#include "../tiles/GoToTims.h"
#include "../tiles/CoopFee.h"
#include "../tiles/CollectOSAP.h"

class BoardException {};

class Board {
	std::array<std::shared_ptr<Tile>, MAX_TILES> tiles;
	public:
	Board();

	// Standard behavior. begin and end construct and return an itterator which
	// starts at either the first or last
	BoardIterator begin(const bool isCyclic = false);
	BoardIterator end();

	// returns the tile with the same unique name given in argument. If
	// non-unique string is given i.e. NeedlesHall or SLC, a BoardException is
	// thrown.
	Tile & at(const std::string);
};

#endif

