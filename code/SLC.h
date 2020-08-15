#ifndef __SLC_H__
#define __SLC_H__
#include "Tile.h"
#include "Player.h"

class SLC : public Tile {
  public:
    SLC();
    void landEffect(Player* p) override;
};

#endif

