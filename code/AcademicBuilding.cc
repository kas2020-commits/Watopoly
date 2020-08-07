#include "AcademicBuilding.h"
#include "iostream"

std::map<const std::string, int> AcademicBuilding::blockMap = {
    {"Arts1", 2}, {"Arts2", 3}, {"Eng", 3}, {"Health", 3}, {"Env", 3}, {"Sci1", 3}, {"Sci2", 3}, {"Math", 2},
};

AcademicBuilding::AcademicBuilding( std::string name, std::string blockName, int purchaseCost, int improvementCost,  int tutzero, int tutone, int tuttwo,   int tutthree, int tutfour, int tutfive): blockName{blockName}, improvementCost{improvementCost}, improvementLevel{0}, Property{name, purchaseCost} {
    tuitionAtLevels.emplace_back(tutzero);
    tuitionAtLevels.emplace_back(tutone);
    tuitionAtLevels.emplace_back(tuttwo);
    tuitionAtLevels.emplace_back(tutthree);
    tuitionAtLevels.emplace_back(tutfour);
    tuitionAtLevels.emplace_back(tutfive);
}

void AcademicBuilding::land(Player* p){
    p->withdraw(tuitionAtLevels.at(improvementLevel));
    owner->deposit(tuitionAtLevels.at(improvementLevel));
    // do execption here later
}

void AcademicBuilding::buy(Player* p){
    if (owner == nullptr){
        owner = p;
        p->withdraw( purchaseCost );
    } else {
        std::cout << "Have an owner!";
        throw PropertyError{};
    }
}

void AcademicBuilding::mortgage(Player* p){
    if( owner == p ){
        morgaged = true;
        p->deposit( purchaseCost * 0.5 );
    } else {
        std::cout << "Wrong Owner!";
        throw PropertyError{};
    }
}

void AcademicBuilding::unmortgage(Player* p){
    if(morgaged){
        morgaged = false;
        p->withdraw( purchaseCost * 0.6 );
    } else {
        std::cout << "Not Morgaged!";
        throw PropertyError{};
    }

}

void AcademicBuilding::improve(Player* p){
    if(improvementLevel < 5){
        if (p->getBlockCount(blockName) == blockMap.find(blockName)->second){
            p->withdraw(improvementCost);
            improvementLevel += 1;
        } else{
            std::cout<< "Don't have monopoly yet";
            throw PropertyError{};
        }
    } else{
        std::cout<< "already 5 improvements";
        throw PropertyError{};
    }
}

int AcademicBuilding::getImprovementLevel(){
    return improvementLevel;
}