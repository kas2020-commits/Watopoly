#ifndef TILE_H
#define TILE_H
#include "Subject.h"

class Tile: public Subject{
    
    protected:
    std::string name;
    bool isProperty;
    
    public:
    Tile(std::string name);
    virtual void land(Player *) = 0;
    virtual void pass(Player *);
    virtual bool setIsProperty() = 0;
    std::string getName();
    

};

#endif
