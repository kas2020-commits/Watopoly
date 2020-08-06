#include "property.h"

Property::Property(std::string name){
    tile(name);
}

bool Property::setIsProperty(){
    isProperty = false;
}
