#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
#include <cstdlib>
#include "Tile.h"
#include "util.h"
#include "Player.h"

class NeedlesHall:public Tile{
    public:
    NeedlesHall();
    void landEffect(Player* p) override;

};

#endif
