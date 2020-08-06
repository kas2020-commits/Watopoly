#ifndef NEEDLESHALL_H
#define NEEDLESHALL_H
#include <cstdlib>
#include "NonProperty.h"


class NeedlesHall:public NonProperty{
    
    protected:
    
    public:
    NeedlesHall(std::string name);
    void land(Player* p) override;
    void applyEffect(Player* p) override;

};

#endif
