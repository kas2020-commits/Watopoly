#include "DCTimsLine.h"
#include <string>
#include <iostream>
DCTimsLine::DCTimsLine(): NonProperty{DC_TIMS_LINE} {}

void DCTimsLine::land(Player* p){
}


void DCTimsLine::applyEffect(Player* p){
    int dice1, dice2, counter;
    char temp;
    counter = 0;
    while (counter < 3){
        updateObservers("Please choose which action you want to do in the DC Tims Line");
        updateObservers("A for roll dice, B for pay $50, C for use a roll up the rim cup ");
        // interaction right here
        std::cin >> temp;
        if(temp == 'A'){
            dice1 = rolldice();
            dice2 = rolldice();
            if(dice1 != dice2){
                updateObservers("Not same, try again");
                counter += 1;
            } else {
                updateObservers("Same number, congrats you may leave now.");
                break;
            }
        } else if (temp == 'B'){
            p->withdraw(50);
            updateObservers("Paid 50 dollars for coffee");
            break;
        } else if (temp == 'C'){
            p->changeTimsCups(-1);
            updateObservers("Use a roll up the rim up!");
            break;
        } else {
            updateObservers("invalid input");
        }
        
    }
    if (counter == 3){
        updateObservers("You can only pay or use roll up the rim now");
        updateObservers("A for pay 50 dollars, B for use a roll up the rim cup!");
        std::cin >> temp;
        while (true){
            if (temp == 'A'){
                p->withdraw(50);
                updateObservers("Paid 50 dollars for coffee");
                break;
            } else if (temp == 'B'){
                p->changeTimsCups(-1);
                updateObservers("Use a roll up the rim up!");
                break;
            } else {
                updateObservers("invalid input, try again!");
            }
        }
    }

}