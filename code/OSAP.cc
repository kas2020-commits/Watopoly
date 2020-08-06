#include "OSAP.h"

OSAP::OSAP(std::string name): NonProperty(name){}

void OSAP::land(Player* p){
    applyEffect(p);
}

void OSAP::pass(Player* p){
    applyEffect(p);
}

void OSAP::applyEffect(Player* p){
    p->deposit(200);
    updateObservers("You get OSAP $200 !");

}

