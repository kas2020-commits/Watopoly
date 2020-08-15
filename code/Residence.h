#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__

#include "Property.h"
#include "GameException.h"
#include "Debt.h"

//
class Residence: public Property {
	void applyFee(Player* p) override;
	virtual void gainPropEffect() override;
	virtual void losePropEffect() override;

	public:
	Residence(std::string name, int purchaseCost);
	bool isRes() override;
};

#endif

