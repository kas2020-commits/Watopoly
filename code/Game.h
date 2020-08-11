#ifndef __GAME_H__
#define __GAME_H__

#include <map>
#include <memory>
#include <string>
#include "Subject.h"
#include "Player.h"
#include "Board.h"

//
class GameException {
  private:
    std::string message;
  public:
    GameException(std::string message) : message{message} {}
    std::string getMessage() { return message; }
};

//
class Game : public Subject {
  friend class IO;
  private:
    std::unique_ptr<Board> board;
    std::map<std::string, std::shared_ptr<Player>> players;
    std::map<std::string, std::shared_ptr<Player>>::iterator curPlayer;
    bool started;
    bool rolled;
    void assets(std::string name);
  public:
    Game();
    virtual ~Game();
    virtual void attachMembers(Observer* ob) override;
    void addPlayer(std::string name, char symbol);
    void start(); // all players must be added before game started
    void roll();
    void next();
    void trade(std::string name, std::string giveProp, std::string receiveProp);
    void trade(std::string name, std::string giveProp, int receiveCash);
    void trade(std::string name, int giveCash, std::string receiveProp);
    void mortgage(std::string prop);
    void unmortgage(std::string prop);
    void buyImprovement(std::string ab);
    void sellImprovement(std::string ab);
    void bankrupt();
    void assets();
    void all();
};

#endif
