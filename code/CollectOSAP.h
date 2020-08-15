#ifndef __OSAP_H__
#define __OSAP_H__
#include "Tile.h"
#include "Player.h"

class CollectOSAP: public Tile{
  public:
    CollectOSAP();
    virtual void landEffect(Player* p) override;
    virtual void pass(Player* p) override;
};

#endif

