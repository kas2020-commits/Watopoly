#include <sstream>
#include <stdexcept>
#include "Controller.h"

#include <iostream> // for debugging

//
Controller::Controller(Game* game, View* view, bool testing) : game{game}, view{view},
	state{0}, testing{testing}
{}

//
Controller::~Controller() {}

// adds desired amount of players to game
void Controller::addPlayers() {
	// gets the number of players from view
	std::istringstream command{};
	int numPlayers;
	while (true) {
		view->update("Enter number of players (min: 2, max: 8):\n");
		command = std::istringstream{view->getCommand()};
		try {
			command >> numPlayers;
			if (numPlayers < 2 || numPlayers > 8) throw std::invalid_argument("");
			break;
		}
		catch (std::invalid_argument&) {
			view->update("Invalid number of players.\n");
		}
	}

	// add players to game
	for (int i = 0; i < numPlayers; ++i) {
		std::string name;
		while (true) {
			view->update("Insert player name.\n");
			command = std::istringstream{view->getCommand()};
			try {
				command >> name;
				if (name == "BANK") throw GameException{""};
				break;
			}
			catch (GameException &) {
				view->update("Invalid name.\n");
			}
		}
		char symbol;
		while (true) {
			view->update("Insert symbol name. ");
			game->displaySymbols();
			command = std::istringstream{view->getCommand()};
			try {
				command >> symbol;
				game->addPlayer(name, symbol);
				break;
			}
			catch (GameException & e) {
				view->update(e.getMessage());
			}
		}
	}
}

// handles the different types of trades
void Controller::handleTrade(std::string name, std::string give, std::string receive) {
	//
	bool cashForProp{false};
	bool propForCash{false};
	bool propForProp{false};
	int giveCash;
	int receiveCash;

	try {
		giveCash = std::stoi(give);
		try {
			receiveCash = std::stoi(receive);
			view->update("Not a valid trade.\n");
			return;
		}
		catch (std::invalid_argument&) { game->trade(name, giveCash, receive); }
	}
	catch (std::invalid_argument&) {
		try {
			receiveCash = std::stoi(receive);
			game->trade(name, give, receiveCash);
		}
		catch (std::invalid_argument&) { game->trade(name, give, receive); }
	}

	// get descision from other player
	while (true) {
		view->update(name + "'s descision (accept/reject):\n");
		std::stringstream command{view->getCommand()};
		std::string decision;
		command >> decision;
		if (decision == "accept") {
			// message view->update("");
			return;
		}
		else if (decision == "reject") {
			if (cashForProp) game->trade(name, receive, giveCash);
			else if (propForCash) game->trade(name, receiveCash, give);
			else if (propForProp) game->trade(name, receive, give);
			return;
		}
		else view->update("Not a valid response.");
	}
}

//
void Controller::help() {
	std::string h {
		"Here is a list of all the commands you can use:\n"
		"\troll: rolls dice and moves player\n"
		"\tnext: end your turn\n"
		"\ttrade <name> <give> <receive>: offers a trade to name with the current player\n"
		"\timprove <property> buy/sell: Attempts to buy or sell an improvement for property\n"
		"\timprove <property> buy/sell: Attempts to buy or sell an improvement for property\n"
		"\tmortgage <Property>: Attempts to mortgage property\n"
	};
	view->update(h);
}

void Controller::displayBoard() {
	view->display();
	view->update("For a list of all the commands you can use, type \"help\".\n");
}

//
void Controller::run(bool init) {
	//
	if (init) { // init new game ???
		view->update("Welcome to watopoly!\n");
		addPlayers();
		game->start();
	}
	displayBoard(); // initial board display

	/* CONTROLLER STATES
	 * state 0: regular turn, player has access to all basic commands
	 * state 1: student must pay tuition, has access to trade and bankrupt
	 * state 2: student trapped
	 * state 3: student must decide where or not to buy a property
	 * state 4: auction
	 * state 5: student in debt
	 */

	// main game loop for game logic
	std::istringstream command;
	std::string action;
	while (true) {
		//
		command = std::istringstream{view->getCommand()};
		command >> action;

		// game logic
		try {
			if (action == "help") help();
			else if (action == "roll") {
				if (state == 0) {
					if (!testing) game->roll();
					else {
						int die1, die2;
						try { command >> die1 >> die2; }
						catch (...) {
							game->roll();
							continue;
						}
						game->roll(die1, die2);
					}
				}
				else if (state == 2) {
					if (!testing) game->roll();
					else {
						int die1, die2;
						try { command >> die1 >> die2; }
						catch (...) {
							dct.roll();
							state = 0;
							continue;
						}
						dct.roll(die1, die2);
						state = 0;
					}
				}
				else {
					view->update("Cannot roll right now.\n");
					continue;
				}
			}
			else if (action == "next") {
				if (state == 0) game->next();
				else {
					view->update("Cannot end turn right now.\n");
					continue;
				}
			}
			else if (action == "trade") {
				std::string name, give, receive;
				command >> name >> give >> receive;
				handleTrade(name, give, receive);
			}
			else if (action == "improve") {
				if (state == 0) {
					std::string ab, action;
					command >> ab >> action;
					if (action == "buy") game->buyImprovement(ab);
					else if (action == "sell") game->sellImprovement(ab);
					else {
						view->update("Invalid command.\n");
						continue;
					}
				}
				else {
					view->update("Cannot improve right now.\n");
					continue;
				}
			}
			else if (action == "mortgage") {
				if (state == 0) {
					std::string prop;
					command >> prop;
					game->mortgage(prop); // will throw if any issues
				}
				else {
					view->update("Cannot mortgage right now.\n");
					continue;
				}
			}
			else if (action == "unmortgage") {
				if (state == 0) {
					std::string prop;
					command >> prop;
					game->unmortgage(prop); // will throw if any issues
				}
				else {
					view->update("Cannot unmortgage right now.\n");
					continue;
				}
			}
			else if (action == "bankrupt") {
				if (state == 1) {
					tp.bankrupt();
					game->next();
				}
				else if (state == 5) {
					db.bankrupt();
					game->next();
				}
			}
			else if (action == "assets") {
				if (state != 1) game->assets();
				else view->update("Cannot display assets right now.\n");
				continue;
			}
			else if (action == "all") {
				if (state != 1) game->all();
				else view->update("Cannot display all assets right now.\n");
				continue;
			}
			else if (action == "save") {
				std::string fileName;
				command >> fileName;
				io.save(fileName, game);
				view->update(std::string {"Game has been saved to file: \"" + fileName + "\"\n"});
			}
			else if (action == "pay") {
				if (state == 1) {
					std::string method;
					command >> method;
					if (method == "$300") {
						tp.payCash();
						view->update(tp.getMessage());
						state = 0;
					}
					else if (method == "10%") {
						tp.payPercent();
						view->update(tp.getMessage());
						state = 0;
					}
					else view->update("Not a valid tuition payment method.\n");
				}
				else if (state == 2) {
					dct.pay();
				}
				else if (state == 5) { // pay debt
					db.pay(); // will throw if lack of funds
					state = 0;
				}
				else {
					view->update("Nothing to pay.\n");
					continue;
				}
			}
			else if (action == "buy") {
				if (state == 3) {
					po.buy(); // may throw if lack of funds
					state = 0;
				}
				else view->update("Nothing to buy.\n");
				continue;
			}
			else if (action == "pass") {
				if (state == 3) po.pass(); // will throw auction
				else {
					view->update("Nothing to pass.\n");
					continue;
				}
			}
			else if (action == "bid") {
				if (state == 4) {
					std::string name;
					command >> name;
					int bid;
					try { command >> bid; }
					catch (...) { view->update("Not a valid bid.\n"); }
					au.bid(name, bid);
					view->update(au.getMessage());
					continue;
				}
				else view->update("No auction currently going on.\n");
				continue;
			}
			else if (action == "end") {
				if (state == 4) {
					au.end();
					view->update(au.getMessage());
					state = 0;
				}
				else {
					view->update("No auction to end.\n");
					continue;
				}
			}
			else if (action == "use") {
				std::string tims, cup;
				command >> tims >> cup;
				if (tims == "Tims" && cup == "cup") {
					if (state == 2) {
						dct.useTimsCup();
						view->update(dct.getMessage());
					}
					else view->update("Cannot use Tims cup now.\n");
				}
				else view->update("Invalid command.\n");
				continue;
			}
			else {
				view->update("Invalid command.\n");
				continue;
			}
			displayBoard();
		}
		catch (GameException& e) {
			view->update(e.getMessage());
		}
		catch (TuitionPayment& e) {
			tp = e;
			view->update(tp.getMessage());
			view->update("Type \"pay $300\", or \"pay 10%\". respectively.\n");
			state = 1;
		}
		catch (DCTimsLineTrap& e) {
			dct = e;
			view->update(dct.getMessage());
			view->update("Type \"pay\", \"use Tims cup\", or \"roll\" respectively.\n");
			state = 2;
		}
		catch (PurchaseOption& e) {
			po = e;
			view->update(po.getMessage());
			view->update("Type \"buy\", or \"pass\" respectively.\n");
			state = 3;
		}
		catch (Auction& e) {
			au = e;
			game->populateAuction(au);
			view->update(au.getMessage());
			view->update("To bid, type \"bid <name> <amount>\". Type \"end\" to end the bidding.\n");
			state = 4;
		}
		catch (Debt& e) {
			db = e;
			view->update(db.getMessage());
			view->update("Type \"pay\", or \"bankrupt\". respectively.\n");
			state = 5;
		}
	}
}

