#ifndef GYM_H
#define GYM_H
#include "Property.h"
#include "util.h"

class Gym: public Property{
    
    protected:
    
    public:
    Gym(std::string name, int purchaseCost);
    
    void land(std::shared_ptr<Player> p) override;
    void buy(std::shared_ptr<Player> p) override;
    void mortgage(std::shared_ptr<Player> p) override;
    void unmortgage(std::shared_ptr<Player> p) override;

};

#endif
