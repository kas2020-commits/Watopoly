#ifndef SLC_H
#define SLC_H
#include <cstdlib>
#include "NonProperty.h"

class SLC:public NonProperty{
    
    protected:
    
    public:
    SLC(std::string name);
    void land(Player* p) override;
    void applyEffect(Player* p) override;

};

#endif
