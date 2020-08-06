#ifndef _VIEW_
#define _VIEW_

#include <map>
#include <string>
#include "Game.h"
#include "Observer.h"

class View : public Observer {
  private:
    int pp;
    Game* game;
    std::string view;
    map<>
  public:
    View(Game* game);
    virtual void update(Subject* whoNotified) override;
    virtual void update(std::string message) override;
    void display();
    std::string getCommand();
};

#endif