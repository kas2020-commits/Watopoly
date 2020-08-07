#ifndef NONPROPERTY_H
#define NONPROPERTY_H
#include "Tile.h"
#include "Player.h"


class NonProperty : public Tile{

    protected:

    public:
    NonProperty(std::string name);
    virtual void applyEffect(Player*);
    bool isProperty() override; 
};

#endif
