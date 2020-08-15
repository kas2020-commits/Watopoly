#include "Auction.h"
#include "GameException.h"
#include "Property.h"

//
PurchaseOption::PurchaseOption(Property* pr, Player* p) : property{pr},
  player{p} {}

//
PurchaseOption::PurchaseOption() : property{nullptr}, player{nullptr} {}

//
void PurchaseOption::buy() { property->buy(Player); }

//
void PurchaseOption::pass() { throw Auction{property}; }

//
Property::Property(std::string name, int purchaseCost) :
  Tile{name}, purchaseCost{purchaseCost}, owner{nullptr}, morgaged{false} {}

//
void Property::buy(Player* p) {
	p->withdraw(purchaseCost);
	setOwner(p);
	updateObservers("Bought \"" + name + "\"!\n");
}

//
void Property::mortgage() {
	if (!mortgaged)
		throw GameException{"\"" + name + "\" is already mortgaged."};
	otherMortgageExcepts();
	owner->deposit(0.5 * purchaseCost);
	mortgaged = true;
}

//
void Property::unmortgage() {
	if (mortgaged)
		throw GameException{"\"" + name + "\" is already unmortgaged."};
	owner->withdraw(0.6 * purchaseCost); // may throw
	mortgaged = false;
}

//
bool Property::otherMortgageExcepts() {}

//
void Property::landEffect(Player* p) {
	if (!isOwned()) throw PurchaseOption(this, p);
	else if (mortgaged) 
		updateObservers("Lucky you, \"" + name + "\" is mortgaged.");
	else applyFee(p);
}

//
bool Property::isOwner(Player* p) { return (p == owner); }

//
bool Property::hasOwner() { return (owner == nullptr); }

//
bool Property::setOwner(Player* p) {
	if (hasOwner() && !owner->isBankrupt()) {
		losePropEffect();
		owner->changeNetWorth(purchaseCost);
	}
	owner = p;
	gainPropEffect();
	owner->changeNetWorth(purchaseCost);
}

//
bool Property::isProperty() { return true; }