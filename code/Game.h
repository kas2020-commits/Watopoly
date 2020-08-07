#ifndef _GAME_
#define _GAME_

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
};

//
class Game : public Subject {
  private:
    std::unique_ptr<Board> board;
    std::map<std::string, std::shared_ptr<Player>> players;
    std::map<std::string, std::shared_ptr<Player>>::iterator curPlayer;
    bool started;
    bool rolled;
  public:
    Game();
    virtual ~Game();
    virtual void attachMembers(Observer* ob) override;
    bool isPlayer(std::string name);
    bool isProperty(std::string name);
    bool isAcademicBuilding();
    void addPlayer(std::string name, char symbol);
    void start(); // all players must be added before game started
    void roll();
    void next();
    void trade(std::string name, std::string giveProp, std::string receiveProp);
    void trade(std::string name, std::string giveProp, int receiveCash);
    void trade(std::string name, int giveCash, std::string receiveProp);
    void mortgage(std::string prop);
    void unmortgage(std::string prop);
    void buyImprovement(std::string prop);
    void sellImprovement(std::string prop);
    void bankrupt();
    void assets(std::string name);
    void all();
};

#endif