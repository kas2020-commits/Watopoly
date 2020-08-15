#include <sstream>
#include <stdexcept>
#include <string>
#include "Controller.h"
#include "Game.h"
#include "View.h"

//
int main(int argc, char* argv[]) {
	Game game{};
	View view{&game};
	Controller controller{&game, &view};
	if (argc == 2) {
		IO loader;
		loader.load(std::string {argv[1]}, &game, &view);
		controller.run(false);
	}
	else if (argc == 1) controller.run();
}

