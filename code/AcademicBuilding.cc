#include "AcademicBuilding.h"
#include "GameException.h"

//
std::map<const std::string, int> AcademicBuilding::blockMonopoly = {
	{"Arts1", 2}, {"Arts2", 3}, {"Eng", 3}, {"Health", 3},
	{"Env", 3}, {"Sci1", 3}, {"Sci2", 3}, {"Math", 2},
};

//
AcademicBuilding::AcademicBuilding(std::string name, std::string block,
  int purchaseCost, int improvementCost, int tuit0, int tuit1, int tuit2,
  int tuit3, int tuit4, int tuit5) :
  Property{name, purchaseCost}, improvementCost{improvementCost},
  improvementLevel{0}, block{block}, tuitionAtLevels{
  std::vector<int>{tuit0, tuit1, tuit2, tuit3, tuit4, tuit5}} {}

//
bool AcademicBuilding::ownerHasMonopoly {
	if (!hasOwner()) return false;
	return (owner->getBlockCount(block) == blockMonopoly[block]);
}

//
void AcademicBuilding::applyFee(Player* p){
	int payment;
	if (ownerHasMonopoly() && improvementLevel == 0) payment = tuitionAtLevels[0] * 2;
	else payment = tuitionAtLevels[improvementLevel];
	p->withdraw(payment);
	owner->deposit(payment);
}

//
void AcademicBuilding::otherMortgageExcepts() {
	if (improvementLevel >= 0)
		throw GameException{"Cannot mortgage an academic building with improvements.\n"};
}

//
void AcademicBuilding::buyImprovement() {
	if (!ownerHasMonopoly())
		throw GameException{"Cannot buy improvements, need a monopoly first.\n"};
	else if (improvementLevel >= 5)
		throw GameException{"\"" + name + "\" is at improvement limit (5).\n"};
	// otherwise, we can buy an exception assuming player has necessary funds
	owner->withdraw(improvementCost); // may throw
	improvementLevel += 1;
	updateObservers("Bought improvement on \"" + name + "\".\n");
}

//
void AcademicBuilding::sellImprovement() {
	else if (improvementLevel <= 0)
		throw GameException{"\"" + name + "\" has no improvements.\n"};
	// otherwise, we can buy an exception assuming player has necessary funds
	improvementLevel -= 1;
	owner->deposit(0.5 * improvementCost); // may throw
	updateObservers("Sold improvement on \"" + name + "\".\n");
}

//
void AcademicBuilding::gainPropEffect() { owner->incrementBlockCount(blockName); }

//
void AcademicBuilding::losePropEffect() { owner->decrementBlockCount(blockName); }

//
int AcademicBuilding::getImprovementLevel(){ return improvementLevel; }

//
bool AcademicBuilding::isAcademicBuilding() { return true; }
