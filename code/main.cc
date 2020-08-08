#include <sstream>
#include <stdexcept>
#include <string>
#include "Game.h"
#include "View.h"

//
int main() {
    //
    Game game{};
    View view{&game};

    // get number of players
    int numPlayers;
    view.update("Welcome to watopoly!");
    while (true) {
        view.update("Enter number of players (min: 2, max: 8):");
        try {
            numPlayers = std::stoi(view.getCommand());
            if (numPlayers < 2 || numPlayers > 8) throw std::invalid_argument("");
            break;
        }
        catch (const std::invalid_argument&) {
            view.update("Invalid number of players.");
        }
    }

    // add players to game
    for (int i = 0; i < numPlayers; i++) {
        while (true) {
            try {
                std::stringstream playerInfo{view.getCommand()};
                std::string name;
                char symbol;
                playerInfo >> name >> symbol;
                game.addPlayer(name, symbol);
                break;
            }
            catch (...) { // implement invalid player construction exception
                view.update("Invalid player details.");
            }
        }
    }

    // main game loop for game logic
    view.display();
    game.start();
    std::string action;
    while (true) {
        std::stringstream command{view.getCommand()};
        command >> action;

        // game logic
        if (action == "roll") {
            game.roll();
        }
        else if (action == "next") {
            view.display();
            game.next();
        }
        /*
        else if (action == "trade") {
            std::string name, giveItem, receiveItem;
            command >> name >> giveItem >> receiveItem;

            if (!game.isPlayer(name)) {
                view.update("Player: \"" + name + "\" does not exist.");
                continue;
            }

            if (!isProperty(give)) {

            }
            if (!isProperty(receive)) {

            }

            // get descision from other player
            bool accepted;
            while (true) {
                view.update("(accept/reject):");
                std::stringstream subCommand{view.getCommand()};
                std::string decision;
                subCommand >> decision;
                if (decision == "accept" || decision == "reject") {
                    accepted = (decision == "accept");
                    break;
                }
                else view.update("Not a valid response.");
            }
            if (!accepted) continue;

            // otherwise accepted, try to make sense of the trade
            try {
                int giveCash = std::stoi(giveItem);
                try {
                    int receiveCash = std::stoi(receiveItem);
                    view.update("Not a valid trade.");
                    continue;
                }
                catch (...) { game.trade(name, giveCash, receiveItem); }
            }
            catch (...) {
                try {
                    int receiveCash = std::stoi(receiveItem);
                    game.trade(name, giveItem, receiveCash);
                }
                catch (...) { game.trade(name, giveItem, receiveItem); }
            }
        }
        else if (action == "improve") {
            std::string ab, action;
            command >> ab >> action;
            if (!game.isAcademicBuilding(ab)) {
                view.update("Cannot improve: \"" + ab + "\"");
                continue;
            }
            if (action == "buy") game.buyImprovement();
            else if (action == "sell") game.sellImprovement();
            else
        }
        else if (action == "mortgage") {

        }
        else if (action == "unmortgage") {

        }
        else if (action == "bankrupt") {

        }
         else if (action == "assets") {
            game.assets();
        } else if (action == "all") {
            game.all();
        } else if (action == "save") {

        }
        else {
            view.update("Invalid command.");
        }*/
    }
}
