#ifndef NEEDLESHALL_H
#define NEEDLESHALL_H
#include <cstdlib>
#include "NonProperty.h"
#include "util.h"

class NeedlesHall:public NonProperty{
    
    public:
    NeedlesHall();
    void land(Player* p) override;
    void applyEffect(Player* p) override;

};

#endif
