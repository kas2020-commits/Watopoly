#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__

#include "LogicException.h"
#include "Tile.h"

//
class DCTimsLineTrap : public LogicException {
  private:
    Player* player;
  public:
    DCTimsLineTrap();
    DCTimsLineTrap(Player* p);
    void useTimsCup();
    void payCash();
    void roll();
};

//
class DCTimsLine : public Tile {
  public:
    DCTimsLine();
    virtual void throwTrap(Player* p) override;
};

#endif