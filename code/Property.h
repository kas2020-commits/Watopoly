#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include "Tile.h"
#include "Player.h"

class PropertyException{};
class Player;

//
class Property : public Tile{
  protected:
	int purchaseCost;
	Player* owner;
	bool morgaged;
	virtual void landEffect(Player* p) override;
	virtual void applyFee(Player* p) = 0;
	virtual void gainPropEffect() = 0;
	virtual void losePropEffect() = 0;
	virtual void otherMortgageExcepts();
  public:
	friend class IO;
	Property(std::string name, int purchaseCost);
	void buy(Player* p);
	virtual void mortgage();
	virtual void unmortgage();
	bool isOwner(Player* p);
	bool hasOwner();
	virtual void setOwner(Player* p);
	bool isProperty() override;
};

#endif
