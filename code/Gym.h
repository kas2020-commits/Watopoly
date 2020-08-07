#ifndef GYM_H
#define GYM_H
#include "Property.h"
#include "util.h"

class Gym: public Property{
    
    protected:
    
    public:
    Gym(std::string name, int purchaseCost);
    
    void land(Player* p) override;
    void buy(Player* p) override;
    void mortgage(Player* p) override;
    void unmortgage(Player* p) override;

};

#endif
