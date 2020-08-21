#ifndef __GAME_H__
#define __GAME_H__

#include <memory>
#include <string>
#include "Auction.h"
#include "util.h"
#include "Roll.h"
#include "GameException.h"
#include "../mvc/Subject.h"
#include "../data/Player.h"
#include "../data/Board.h"
#include "../tiles/AcademicBuilding.h"
#include "../tiles/Gym.h"
#include "../tiles/Property.h"
#include "../tiles/Residence.h"

//
class GameOver : public GameException {
  public:
    GameOver(Player* p);
};

//
class Game : public Subject {
  friend class IO;

  private:
    std::unique_ptr<Board> board;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Player>>::iterator curPlayer;
    bool started;
    void assets(std::shared_ptr<Player>);
    std::shared_ptr<Player> getPlayer(std::string name);

  public:
    Game();
    virtual ~Game();
    virtual void attachMembers(Observer* ob) override;
    void addPlayer(std::string name, char symbol);
    void start(); // all players must be added before game started
    void roll();
    void roll(int die1, int die2);
    void next();
    void trade(std::string name, std::string giveProp, std::string receiveProp);
    void trade(std::string name, std::string giveProp, int receiveCash);
    void trade(std::string name, int giveCash, std::string receiveProp);
    void mortgage(std::string prop);
    void unmortgage(std::string prop);
    void buyImprovement(std::string ab);
    void sellImprovement(std::string ab);
    void assets();
    void all();
    void populateAuction(Auction& au);
	  void displaySymbols();
};

#endif

