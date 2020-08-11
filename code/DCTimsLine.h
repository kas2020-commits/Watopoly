#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__

#include "Tile.h"
#include "util.h"

//
class DCTimsLine : public Tile {
 public:
    DCTimsLine();
    void landEffect(Player* p) override;
}; 

#endif