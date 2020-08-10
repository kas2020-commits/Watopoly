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
    Player* owner;
    bool morgaged;
  public:
    Property(std::string name, int purchaseCost);
    virtual void buy(Player* p) = 0;
    virtual void mortgage(Player* p) = 0;
    virtual void unmortgage(Player* p) = 0;
    Player* getOwner();
    bool isProperty() override; 
};

#endif
