#ifndef _VIEW_
#define _VIEW_

#include <map>
#include <string>
#include "Observer.h"

class AcadecmicBuidling;
class Game;
class Player;

class View : public Observer {
  private:
    std::string view;
    std::vector<int> tileLoc;
    std::map<std::string, int> playerLoc;
  public:
    View(Game* g);
    void updatePlayer(Player* p);
    void updateImprovements(AcademicBuilding* a);
    virtual void update(Subject* whoUpdated) override;
    virtual void update(std::string message) override;
    void display();
    std::string getCommand();
};

#endif