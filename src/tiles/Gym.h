#ifndef __GYM_H__
#define __GYM_H__
#include "Property.h"
#include "../logic/util.h"
#include "../logic/GameException.h"
#include "../logic/Debt.h"

class Gym: public Property{
  protected:
    virtual void applyFee(Player* p) override;
    virtual void gainPropEffect() override;
	  virtual void losePropEffect() override;
  public:
    Gym(std::string name, int purchaseCost);
	  bool isGym() override;
};

#endif

