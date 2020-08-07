#include "Res.h"
#include <iostream>
#include <string>

Res::Res(std::string name, int purchaseCost): Property(name, purchaseCost){}

void Res::land(std::shared_ptr<Player> p){
    if (owner != nullptr){
        if(p->getResCount() == 4){
            p->withdraw(200);
            owner->deposit(200);

        } else if(p->getResCount() == 3){
            p->withdraw(100);
            owner->deposit(100);

        } else if(p->getResCount() == 2){
            p->withdraw(50);
            owner->deposit(50);

        } else if(p->getResCount() == 1){
            p->withdraw(25);
            owner->deposit(25);

        }
    } else {
        std::cout << "No owner";
        throw PropertyException{};
    }
}

void Res::buy(std::shared_ptr<Player> p){
    if (owner == nullptr){
        owner = p;
        p->withdraw( purchaseCost );
    } else {
        std::cout << "Have an owner!";
        throw PropertyException{};
    }
}

void Res::mortgage(std::shared_ptr<Player> p){
    if( owner == p ){
        morgaged = true;
        p->deposit( purchaseCost * 0.5 );
    } else {
        std::cout << "Wrong Owner!";
        throw PropertyException{};
    }
}

void Res::unmortgage(std::shared_ptr<Player> p){
    if(morgaged){
        morgaged = false;
        p->withdraw( purchaseCost * 0.6 );
    } else {
        std::cout << "Not Morgaged!";
        throw PropertyException{};
    }
    
}
