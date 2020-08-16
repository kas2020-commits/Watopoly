#include <sstream>
#include <stdexcept>
#include <string>
#include "Controller.h"
#include "Game.h"
#include "View.h"
#include <iostream>

//
int main(int argc, char* argv[]) {
	Game game{};
	View view{&game};
	bool isTesting = false;
	bool fromSave = false;
	std::string file;
	IO loader;
	std::string optionOne, optionTwo;
	const std::string TESTING {"-testing"};

	if (argc > 1) optionOne = argv[1];
	if (argc > 2) optionTwo = argv[2];

	if (!isTesting && (optionOne.compare(TESTING) == 0 || optionTwo.compare(TESTING) == 0))
	{
		isTesting = true;
	}

	if (argc == 2 && optionOne.compare(TESTING) != 0) {
		file = optionOne;
		fromSave = true;
	}

	if (argc == 3 && optionOne.compare(TESTING) != 0) {
		file = optionOne;
		fromSave = true;
	}

	if (argc == 3 && optionTwo.compare(TESTING) != 0) {
		file = optionTwo;
		fromSave = true;
	}

	// construct the controller with the correct parameters
	Controller controller{&game, &view, isTesting};

	// if from a savefile, load it
	if (fromSave) {
		try {
		loader.load(file, &game, &view);
		} catch (IOException & fne) {
			std::cout << fne.getMessage() << std::endl;
			return 1;
		}
	}

	// start program
	controller.run(!fromSave);
}

