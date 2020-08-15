#include "Auction.h"
#include "Debt.h"
#include "GameException.h"
#include "Property.h"

//
PurchaseOption::PurchaseOption(Property* pr, Player* p) : property{pr},
  player{p} {}

//
PurchaseOption::PurchaseOption() : property{nullptr}, player{nullptr} {}

//
void PurchaseOption::buy() { property->buy(player); }

//
void PurchaseOption::pass() { throw Auction{property}; }

//
Property::Property(std::string name, int purchaseCost) :
  Tile{name}, purchaseCost{purchaseCost}, owner{nullptr}, mortgaged{false} {}

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
	owner->deposit(purchaseCost / 2);
	mortgaged = true;
}

//
void Property::unmortgage() {
	if (mortgaged)
		throw GameException{"\"" + name + "\" is already unmortgaged."};
	owner->withdraw(6 * purchaseCost / 10); // may throw
	mortgaged = false;
}

//
void Property::otherMortgageExcepts() {}

//
void Property::landEffect(Player* p) {
	if (!hasOwner()) throw PurchaseOption(this, p);
	else if (mortgaged)
		updateObservers("Lucky you, \"" + name + "\" is mortgaged.");
	else applyFee(p);
}

//
bool Property::isOwner(Player* p) { return (p == owner); }

//
bool Property::hasOwner() { return owner != nullptr; }

//
void Property::setOwner(Player* p) {
	if (hasOwner()) {
		losePropEffect();
		owner->changeNetWorth(purchaseCost * -1);
	}
	owner = p;
	gainPropEffect();
	owner->changeNetWorth(purchaseCost);
	if (mortgaged) {
		try { owner->withdraw(0.1 * purchaseCost); }
		catch (GameException& e) { throw Debt{owner, purchaseCost / 10}; }
	}
}

//
bool Property::isProperty() { return true; }
