#ifndef TILE_H
#define TILE_H
#include "Subject.h"
#include <string>

class Player;

class Tile: public Subject{

    protected:
    std::string name;
    int index;
    static int tileCount;
    public:
    Tile(std::string name);
    virtual void land(Player *) = 0;
    virtual void pass(Player *);
    std::string getName();
    int getIndex();
    bool operator==(Tile &);
    virtual bool isProperty() = 0;

};

#endif
