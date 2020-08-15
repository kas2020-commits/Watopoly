#ifndef __BOARD_H__
#define __BOARD_H__
#include <memory>
#include <string>
#include <map>
#include <array>
#include "BoardIterator.h"
#include "util.h"

#include "AcademicBuilding.h"
#include "Tuition.h"
#include "NeedlesHall.h"
#include "SLC.h"
#include "DCTimsLine.h"
#include "Gym.h"
#include "Residence.h"
#include "GooseNesting.h"
#include "GoToTims.h"
#include "CoopFee.h"
#include "CollectOSAP.h"

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

