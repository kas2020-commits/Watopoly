#include "Tile.h"

Tile::Tile(std::string name): name{name}, isProperty{false} {}

std::string Tile::getName(){
    return name;
}
