#include <fstream>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "AcademicBuilding.h"

class View : public Observer {
  private:
    Game* game;
    std::string view;
    std::map<std::string, int> playerPositions;
    std::map<std::string, int> improvementPositions;
  public:

View::View(Game* game) : game{game}, view{""} {
    // read in view template
    std::ifstream viewTemplate{"test.txt"};
    std::string line;
    while (viewTemplate, line) view += line;
    game->attach(this);

    // set up building position map
    improvementPositions = std::map<std::string, int> {
        {AL, },
        {ML, },
        {ECH, },
        {PAS, }, 
        {HH, },
        {RCH, },
        {DWE, },
        {CPH, }, 
        {LHI, },
        {BMH, }, 
        {OPT, },
        {EV1, },
        {EV2, },
        {EV3, }, 
        {PHYS, },
        {B1, },
        {B2, },
        {EIT, }, 
        {ESC, }, 
        {C2, }, 
        {MC, }, 
        {DC, }
    }
}

void update(Subject* whoUpdated) {
    Player* p = std::dynamic_cast<Player*>(whoUpdated);
    if (p) {
        std::string name{p->getName()};
        if (!positions.count(name)) {
            // remove player old position
        }
        // add player new position
    }
    AcademicBuilding* a = std::dynamic_cast<AcademicBuilding*>(whoUpdated);
    if (a) {
        // building improvement logic
    }
}

virtual void update(std::string message) override;
void display();
std::string getCommand();