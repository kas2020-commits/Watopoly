#ifndef __IO_H__
#define __IO_H__
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <map>
#include "Game.h"
#include "View.h"

/* Here is the structure of a player's save:
 * PLAYER
 * name
 * symbol position cash timsCups resCount turnsTrapped
 * index1 index2 index3 ... indexn // where each value is the index of the tile
 */

/* Tile improvements are saved by using the index of the tile representing 1
 * improvement. Thus if tile with index 20 has 4 improvements then in the list
 * we will see the number 20 appear 4 times.
 *
 * Example:
 * IMPROVEMENTS
 * 12 22 20 20 20 20 9 3 9 32
 */

/* The current player information is saved by recording the name of the
 * player. Here is an example as reference. Suppose player named Alex is current
 * player:
 *
 * CURRENTPLAYER
 * Alex
 */

/* Academic tiles owned by a player are stored in the following way:
 *
 * Example:
 * ACADEEMIC
 * TileIndex Name BlockName TileImprovements
 */

/* gneric properties that are something other than academic tiles are stored
 * similarly to academic tiles:
 *
 * Example:
 * PROPERTY
 * TileIndex Name
 */

/* Game booleans are stored simply in bit representation, where a 0 is false and
 * a 1 is true. Order is started and then rolled.
 *
 * Example:
 * GAMEBOOLS
 * 1 1
 */

class IO {
	struct IOImpl;
	std::shared_ptr<IOImpl> list;
	public:
	IO();
	void save(const std::string, Game *);
	void load(const std::string, Game *, View *);
};

#endif
