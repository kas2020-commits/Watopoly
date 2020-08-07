#include "NonProperty.h"

NonProperty::NonProperty(std::string name): Tile{name}{
}

bool NonProperty::isProperty() { return true; }
