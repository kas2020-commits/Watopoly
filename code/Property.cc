#include "property.h"

Property::Property(int purchaseCost, std::string name): purchaseCost{purchaseCost}, owner{nullptr}, morgaged{false}{
    tile(name);
}

bool Property::isProperty(){
    isProperty = true;
}
