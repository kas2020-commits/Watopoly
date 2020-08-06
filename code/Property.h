#ifndef PROPERTY_H
#define PROPERTY_H
#include "Tile.h"
#include "Player.h"

class Property:public Tile{

    protected:
    int purchaseCost;
    Player * owner;
    bool morgaged;

    public:
    Property(std::string name, int purchaseCost);
    virtual void buy(Player* p);
    virtual void mortgage(Player* p);
    virtual void unmortgage(Player* p);
    virtual bool setIsProperty() override;

};

#endif
