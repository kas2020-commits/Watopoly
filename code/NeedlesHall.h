#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
#include <cstdlib>
#include "NonProperty.h"
#include "util.h"

class NeedlesHall:public NonProperty{
    public:
    NeedlesHall();
    void land(std::shared_ptr<Player> p) override;

};

#endif
