#ifndef GOTOTIMS_H
#define GOTOTIMS_H
#include "NonProperty.h"

class GoToTims: public NonProperty{
    
    protected:
    std::string name;
    
    public:
    GoToTims(std::string name);
    void land(Player* p) override;
    void applyEffect(Player* p) override;
};

#endif
