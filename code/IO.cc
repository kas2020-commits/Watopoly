#include "IO.h"

struct IO::IOImpl {
	typedef const std::string head;
	head PLAYER { "PLAYER INFORMATION STARTS HERE" };
	head IMPROVEMENTS { "TILE IMPROVEMENT INFORMATION STARTS HERE" };
	head CURRENTPLAYER { "CURRENT PLAYER IS SAVED HERE" };
	head GAMEBOOLS { "GAME BOOLS ARE SAVED HERE" };
};

std::unique_ptr<Game> IO::load(const std::string filename)
{
	using namespace std;
	ifstream file {filename};
	istringstream iss;
	iss.exceptions(ios::failbit);
	file.exceptions(ios::failbit|ios::eofbit);

	unique_ptr<Game> game {};

	// temp fields
	string s;
	string tempName;
	char tempSymbol;
	int tempPosition;
	int tempCash;
	int tempTimsCups;
	int tempGymCount;
	int tempResCount;
	int tempTurnsTrapped;
	int tempTileIndex;
	int tempTileImprovements;
	vector<int> indexList;

	// permenant fields
	string currPlayerName;
	map<int, pair<string, int>> improvementList;
	map<string, shared_ptr<Player>> IOplayers;
	bool permStarted;
	bool permRolled;

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
				getline(file, tempName);

				// grab all fixed data fields
				getline(file, s);
				istringstream iss{s};
				iss >> tempSymbol >> tempPosition >> tempCash >> tempTimsCups >> tempGymCount >>
					tempResCount >> tempTurnsTrapped;

				// Dealing with tiles
				getline(file, s);
				istringstream indicies{s};
				while (true)
				{
					indicies >> tempTileIndex;
					if (indicies.fail()) break;
					indexList.push_back(tempTileIndex);
				}
				for (auto &i : indexList)
				{
					improvementList[i].first = tempName;
				}

				// Construct Player and push him into vector.
				BoardIterator tempIt { game->board->begin(true) };
				for (int i = 0; i < tempPosition; ++i) ++tempIt;
				shared_ptr<Player> tempPlayer = make_shared<Player>(tempName, tempSymbol, tempIt);
				tempPlayer->deposit(tempCash);
				tempPlayer->setTimsCups(tempTimsCups);
				tempPlayer->setResCount(tempResCount);
				tempPlayer->setGymCount(tempGymCount);
				tempPlayer->setTurnsTrapped(tempTurnsTrapped);
				IOplayers[tempName] = tempPlayer;
			}

			// Improvements are saved in the improvementList variable
			else if (s.compare(list->IMPROVEMENTS) == 0)
			{
				// grab list of indicies to tiles owned by player
				getline(file, s);
				istringstream indicies{s};
				while (true)
				{
					indicies >> tempTileIndex;
					if (indicies.fail()) break;
					auto tileCountFinder = improvementList.find(tempTileIndex);
					if (tileCountFinder == improvementList.end())
					{
						improvementList[tempTileIndex].second = 1;
					}
					else improvementList[tempTileIndex].second += 1;
				}
			}

			// grabs the current player's name
			else if (s.compare(list->CURRENTPLAYER) == 0)
			{
				getline(file, currPlayerName);
			}

			// stores the boolean values for game.
			else if (s.compare(list->GAMEBOOLS) == 0)
			{
				getline(file, s);
				istringstream bools{s};
				bools >> permStarted >> permRolled;
			}

		}
	}
	catch (ios::failure &) {}
	game->players = IOplayers;
	for (auto &i : improvementList)
	{
		tempTileIndex = i.first;
		tempName = i.second.first;
		tempTileImprovements = i.second.second;
		for (auto tempBoardIt = game->board->begin(); tempBoardIt != game->board->end(); ++tempBoardIt)
		{
			if (tempTileIndex == tempBoardIt->getIndex())
			{
				if (tempBoardIt->isAcademicBuilding())
				{
					auto tempAcademic = dynamic_cast<AcademicBuilding *>(&(*tempBoardIt));
					tempAcademic->owner = IOplayers.find(tempName)->second.get();
					tempAcademic->improvementLevel = tempTileImprovements;
				}
				else if (tempBoardIt->isProperty())
				{
					auto tempProperty = dynamic_cast<AcademicBuilding *>(&(*tempBoardIt));
					tempProperty->owner = IOplayers.find(tempName)->second.get();
				}
			}
		}
	}
	for (auto i = IOplayers.begin(); i != IOplayers.end(); ++i)
	{
		if (i->first.compare(currPlayerName) == 0)
		{
			game->curPlayer = i;
			break;
		}
	}
	game->started = permStarted;
	game->rolled = permRolled;
	file.close();
	return game;
}

void IO::save(const std::string filename, std::unique_ptr<Game> game)
{
	std::ofstream file {filename};
	// TODO: Create the template code for saving a game.
	file.close();
}
