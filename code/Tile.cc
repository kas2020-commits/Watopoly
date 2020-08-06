#include "Tile.h"
int Tile::tileCount = 0;

Tile::Tile(std::string name): name{name}, isProperty{false}, index{tileCount} {
    tileCount += 1;
}

std::string Tile::getName(){
    return name;
}

int Tile::getIndex(){
    return index;
}