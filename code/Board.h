#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include <memory>
#include <string>
#include <map>
#include "BoardIterator.h"

#include "AcademicBuilding.h"
#include "Tutition.h"
#include "NeedlesHall.h"
#include "SLC.h"
#include "DCTimsLine.h"
#include "Gym.h"
#include "Res.h"
#include "GooseNesting.h"
#include "GoToTims.h"
#include "CoopFee.h"

/* #include "util.h" */

class Board {
	std::vector<std::shared_ptr<Tile>> tiles;
	public:
	Board();

	// Standard behavior. begin and end construct and return an itterator which
	// starts at either the first or last
	BoardIterator begin(const bool isCyclic = false);
	BoardIterator end();
};

#endif
