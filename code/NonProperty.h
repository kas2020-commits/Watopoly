#ifndef NONPROPERTY_H
#define NONPROPERTY_H
#include tile.h
#include player.h


class NonProperty:public tile{
    
    protected:
    
    public:
    Property(std::string name, int purchaseCost);
    virtual void applyEffect(Player*);
    bool setIsProperty() override;
    

};

#endif
