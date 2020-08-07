#include "Tutition.h"
#include <iostream>
#include <string>
Tutition::Tutition(): NonProperty{TUITION}{

}
void Tutition::land(Player* p){
    applyEffect(p);
}


void Tutition::applyEffect(Player* p){
    updateObservers("You need to pay tutition, A for pay $300, B for 10% of you worth!");
    char temp; 
    while (true){
        std::cin >> temp;
        if(temp == 'A'){
            p->withdraw(300);
            break;
        } else if (temp == 'B'){
            p->withdraw(0.1 * p->displayTotalWorth()); // need to be updated 
            break;
        } else {
            updateObservers("Invalid input, try again!");
        }     
    }
}