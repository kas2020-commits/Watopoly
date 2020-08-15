#include <sstream>
#include <stdexcept>
#include <string>
#include "Controller.h"
#include "Game.h"
#include "View.h"

//
int main(int argc, char* argv[]) {
	Game game{};
	if (argc == 2) {
		IO loader;
		loader.load(std::string {argv[1]}, &game);
	}
	View view{&game};
	Controller controller{&game, &view};
	controller.run();
}
