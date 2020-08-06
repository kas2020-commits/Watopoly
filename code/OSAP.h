#ifndef OSAP_H
#define OSAP_H
#include "NonProperty.h"

class OSAP: public NonProperty{
    
    protected:
    std::string name;
    
    public:
    OSAP(std::string name);
    void land(Player* p) override;
    void pass(Player* p);
    void applyEffect(Player* p) override;
};

#endif
