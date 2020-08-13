#include <sstream>
#include <stdexcept>
#include "Controller.h"

#include <iostream> // for debugging

//
Controller::Controller(Game* game, View* view) : game{game}, view{view}, io{IO{}} {}

//
Controller::~Controller() {}

// adds desired amount of players to game
void Controller::addPlayers() {
	// gets the number of players from view
	int numPlayers;
	while (true) {
		view->update("Enter number of players (min: 2, max: 8):\n");
		try {
			numPlayers = std::stoi(view->getCommand());
			if (numPlayers < 2 || numPlayers > 8) throw std::invalid_argument("");
			break;
		}
		catch (std::invalid_argument&) {
			view->update("Invalid number of players.\n");
		}
	}

	// add players to game
	for (int i = 0; i < numPlayers; ++i) {
		while (true) {
			view->update("Type the name of the player followed by the symbol you would like\n");
			try {
				std::stringstream playerInfo{view->getCommand()};
				std::string name;
				char symbol;
				playerInfo >> name >> symbol;
				game->addPlayer(name, symbol);
				break;
			}
			catch (PlayerException &) { // implement invalid player construction exception
				view->update("Invalid player details.\n");
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
		if (decision == "accept") return;
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
void Controller::run() {
	//
	view->update("Welcome to watopoly!\n");
	addPlayers();

	// main game loop setup
	view->display();
    game->start();
    int state = 0;
    /* state 0: regular turn, player has access to all basic commands
     * state 1: student must pay tuition, has access to trade and bankrupt
     * state 2: student trapped
     *
     *
     */
    std::stringstream command;
    std::string action;
    TuitionPayment tuition;
	DCTimsLineTrap dcTrap;

    // main game loop for game logic
	while (true) {
		//
		command = std::stringstream{view->getCommand()};
		command >> action;

		// game logic
		try {
			if (action == "roll") {
                if (state != 0) {
                    view->update("Cannot roll right now.\n");
                    continue;
                }
                game->roll();
			}
			else if (action == "next") {
                if (state != 0) {
                    view->update("Cannot end turn right now.\n");
                    continue;
                }
                view->display();
				game->next();
			}
			else if (action == "trade") {
				std::string name, give, receive;
				command >> name >> give >> receive;
				handleTrade(name, give, receive);
			}
			else if (action == "improve") {
                if (state != 0) {
                    view->update("Cannot improve right now.\n");
                    continue;
                }
                std::string ab, action;
				command >> ab >> action;
				if (action == "buy") game->buyImprovement(ab);
				else if (action == "sell") game->sellImprovement(ab);
				else view->update("Invalid command.\n");
			}
			else if (action == "mortgage") {
                if (state != 0) {
                    view->update("Cannot mortgage right now.\n");
                    continue;
                }
                std::string prop;
				command >> prop;
				game->mortgage(prop);
			}
			else if (action == "unmortgage") {
                if (state != 0) {
                    view->update("Cannot unmortgage right now.\n");
                    continue;
                }
                std::string prop;
				command >> prop;
				game->unmortgage(prop);
			}
			else if (action == "bankrupt") {
				game->bankrupt();
			}
			else if (action == "assets") {
                if (state != 0) {
                    view->update("Cannot display assets right now.\n");
                    continue;
                }
                game->assets();
			}
			else if (action == "all") {
                if (state != 0) {
                    view->update("Cannot display all assets right now.\n");
                    continue;
                }
                game->all();
			}
			else if (action == "save") {
                std::string fileName;
                command >> fileName;
                io.save(fileName, game);
                view->update(std::string {
						"Game has been saved to file: " + fileName + "\n"});
            }
            else if (action == "pay") {
                if (state != 1) {
                    view->update("Nothing to pay.\n");
                    continue;
                }
                std::string method;
                command >> method;
                if (method == "$300") {
                    tuition.payCash();
                    state = 0;
                }
                else if (method == "10%") {
                    tuition.payPercent();
                    state = 0;
                }
                else view->update("Not a valid tuition payment method.\n");
            }
			else if () {

			}
			else {
				view->update("Invalid command.\n");
			}
		}
		catch (GameException& e) {
			view->update(e.getMessage());
		}
		catch (TuitionPayment& tp) {
            tuition = tp;
            state = 1;
		}
		catch (DCTimsLineTrap& dct) {
			dcTrap = dct;
			state = 2;
		}
	}
}
