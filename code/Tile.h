#ifndef __TILE_H__
#define __TILE_H__

#include <memory>
#include <string>
#include "Subject.h"
#include "util.h"

class Player; // forward declaration

//
class Tile: public Subject {
  protected:
    std::string name;
    int index;
    static int tileCount;
    virtual void landEffect(Player*);
  public:
    Tile(std::string name);
    void land(Player*);
    virtual void pass(Player*);
    virtual void leave(Player*);
    std::string getName();
    int getIndex();
    bool operator==(Tile &);
    virtual bool isProperty();
    virtual bool isAcademicBuilding();
    virtual bool isGym();
    virtual bool isRes();
    virtual void throwTrap(Player* p);
};

#endif

