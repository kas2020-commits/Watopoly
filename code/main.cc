#include <sstream>
#include <stdexcept>
#include <string>
#include "Controller.h"
#include "Game.h"
#include "View.h"

//
int main(int argc, char* argv[]) {
    if (argc == 1) {
        Game game{};
        View view{&game};
        Controller controller{&game, &view};
        controller.run();
    }
    else if (argc == 2) {
		IO loader{};
		loader.load(argv[2]);
    }
	else {}
}
