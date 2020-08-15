#ifndef __COOP_FEE_H__
#define __COOP_FEE_H__
#include "Tile.h"
#include "Player.h"

//
class CoopFee: public Tile {
  public:
    CoopFee();
    void landEffect(Player* p) override;
};

#endif
