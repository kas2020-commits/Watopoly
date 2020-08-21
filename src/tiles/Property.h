#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include "Tile.h"
#include "../data/Player.h"
#include "../logic/LogicException.h"
#include "../logic/Debt.h"
#include "../logic/GameException.h"

// forward declaration
class Player;
class Property;

//
class PurchaseOption : public LogicException {
  private:
	Property* property;
	Player* player;
  public:
    PurchaseOption();
    PurchaseOption(Property* pr, Player* p);
	void buy();
	void pass();
	virtual std::string getMessage() override;
};

//
class Property : public Tile {
  protected:
	int purchaseCost;
	Player* owner;
	bool mortgaged;
	virtual void landEffect(Player* p) override;
	virtual void applyFee(Player* p) = 0;
	virtual void gainPropEffect() = 0;
	virtual void losePropEffect() = 0;
	virtual void otherMortgageExcepts();
	virtual void newOwnerExcepts();
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

