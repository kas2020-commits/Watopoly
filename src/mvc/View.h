#ifndef __VIEW_H__
#define __VIEW_H__

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Observer.h"
#include "../tiles/AcademicBuilding.h"
#include "../data/Player.h"
#include "../logic/Game.h"
#include "../logic/util.h"

class AcademicBuilding;
class Game;
class Player;

class View : public Observer {
  private:
    std::string view;
    std::vector<int> tileLoc;
    std::map<std::string, int> playerLoc;
    void updatePlayer(Player* p);
    void updateImprovements(AcademicBuilding* a);
  public:
    View(Game* g);
    virtual void update(Subject* whoUpdated) override;
    virtual void update(std::string message) override;
    void display();
    std::string getCommand();
};

#endif

