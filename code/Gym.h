#ifndef __GYM_H__
#define __YM_H__
#include "Property.h"
#include "util.h"

class Gym: public Property{
    public:
    Gym(std::string name, int purchaseCost);
    void land(std::shared_ptr<Player> p) override;
    void buy(std::shared_ptr<Player> p) override;
    void mortgage(std::shared_ptr<Player> p) override;
    void unmortgage(std::shared_ptr<Player> p) override;

};

#endif
