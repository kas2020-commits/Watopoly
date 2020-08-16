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
	std::string option;
	std::string value;
	const std::string TESTING {"-testing"};
	const std::string LOAD {"-load"};
	bool failed = false;

	if (argc == 1) {
		Controller controller{&game, &view, isTesting};
		controller.run();
	}
	else if (argc == 4) {
		option = argv[1];
		isTesting = true;
		fromSave = true;
		if (option.compare(TESTING) == 0) {
			file = argv[3];
		}
		else if (option.compare(LOAD) == 0) {
			file = argv[2];
		}
		else {
			failed = true;
		}
	}
	else if (argc == 2) {
		option = argv[1];
		if (option.compare(TESTING) == 0) isTesting = true;
		else {
			failed = true;
		}
	}
	else if (argc == 3) {
		option = argv[1];
		if (option.compare(LOAD) == 0) {
			file = argv[2];
			fromSave = true;
		}
		else {
			failed = true;
		}
	}
	else failed = true;

	if (failed) {
		std::cout << "Bad Arguments; Quiting..." << std::endl;
		return 1;
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

