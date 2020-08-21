#include "Gym.h"
#include <sstream>

//
Gym::Gym(std::string name, int purchaseCost): Property{name, purchaseCost} {}

//
void Gym::applyFee(Player* p) {
    // throw fatal error if no owner
    std::ostringstream ss{"Payed $"};
    Roll r = p->roll();
    int payment{r.total};
    if (owner->getGymCount() == 1) payment *= 4;
    if (owner->getGymCount() == 2) payment *= 10;
    // else throw exception possibly?
    try { p->withdraw(payment); }
    catch (GameException&) { throw Debt{p, owner, payment}; }
    owner->deposit(payment);
    ss << payment << " to gym's owner: \"";
    ss << owner->getName() << "\"\n";
    updateObservers(ss.str());
}

//
void Gym::gainPropEffect() { owner->incrementGymCount(); }

//
void Gym::losePropEffect() { owner->decrementGymCount(); }

//
bool Gym::isGym() { return true; }

