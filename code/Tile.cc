#include "Tile.h"

//
int Tile::tileCount = 0;

//
Tile::Tile(std::string name) : name{name}, index{tileCount} { ++tileCount; }

//
void Tile::landEffect(Player* p) {}

// template function
void Tile::land(Player* p) {
    updateObservers("Landed on tile: " + name + "\n");
    landEffect(p);
}

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

//
bool Tile::isGym() { return false; }

//
bool Tile::isRes() { return false; }