#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include "Game.h"
#include "View.h"
#include "IO.h"

//
class Controller {
  private:
	Game* game;
    View* view;
    IO io;
	void addPlayers();
	void handleTrade(std::string name, std::string give, std::string receive);
  public:
	Controller(Game* game, View* view);
	virtual ~Controller();
	void run();
};

#endif
