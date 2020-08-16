#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__

#include "LogicException.h"
#include "Tile.h"
#include "Player.h"
#include "GameException.h"

//
class DCTimsLineTrap : public LogicException {
  private:
    Player* player;
  public:
    DCTimsLineTrap();
    DCTimsLineTrap(Player* p);
    void useTimsCup();
    void pay();
    void roll();
    void roll(int die1, int die2); // for testing
    virtual std::string getMessage() override;
};

//
class DCTimsLine : public Tile {
  public:
    DCTimsLine();
    virtual void throwTrap(Player* p) override;
};

#endif

