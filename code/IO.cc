#include "IO.h"

struct IO::IOImpl {
	typedef const std::string head;
	head PLAYER { "PLAYER INFORMATION STARTS" };
	head IMPROVEMENTS { "TILE IMPROVEMENT INFORMATION" };
	head CURRENTPLAYER { "CURRENT PLAYER" };
	head GAMESTARTED { "DID THE GAME START?" };
	head ACADEEMIC { "ACADEEMIC BUILDING"};
	head PROPERTY { "GENERIC PROPERTY" };
};

struct AcademicInfo {
	std::string name;
	std::string blockName;
	int improvementLevel;
	AcademicInfo(std::string name, std::string blockName, int improvementLevel);
};

IO::IO()
	: list{ std::make_shared<IOImpl>() }
{}

AcademicInfo::AcademicInfo(std::string name, std::string blockName, int improvementLevel)
	: name{name}, blockName{blockName}, improvementLevel{improvementLevel}
{}

std::unique_ptr<Game> IO::load(const std::string filename)
{
	using namespace std;
	ifstream file {filename};
	istringstream iss;
	iss.exceptions(ios::failbit);
	file.exceptions(ios::failbit|ios::eofbit);

	unique_ptr<Game> game {};

	// useful constants
	const auto boardStart = game->board->begin();
	const auto boardEnd = game->board->end();

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
	string tempBlockName;

	// permenant fields
	string currPlayerName;
	map<int, string> propertyList;
	map<int, AcademicInfo> academicList;

	vector<shared_ptr<Player>> IOplayers;
	/* map<string, shared_ptr<Player>> IOplayers; */
	bool permStarted;

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

				// Construct Player and push him into vector.
				BoardIterator tempIt { game->board->begin(true) };
				for (int i = 0; i < tempPosition; ++i) ++tempIt;
				shared_ptr<Player> tempPlayer = make_shared<Player>(tempName, tempSymbol, tempIt);
				tempPlayer->deposit(tempCash);
				tempPlayer->timsCups = tempTimsCups;
				tempPlayer->resCount = tempResCount;
				tempPlayer->gymCount = tempGymCount;
				tempPlayer->turnsTrapped = tempTurnsTrapped;

				IOplayers.push_back(tempPlayer);
			}

			// handle an academic building
			else if (s.compare(list->ACADEEMIC) == 0)
			{
				getline(file, s);
				istringstream soop{s};
				soop >> tempTileIndex >> tempName >>  tempBlockName >> tempTileImprovements;
				academicList.insert( pair<int, AcademicInfo>(tempTileIndex,
							AcademicInfo(tempName, tempBlockName, tempTileImprovements)));
			}

			// handle a property
			else if (s.compare(list->PROPERTY) == 0)
			{
				getline(file, s);
				istringstream soop{s};
				soop >> tempTileIndex >> tempName;
				propertyList[tempTileIndex] = tempName;
			}

			// grabs the current player's name
			else if (s.compare(list->CURRENTPLAYER) == 0)
			{
				getline(file, currPlayerName);
			}

			// stores the boolean values for game.
			else if (s.compare(list->GAMESTARTED) == 0)
			{
				getline(file, s);
				istringstream bools{s};
				bools >> permStarted;
			}

			else break;
		} // while
	} // try
	catch (ios::failure &) {}

	// fix players' blockCount datafield
	for (auto &i : IOplayers)
	{
		string tempPlayerName = i->getName();
		for (auto &j : academicList)
		{
			if (j.second.name == tempPlayerName)
			{
				i->blockCount[j.second.blockName] += 1;
			}
		}
	}

	// fix the academic tiles
	for (auto &i : academicList)
	{
		tempTileIndex = i.first;
		tempName = i.second.name;
		tempTileImprovements = i.second.improvementLevel;
		for (auto tempBoardIt = boardStart; tempBoardIt != boardEnd; ++ tempBoardIt)
		{
			if (tempTileIndex == tempBoardIt->getIndex())
			{
				auto tempAcademic = dynamic_cast<AcademicBuilding *>(&(*tempBoardIt));
				for (auto &it : IOplayers)
				{
					if (it->getName().compare(tempName) == 0)
					{
						tempAcademic->owner = it.get();
						break;
					}
				}
				tempAcademic->improvementLevel = tempTileImprovements;
			}
		}
	}

	// fix the other property tiles
	for (auto &i : propertyList)
	{
		tempTileIndex = i.first;
		tempName = i.second;
		for (auto tempBoardIt = boardStart; tempBoardIt != boardEnd; ++ tempBoardIt)
		{
			auto tempProperty = dynamic_cast<AcademicBuilding *>(&(*tempBoardIt));
			for (auto &it : IOplayers)
			{
				if (it->getName().compare(tempName) == 0)
				{
					tempProperty->owner = it.get();
					break;
				}
			}
		}
	}

	// Update game fields.
	for (auto i = IOplayers.begin(); i != IOplayers.end(); ++i)
	{
		if ((*i)->getName().compare(currPlayerName) == 0)
		{
			game->curPlayer = i;
			break;
		}
	}
	game->started = permStarted;
	game->players = IOplayers;

	// fin
	file.close();
	return game;
}

///////////////////////////////////////////////////////////////////////////////

void IO::save(const std::string filename, Game * game)
{
	using namespace std;
	ofstream file {filename};

	// save the player's data fields in the order agreed on in the spec
	for (auto it = game->players.begin(); it != game->players.end(); ++it)
	{
		file << list->PLAYER << endl
			<< it->get()->name << endl
			<< it->get()->symbol << " "
			<< it->get()->position->getIndex() << " "
			<< it->get()->cash << " "
			<< it->get()->timsCups << " "
			<< it->get()->resCount << " "
			<< it->get()->resCount << " "
			<< it->get()->turnsTrapped << " "
			<< endl;
	}

	// go through all tiles in the board. If it is a property, list improvement
	// level as well as name;
	for (auto it = game->board->begin(); it != game->board->end(); ++it)
	{
		if (it->isAcademicBuilding())
		{
			auto tempAcademic = dynamic_cast<AcademicBuilding *>(&(*it));
			if (tempAcademic->owner != nullptr)
			{
				file<< list->ACADEEMIC << endl
					<< tempAcademic->getIndex() << " "
					<< tempAcademic->owner->getName() << " "
					<< tempAcademic->getImprovementLevel() << endl;
			}
		}
		else if (it->isProperty())
		{
			auto tempProperty = dynamic_cast<Property *>(&(*it));
			if (tempProperty->owner != nullptr)
			{
				file<< list->PROPERTY << endl
					<< tempProperty->getIndex() << " "
					<< tempProperty->owner->getName() << endl;
			}
		}
	}

	// save current player
	file << list->CURRENTPLAYER << endl << game->curPlayer->get()->getName() << endl;

	// save game bools
	file << list->GAMESTARTED << endl << game->started << endl;

	// fin
	file.close();
}

