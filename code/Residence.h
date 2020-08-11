#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__

#include "Property.h"
#include <string>

//
class Residence: public Property {
  public:
    Residence(std::string name, int purchaseCost);
    void landEffect(Player* p) override;
    void buy(Player* p) override;
    void mortgage(Player* p) override;
    void unmortgage(Player* p) override;
	bool isRes() override;
};

#endif