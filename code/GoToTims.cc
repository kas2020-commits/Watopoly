#include "GoToTIms.h"

GoToTIms::GoToTIms(std::string name){
    NonProperty(name);
}
void GoToTIms::land(Player* p){
    applyEffect(p);
}
void GoToTIms::applyEffect(Player* p){
    p->move("DC Tims Line");
    updateObservers("You Go To Tims Line!");
}

