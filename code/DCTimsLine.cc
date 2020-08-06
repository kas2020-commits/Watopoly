#include "DCTimsLine.h"
#include <string>
DCTimsLine::DCTimsLine(): NonProperty{DC_TIMS_LINE} {}

void DCTimsLine::land(Player* p){
    //
}


void DCTimsLine::applyEffect(Player* p){
    //double dice
    //50 bucks
    //use roll up the rims
    int dice1 = rolldice();
    int dice2 = rolldice();
    int dicecount = 0;
    if (dicecount != 3)
    if (dice1 != dice2){
        dicecount += 1;
    }
}