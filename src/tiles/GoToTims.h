#ifndef __GO_TO_TIMS_H__
#define __GO_TO_TIMS_H__
#include "Tile.h"
#include "../data/Player.h"

//
class GoToTims : public Tile {
  public:
    GoToTims();
    void landEffect(Player* p) override;
};

#endif

