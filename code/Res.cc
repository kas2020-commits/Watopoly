#include "Res.h"
#include <iostream>
#include <string>

Res::Res(std::string name, int purchaseCost){
    property(name, purchaseCost);
}

void Res::land(Player* p){
    if (owner != nullptr){
        if(p->getResCount() == 4){
            owner->deposit(200);
            p->withdraw(200);
        } else if(p->getResCount() == 3){
            owner->deposit(100);
            p->withdraw(100);
        } else if(p->getResCount() == 2){
            owner->deposit(50);
            p->withdraw(50);
        } else if(p->getResCount() == 1){
            owner->deposit(25);
            p->withdraw(25);
        }
    } else {
        std::cout << "No owner";
        throw propertyerror;
    }
}

void Res::buy(Player* p){
    if (owner == nullptr){
        owner = p;
        p->withdraw( purchaseCost );
    } else {
        std::cout << "Have an owner!";
        throw propertyerror;
    }
}

void Res::mortgage(Player* p){
    if( owner == p ){
        morgaged = true;
        p->deposit( purchaseCost * 0.5 );
    } else {
        std::cout << "Wrong Owner!"
        throw propertyerror;
    }
}

void Res::unmortgage(Player* p){
    if(morgaged){
        morgaged = false;
        p->withdraw( purchaseCost * 0.6 );
    } else {
        std::cout << "Not Morgaged!";
        throw propertyerror;
    }
    
}
