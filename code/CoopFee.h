#ifndef COOPFEE_H
#define COOPFEE_H
#include "NonProperty.h"

class CoopFee: public NonProperty{
    
    protected:
    std::string name;
    
    public:
    CoopFee(std::string name);
    void land(Player* p) override;
    void applyEffect(Player* p) override;
};

#endif
