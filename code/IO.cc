#include "IO.h"

struct IO::IOImpl {
	std::string CURRENTPLAYER { "CURRENT PLAYER" };
};

IO::IO()
	: list{ std::make_shared<IOImpl>() }
{}

void IO::load(const std::string filename, Game * game, View * view)
{
	using namespace std;
	ifstream file {filename};
	istringstream iss;
	iss.exceptions(ios::failbit);
	file.exceptions(ios::failbit|ios::eofbit);

	// useful constants
	const auto boardStart = game->board->begin();
	const auto boardEnd = game->board->end();

	// temp fields
	string s;

	string tempName;
	char tempSymbol;
	int tempTimsCups;
	int tempCash;
	int tempPosition;
	int tempResCount;
	int tempGymCount;
	int tempTurnsTrapped;

	Player * tempPlayerPointer = nullptr;

	string tempPropertyName;
	string tempPropertyOwner;
	int tempPropertyImprovements;

	string tempBlockName;


	// permenant fields
	int playerCount;
	string currPlayerName;
	map<int, string> propertyList;

	vector<shared_ptr<Player>> IOplayers;

	getline(file, s);
	istringstream readCountPlayer{s};
	readCountPlayer >> playerCount;

	for (int i = 1; i < playerCount; ++i)
	{
		getline(file, s);
		istringstream readPlayer{s};

		readPlayer >> tempName >> tempSymbol >> tempTimsCups >> tempCash
			>> tempPosition >> tempResCount >> tempGymCount >> tempTurnsTrapped;
		BoardIterator tempIt { game->board->begin(true) };

		if (tempPosition == 30) throw IOException("Error: Player index was illegal\n");
		/* if (tempName.compare("BANK")) throw IOException("Error: Player name illegal\n"); */

		for (int j = 0; j < tempPosition; ++j) ++tempIt;

		shared_ptr<Player> tempPlayer = make_shared<Player>(tempName, tempSymbol, tempIt);
		tempPlayer->deposit(tempCash);
		tempPlayer->timsCups = tempTimsCups;
		tempPlayer->resCount = tempResCount;
		tempPlayer->gymCount = tempGymCount;
		tempPlayer->turnsTrapped = tempTurnsTrapped;

		IOplayers.push_back(tempPlayer);
	}

	for (int i = 0; i < PROPERTIES; ++i)
	{
		getline(file, s);
		istringstream readProperty{s};
		readProperty >> tempPropertyName >> tempPropertyOwner >> tempPropertyImprovements;
		for (auto tempBoardIt = boardStart; tempBoardIt != boardEnd; ++tempBoardIt)
		{
			if (tempBoardIt->getName().compare(tempPropertyName) == 0)
			{
				// find pointer to player
				for (auto & it : IOplayers)
				{
					if (it->getName().compare(tempName) == 0)
					{
						tempPlayerPointer = it.get();
						break;
					}
				}

				if (tempBoardIt->isAcademicBuilding())
				{
					auto tempAcademic = dynamic_cast<AcademicBuilding *>(&(*tempBoardIt));
					tempAcademic->owner = tempPlayerPointer;
					tempAcademic->improvementLevel = tempPropertyImprovements;
				}
				else
				{
					auto tempProperty = dynamic_cast<Property *>(&(*tempBoardIt));
					tempProperty->owner = tempPlayerPointer;
				}
			}
		}
	}

	// get current player
	getline(file, s);
	if (s.compare(list->CURRENTPLAYER) == 0)
	{
		getline(file, currPlayerName);
	}

	// fix players' blockCount datafield
	for (auto &i : IOplayers)
	{
		string tempPlayerName = i->getName();
		// iterate the board
		for (auto tempBoardIt = boardStart; tempBoardIt != boardEnd; ++tempBoardIt)
		{
			// check if AcademicBuilding
			if (tempBoardIt->isAcademicBuilding())
			{
				auto tempAcademic = dynamic_cast<AcademicBuilding *>(&(*tempBoardIt));
				if (tempAcademic->owner != nullptr &&
						tempAcademic->owner->name.compare(tempPlayerName) == 0)
				{
					i->blockCount[tempAcademic->block] += 1;
				}
			}
			else if (tempBoardIt->isProperty())
			{
				auto tempProperty = dynamic_cast<Property *>(&(*tempBoardIt));
				tempPropertyName = tempBoardIt->getName();
				if (tempProperty->hasOwner() &&
						(tempProperty->owner->name.compare(tempPlayerName) == 0)
						&& (tempPropertyName == PAC || tempPropertyName == CIF))
				{
					++i->gymCount;
				}
				else if (tempProperty->hasOwner() &&
						tempProperty->owner->name.compare(tempPlayerName) == 0
						&& (tempPropertyName == MKV || tempPropertyName == UWP ||
							tempPropertyName == REV || tempPropertyName == V1))
				{
					++i->resCount;
				}
			}
		}
	}

	// Update game's iterator of current players.
	for (auto i = IOplayers.begin(); i != IOplayers.end(); ++i)
	{
		if ((*i)->getName().compare(currPlayerName) == 0)
		{
			game->curPlayer = i;
			break;
		}
	}

	game->started = true;
	game->players = std::move(IOplayers);
	game->attach(view);

	// fin
	file.close();
}

///////////////////////////////////////////////////////////////////////////////

void IO::save(const std::string filename, Game * game)
{
	using namespace std;
	ofstream file {filename};

	file << game->players.size() << endl;

	// save the player's data fields in the order agreed on in the spec
	for (auto it = game->players.begin(); it != game->players.end(); ++it)
	{
		file << it->get()->name << " "
			<< it->get()->symbol << " "
			<< it->get()->timsCups << " "
			<< it->get()->cash << " "
			<< it->get()->position->getIndex() << " "

			<< it->get()->resCount << " "
			<< it->get()->gymCount << " "
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
			file << tempAcademic->name << " ";
			if (tempAcademic->owner != nullptr)
			{
				file << tempAcademic->owner->name << " ";
			}
			else {
				file << "BANK ";
			}
			file << tempAcademic->getImprovementLevel() << " ";
			file << tempAcademic->getIndex() << endl;
		}
		else if (it->isProperty())
		{
			auto tempProperty = dynamic_cast<Property *>(&(*it));
			file << tempProperty->name << " ";
			if (tempProperty->owner != nullptr)
			{
				file << tempProperty->owner->name << " ";
			}
			else {
				file << "BANK ";
			}
			file << tempProperty->getIndex() << endl;
		}
	}

	// save current player
	file << list->CURRENTPLAYER << endl << game->curPlayer->get()->getName() << endl;

	// fin
	file.close();
}

