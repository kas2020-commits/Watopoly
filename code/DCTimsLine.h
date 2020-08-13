#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__

#include "Tile.h"

//
class DCTimsLineTrap {
  private:
    Player* player;
  public:
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