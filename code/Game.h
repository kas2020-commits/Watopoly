#ifndef _GAME_
#define _GAME_

#include <map>
#include <memory>
#include <string>
#include "Subject.h"
#include "Player.h"
#include "Board.h"

class Game : public Subject {
  private:
    std::shared_ptr<Board> board;
    std::map<std::string, std::shared_ptr<Player>> players;
    std::map<std::string, std::shared_ptr<Player>>::iterator curPlayer;
    bool started;
  public:
    Game();
    virtual ~Game();
    virtual void attachToMembers(Observer* ob) override;
    void addPlayer();
    void bankruptPlayer();
    std::shared_ptr<Player> start(); // all players must be added before game started
    std::shared_ptr<Player> nextTurn();
};

#endif