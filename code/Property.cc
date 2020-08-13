#include "Property.h"

//
Property::Property(std::string name, int purchaseCost)
	:Tile{name}, purchaseCost{purchaseCost}, owner{nullptr}, morgaged{false} {}

//
bool isOwner(Player* p) { return (p == owner); }

//
bool Property::hasOwner() { return (owner == nullptr); }

//
bool Property::setOwner(Player* p) { owner = p; }

//
bool Property::isProperty() { return true; }
