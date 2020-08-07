#include "Gym.h"
#include <iostream>
#include <string>

Gym::Gym(std::string name, int purchaseCost): Property{name, purchaseCost} {}

void Gym::land(Player* p){
    if (owner != nullptr){
        int firstdice = rollDice();
        int seconddice = rollDice();
        int total = firstdice + seconddice;
    
        if(p->getGymCount() == 2){
            total = total * 10;
            std::string rollfirst = std::to_string(firstdice);
            std::string rollsecond = std::to_string(seconddice);
            updateObservers("First dice is " + rollfirst );
            updateObservers("Second dice is " + rollsecond );
            std::string str= std::to_string(total);
            updateObservers("Pay a total of " + str +"dollars!");
            p->withdraw(total);
            owner->deposit(total);
        } else if (p->getGymCount() == 1){
            total = total * 4;
            std::string rollfirst = std::to_string(firstdice);
            std::string rollsecond = std::to_string(seconddice);
            updateObservers("First dice is " + rollfirst );
            updateObservers("Second dice is " + rollsecond );
            std::string str= std::to_string(total);
            updateObservers("Pay a total of " + str +"dollars!");
            p->withdraw(total);
            owner->deposit(total);
        }

        // do execption here later
    } else {
        std::cout << "No owner";
        throw PropertyError{};
    }
}

void Gym::buy(Player* p){
    if (owner == nullptr){
        owner = p;
        p->withdraw( purchaseCost );
    } else {
        std::cout << "Have an owner!";
        throw PropertyError{};
    }
}

void Gym::mortgage(Player* p){
    if( owner == p ){
        morgaged = true;
        p->deposit( purchaseCost * 0.5 );
    } else {
        std::cout << "Wrong Owner!";
        throw PropertyError{};
    }
}

void Gym::unmortgage(Player* p){
    if(morgaged){
        morgaged = false;
        p->withdraw( purchaseCost * 0.6 );
    } else {
        std::cout << "Not Morgaged!";
        throw PropertyError{};
    }
    
}
