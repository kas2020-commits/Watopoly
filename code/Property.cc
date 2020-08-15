#include "GameException.h"
#include "Property.h"

//
Property::Property(std::string name, int purchaseCost)
	:Tile{name}, purchaseCost{purchaseCost}, owner{nullptr}, morgaged{false} {}

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
	if (mortgaged) 
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
