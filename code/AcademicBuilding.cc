#include "AcademicBuilding.h"

static std::map<const std::string, int> AcademicBuilding::blockMap{
    blockmap.emplace("Arts1", 2);
    blockmap.emplace("Arts2", 3);
    blockmap.emplace("Eng", 3);
    blockmap.emplace("Health", 3);
    blockmap.emplace("Env", 3);
    blockmap.emplace("Sci1", 3);
    blockmap.emplace("Sci2", 3);
    blockmap.emplace("Math", 2);
};


AcademicBuilding::AcademicBuilding( std::string name, std::string blockName, int      improvementCost, int purchaseCost, int tutzero, int tutone, int tuttwo,   int tutthree, int tutfour, int tutfive): blockName{blockName}, improvementCost{improvementCost}, improvementLevel{0} {
    property{purchaseCost, name};
    tuitionAtLevels.emplace_back(tutzero);
    tuitionAtLevels.emplace_back(tutone);
    tuitionAtLevels.emplace_back(tuttwo);
    tuitionAtLevels.emplace_back(tutthree);
    tuitionAtLevels.emplace_back(tutfour);
    tuitionAtLevels.emplace_back(tutfive);
}

void AcademicBuilding::land(Player* p){
    owner->deposit(tuitionAtLevels.at(improvementLevel));
    p->withdraw(tuitionAtLevels.at(improvementLevel));
    // do execption here later
}

void AcademicBuilding::buy(Player* p){
    if (owner == nullptr){
        owner = p;
        p->withdraw( purchaseCost );
    } else {
        std::cout << "Have an owner!";
        throw propertyerror;
    }
}

void AcademicBuilding::mortgage(Player* p){
    if( owner == p ){
        morgaged = true;
        p->deposit( purchaseCost * 0.5 );
    } else {
        std::cout << "Wrong Owner!"
        throw propertyerror;
    }
}

void AcademicBuilding::unmortgage(Player* p){
    if(morgaged){
        morgaged = false;
        p->withdraw( purchaseCost * 0.6 );
    } else {
        std::cout << "Not Morgaged!";
        throw propertyerror;
    }
    
}

void improve(Player* p){
    if(improvementLevel < 5){
        if (p->getBlockCount(blockName) == blockmap.find(blockName)->second){
            p->withdraw(improvementCost);
            // add not enough money error maybe
            improvementLevel += 1;
        } else{
            std::cout<< "Don't have monopoly yet";
            throw propertyerror;
        }
    } else{
        std::cout<< "already 5 improvements";
        throw propertyerror;
    }
}
