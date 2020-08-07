#ifndef __TILE_H__
#define __TILE_H__
#include "Subject.h"
#include <memory>
#include <string>

class Player; // forward declaration

//
class Tile: public Subject{
  protected:
    std::string name;
    int index;
    static int tileCount;
  public:
    Tile(std::string name);
    virtual void land(std::shared_ptr<Player>) = 0;
    virtual void pass(std::shared_ptr<Player>);
    std::string getName();
    int getIndex();
    bool operator==(Tile &);
    virtual bool isProperty();
    virtual bool isAcademicBuilding();
};

#endif
