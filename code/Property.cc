#include "Property.h"

//
Property::Property(std::string name, int purchaseCost)
	:Tile{name}, purchaseCost{purchaseCost}, owner{nullptr}, morgaged{false}
{}

//
bool Property::isProperty() { return true; }
