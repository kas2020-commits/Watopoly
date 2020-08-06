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
<<<<<<< HEAD
    virtual bool setIsProperty() override;
=======
    bool setIsProperty() override;
    
>>>>>>> f1838a8af29f331755e1a5a56655a910b0a63c30

};

#endif
