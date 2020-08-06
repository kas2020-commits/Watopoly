#ifndef _VIEW_
#define _VIEW_

#include <map>
#include <string>
#include "Game.h"
#include "Observer.h"

class View : public Observer {
  private:
    Game* game;
    std::string view;
    std::map<std::string, int> positions;
  public:
    View(Game* game);
    virtual void update(Subject* whoUpdated) override;
    virtual void update(std::string message) override;
    void display();
    std::string getCommand();
};

#endif