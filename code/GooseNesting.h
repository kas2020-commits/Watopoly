#ifndef GOOSENESTING_H
#define GOOSENESTING_H
#include "NonProperty.h"

class GooseNesting: public NonProperty{
    
    protected:
    std::string name;
    
    public:
    GooseNesting(std::string name);
    void land(Player* p) override;
    void applyEffect(Player* p) override;
};

#endif
