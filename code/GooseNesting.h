#ifndef __GOOSE_NESTING_H__
#define __GOOSE_NESTING_H__

#include "Tile.h"

//
class GooseNesting : public Tile {
  public:
    GooseNesting();
    void landEffect(Player* p) override;
};

#endif
