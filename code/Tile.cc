#include "Tile.h"

//
int Tile::tileCount = 0;

//
Tile::Tile(std::string name) : name{name}, index{tileCount} { ++tileCount; }

//
void Tile::land(Player* p) {}

//
void Tile::pass(Player* p) {}

//
void Tile::leave(Player* p) {}

//
std::string Tile::getName() { return name; }

//
int Tile::getIndex() { return index; }

//
bool Tile::operator==(Tile & t) { return (this->index == t.index); }

//
bool Tile::isProperty() { return false; }

//
bool Tile::isAcademicBuilding() { return false; }
