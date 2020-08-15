#include <fstream>
#include <iostream>
#include "AcademicBuilding.h"
#include "Game.h"
#include "Player.h"
#include "util.h"
#include "View.h"

// view class for user to interact with
View::View(Game* game) : view{VIEW_TEMPLATE} {
    // set exception type for input
    std::cin.exceptions(std::ios::failbit|std::ios::eofbit);

    // set up tile location vector
    //  note: tiles are indexed 0-39 going clockwise from Collect OSAP
    //  note: the following coords represent the location of the top left of each tile
    auto getLoc = [](int row, int col) { return 101 * row + col; };
    for (int i = 90; i >=  9; i -= 9) tileLoc.emplace_back(getLoc(50,  i));
    for (int i = 50; i >=  5; i -= 5) tileLoc.emplace_back(getLoc( i,  0));
    for (int i =  0; i <= 81; i += 9) tileLoc.emplace_back(getLoc( 0,  i));
    for (int i =  0; i <= 45; i += 5) tileLoc.emplace_back(getLoc( i, 90));

    // attach view to game
    game->attach(this);
}

// updates a given player's location on the view
void View::updatePlayer(Player* p) {
    // check bankruptcy !!!!!
    std::string name = p->getName();
    int tileIdx = p->getPosition().getIndex();
    if (playerLoc.count(name)) view[playerLoc[name]] = ' ';
    int playerZone = tileLoc[tileIdx] + 405;
    for (int i = playerZone; i < playerZone + 8; i++) {
        if (view[i] == ' ') {
            playerLoc[name] = i;
            view[i] = p->getSymbol();
            break;
        }
    }
}

// updates improvements for a given academic building on view
void View::updateImprovements(AcademicBuilding* a) {
    int tileIdx = a->getIndex();
    int impZone = tileLoc[tileIdx] + 102;
    int impLevel = a->getImprovementLevel();
    for (int i = impZone; i < impZone + impLevel; i++) view[i] = 'I';
    for (int i = impZone + impLevel; i < impZone + 5; i++) view[i] = ' ';
}

// notifies view that state of one of its subjects has changed
void View::update(Subject* whoUpdated) {
    Player* p = dynamic_cast<Player*>(whoUpdated);
    if (p) {
        updatePlayer(p);
        return;
    }
    AcademicBuilding* a = dynamic_cast<AcademicBuilding*>(whoUpdated);
    if (a) {
        updateImprovements(a);
        return;
    }
}

// prompts view to display a message from its subjects
void View::update(std::string message) {
    std::cout << message;
}

// display the game board
void View::display() { std::cout << view; }

// gets a command from the user
std::string View::getCommand() {
    std::string command;
    getline(std::cin, command);
    return command;
}
