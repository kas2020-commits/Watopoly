#ifndef __GYM_H__
#define __GYM_H__
#include "Property.h"
#include "util.h"

class Gym: public Property{
    public:
    Gym(std::string name, int purchaseCost);
    void land(Player* p) override;
    void buy(Player* p) override;
    void mortgage(Player* p) override;
    void unmortgage(Player* p) override;
	bool isGym() override;

};

#endif
