#include "Property.h"

Property::Property(std::string name, int purchaseCost): purchaseCost{purchaseCost}, owner{nullptr}, morgaged{false}, Tile{name}{
}

bool Property::isProperty() { return true; }