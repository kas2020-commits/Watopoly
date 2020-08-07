#ifndef NEEDLESHALL_H
#define NEEDLESHALL_H
#include <cstdlib>
#include "NonProperty.h"
#include "util.h"

class NeedlesHall:public NonProperty{
    
    public:
    NeedlesHall();
    void land(std::shared_ptr<Player> p) override;

};

#endif
