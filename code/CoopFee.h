#ifndef COOPFEE_H
#define COOPFEE_H
#include "NonProperty.h"
#include "util.h"

class CoopFee: public NonProperty{
    
    
    public:
    CoopFee();
    void land(Player* p) override;
    void applyEffect(Player* p) override;
};

#endif
