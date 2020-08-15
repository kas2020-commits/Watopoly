#include "Gym.h"
#include <sstream>

//
Gym::Gym(std::string name, int purchaseCost): Property{name, purchaseCost} {}

//
void Gym::applyFee(Player* p) {
    if (hasOwner()){
        std::ostringstream ss{"Payed $"};
        Roll r = p->roll();
        int payment{r.total};
        if (owner->getGymCount() == 1) int payment *= 4;
        if (owner->getGymCount() == 2) int payment *= 10;
        // else throw exception possibly?
        p->withdraw(payment);
        owner->deposit(payment);
        ss << payment << " to gym's owner: \""
        ss << owner->getName() << "\"\n";
        updateObservers(ss.str());
    }
    else {
        // throw buy option
    }
}

//
void Gym::gainPropEffect() { owner->incrementGymCount(); }

//
void Gym::losePropEffect() { owner->decrementGymCount(); }

//
bool Gym::isGym() { return true; }