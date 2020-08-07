#ifndef __NON_PROPERTY_H__
#define __NON_PROPERTY_H__
#include "Tile.h"
#include "Player.h"

//
class NonProperty : public Tile{
  public:
    NonProperty(std::string name) : Tile{name} {};
    virtual void applyEffect(std::shared_ptr<Player> p) = 0;
    virtual void land(std::shared_ptr<Player> p) override { applyEffect(p); }
};

#endif
