#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__

#include "Tile.h"
#include "Trapped.h"
#include "util.h"

//
class DCTimsLineTrapped : public Trapped, public Subject {
  public:
    DCTimsLineTrapped(Player* p);
    void useTimsCup();
    void payCash();
    void roll();
};

//
class DCTimsLine : public Tile {
 public:
    DCTimsLine();
    virtual void throwTrapped() override;
}; 

#endif