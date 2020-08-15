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

	if ((optionOne.compare(TESTING) == 0 || optionTwo.compare(TESTING) == 0)
			&& !isTesting) {
		std::cout << "Aids" << std::endl;
		isTesting = true;
	}

	if (!fromSave && optionOne.compare(TESTING) == 0) {
		std::cout << "Cancer2" << std::endl;
		file = optionTwo;
		fromSave = true;
	}
	if (!fromSave && optionTwo.compare(TESTING) == 0) {
		std::cout << "Cancer1" << std::endl;
		file = optionOne;
		fromSave = true;
	}

	// construct the controller with the correct parameters
	Controller controller{&game, &view, isTesting};

	// if from a savefile, load it
	if (fromSave) loader.load(file, &game, &view);

	// start program
	controller.run(!fromSave);
}

