#include "property.h"

Property::Property(std::string name, int purchaseCost): purchaseCost{purchaseCost}, owner{nullptr}, morgaged{false}{
    tile(name);
}

bool Property::isProperty(){
    isProperty = true;
}
