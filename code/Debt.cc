#include "Debt.h"
#include "GameException.h"

//
Debt::Debt(Player* owedFrom, Player* owedTo, int owed) :
    owedFrom{owedFrom}, owedTo{owedTo}, owed{owed} {}

//
Debt::Debt(Player* owedFrom, int owed) :
    owedFrom{owedFrom}, owedTo{nullptr}, owed{owed} {}

//
Debt::Debt() : owedFrom{nullptr}, owedTo{nullptr}, owed{0} {}

//
void Debt::pay() {
    owedFrom->withdraw(owed); // throw exception if fails
    if (owedTo) owedTo->deposit(owed);
    // else add cash to bank
}

void Debt::bankrupt() {
    if (owedFrom->getCash() >= owed) {
        throw GameException{"You can pay your debt, no reason to go bankrupt."};
    }
    //otherwise, allow bankruptcy
    owedFrom->setBankrupt();
}
