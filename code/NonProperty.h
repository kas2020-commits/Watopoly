#ifndef NONPROPERTY_H
#define NONPROPERTY_H
#include "Tile.h"
#include "Player.h"
#include "util.h"


class NonProperty : public Tile{

    protected:

    public:
    NonProperty(std::string name);
    virtual void applyEffect(Player*);
    virtual bool setIsProperty() override;

};

#endif
