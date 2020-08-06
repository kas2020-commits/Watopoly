#ifndef PROPERTY_H
#define PROPERTY_H
#include tile.h
#include player.h


class Property:public tile{
    
    protected:
    int purchaseCost;
    Player * owner;
    bool morgaged;
    
    public:
    Property(std::string name, int purchaseCost);
    virtual void buy(Player* p);
    virtual void mortgage(Player* p);
    virtual void unmortgage(Player* p);
    bool isProperty() override;
    

};

#endif
