#include "IO.h"

/* Here is the structure of a player's save:
 * PLAYER
 * name
 * symbol position cash timsCups resCount bankrupt position
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

struct IOImpl {
	typedef const std::string head;
	head PLAYER { "PLAYER INFORMATION STARTS HERE" };
	head IMPROVEMENTS { "TILE IMPROVEMENT INFORMATION STARTS HERE" };
	head CURRENTPLAYER { "CURRENT PLAYER IS SAVED HERE" };
};

IO::IO(Game * game)
	: list{std::make_unique<IOImpl>()}, game{game}
{}

void IO::load(const std::string filename)
{
	using namespace std;
	ifstream file {filename};
	istringstream iss;
	iss.exceptions(ios::failbit);
	file.exceptions(ios::failbit|ios::eofbit);

	// temp fields
	string s;
	string name;
	char symbol;
	int position;
	int cash;
	int timsCups;
	int gymCount;
	int resCount;
	bool bankrupt;
	int tileIndex;
	vector<int> indexList;

	// permenant fields
	vector<int> improvementList;
	string currPlayerName;

	try {
		while (1)
		{
			getline(file, s);

			/* This block will grab the information from the file and construct
			 * a Player with the correct state. The code at the end of the if
			 * statement is where the Player construction happens, and where the
			 * Player is given to the proper owner.
			 */
			if (s.compare(list->PLAYER) == 0)
			{
				// grab player name
				getline(file, name);

				// grab all static data fields
				getline(file, s);
				istringstream iss{s};
				iss >> symbol >> position >> cash >> timsCups >> gymCount >>
					resCount >> bankrupt;

				// grab list of indicies to tiles owned by player
				getline(file, s);
				istringstream indicies{s};
				while (true)
				{
					indicies >> tileIndex;
					if (indicies.fail()) break;
					indexList.push_back(tileIndex);
				}
				// TODO: ADD CODE TO CONSTRUCT PLAYER HERE
			}

			// Improvements are saved in the improvementList variable
			else if (s.compare(list->IMPROVEMENTS) == 0)
			{
				// grab list of indicies to tiles owned by player
				getline(file, s);
				istringstream indicies{s};
				while (true)
				{
					indicies >> tileIndex;
					if (indicies.fail()) break;
					improvementList.push_back(tileIndex);
				}
			}

			// grabs the current player's name
			else if (s.compare(list->CURRENTPLAYER) == 0)
			{
				getline(file, currPlayerName);
			}

		}
	}
	catch (ios::failure &) {}
	// TODO: CONSTRUCT THE GAME USING THE PERMENANT FIELDS HERE
	file.close();
}

void IO::save(const std::string filename)
{
	std::ofstream file {filename};
	// TODO: Create the template code for saving a game.
	file.close();
}
