#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include "Game.h"
#include "View.h"
#include "IO.h"
#include "Debt.h"

//
class Controller {
  private:
	Game* game;
    View* view;
    IO io;
	int state;
	PurchaseOption po;
	Auction au;
	Debt db;
	TuitionPayment tp;
	DCTimsLineTrap dct;
	bool testing;
	void addPlayers();
	void handleTrade(std::string name,
	  std::string give, std::string receive);
  public:
	Controller(Game* game, View* view, bool testing = false);
	virtual ~Controller();
	void run();
};

#endif
