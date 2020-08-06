#ifndef SLC_H
#define SLC_H
#include <cstdlib>
#include "NonProperty.h"
#include "util.h"

class SLC:public NonProperty{
    
    public:
    SLC();
    void land(Player* p) override;
    void applyEffect(Player* p) override;

};

#endif
