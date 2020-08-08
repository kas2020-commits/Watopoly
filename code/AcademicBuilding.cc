#include "AcademicBuilding.h"

//
std::map<const std::string, int> AcademicBuilding::blockMap = {
    {"Arts1", 2}, {"Arts2", 3}, {"Eng", 3}, {"Health", 3}, 
    {"Env", 3}, {"Sci1", 3}, {"Sci2", 3}, {"Math", 2},
};

//
AcademicBuilding::AcademicBuilding(std::string name, std::string blockName, 
  int purchaseCost, int improvementCost, int tuit0, int tuit1, int tuit2, 
  int tuit3, int tuit4, int tuit5) : 
  Property{name, purchaseCost}, blockName{blockName}, improvementCost{improvementCost}, improvementLevel{0} {
    tuitionAtLevels = std::vector<int>{tuit0, tuit1, tuit2, tuit3, tuit4, tuit5};
}

//
void AcademicBuilding::land(Player* p){
    /*
    p->withdraw(tuitionAtLevels.at(improvementLevel));
    owner->deposit(tuitionAtLevels.at(improvementLevel));
    // do execption here later
    */
}

//
void AcademicBuilding::buy(Player* p) {
    /*
    if (owner == nullptr){
        owner = p;
        p->withdraw( purchaseCost );
    } else {
        std::cout << "Have an owner!";
        throw PropertyException{};
    }
    */
}

//
void AcademicBuilding::mortgage(Player* p) {
    /*
    if( owner == p ){
        morgaged = true;
        p->deposit( purchaseCost * 0.5 );
    } else {
        std::cout << "Wrong Owner!";
        throw PropertyException{};
    }
    */
}

//
void AcademicBuilding::unmortgage(Player* p) {
    /*
    if(morgaged){
        morgaged = false;
        p->withdraw( purchaseCost * 0.6 );
    } else {
        std::cout << "Not Morgaged!";
        throw PropertyException{};
    }
    */
}

//
void AcademicBuilding::buyImprovement(Player* p) {
    /*
    if(improvementLevel < 5){
        if (p->getBlockCount(blockName) == blockMap.find(blockName)->second){
            p->withdraw(improvementCost);
            improvementLevel += 1;
        } else{
            std::cout<< "Don't have monopoly yet";
            throw PropertyException{};
        }
    } else{
        std::cout<< "already 5 improvements";
        throw PropertyException{};
    }
    */
}

//
void AcademicBuilding::sellImprovement(Player* p) {
    /*
    if(improvementLevel > 0){
        p->deposit(improvementCost * 0.5);
        improvementLevel -= 1;
    } else{
            std::cout<< "no improvements!";
        throw PropertyException{};
    }
    */
}

//
int AcademicBuilding::getImprovementLevel(){
    return improvementLevel;
}

//
bool AcademicBuilding::isAcademicBuilding() { return true; }