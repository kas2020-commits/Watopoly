#include <sstream>

#include "Residence.h"

//
Residence::Residence(std::string name, int purchaseCost):
  Property(name, purchaseCost){}

//
void Residence::landEffect(Player*  p){
    if (hasOwner()) {
        int payment;
        if(p->getResCount() == 1) payment = 25;
        else if(p->getResCount() == 2) payment = 50;
        else if(p->getResCount() == 3) payment = 100;
        else if(p->getResCount() == 4) payment = 200;
        // else throw exception possibly?
        try { p->withdraw(payment); }
        catch (GameException&) { throw Debt{p, owner, payment}; }
        owner->deposit(payment);
        std::ostringstream ss{"Payed $"};
        ss << payment << " for rent to land lord: \""
        ss << owner->getName() << "\"";
        updateObservers(ss.str());
    }
    else {
        // throw buy option
    }
}

//
void Residence::gainPropEffect() { owner->incrementResCount(); }

//
void Residence::losePropEffect() { owner->decrementResCount(); }

//
bool Residence::isRes() { return true; }
