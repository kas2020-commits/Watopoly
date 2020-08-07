#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include "Tile.h"
#include "Player.h"

class PropertyException{};
class Player;

//
class Property : public Tile{
  protected:
    int purchaseCost;
    std::shared_ptr<Player> owner;
    bool morgaged;
  public:
    Property(std::string name, int purchaseCost);
    virtual void buy(std::shared_ptr<Player> p) = 0;
    virtual void mortgage(std::shared_ptr<Player> p) = 0;
    virtual void unmortgage(std::shared_ptr<Player> p) = 0;
    bool isProperty() override; 
};

#endif
