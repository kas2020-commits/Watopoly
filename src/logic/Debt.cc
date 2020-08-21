#include <sstream>
#include "Debt.h"
#include "GameException.h"

//
Debt::Debt(Player* owedFrom, Player* owedTo, int owed) :
    owedFrom{owedFrom}, owedTo{owedTo}, owed{owed}, payed{false} {}

//
Debt::Debt(Player* owedFrom, int owed) :
    owedFrom{owedFrom}, owedTo{nullptr}, owed{owed} {}

//
Debt::Debt() : owedFrom{nullptr}, owedTo{nullptr}, owed{0} {}

//
void Debt::pay() {
    owedFrom->withdraw(owed); // throw exception if fails
    if (owedTo) owedTo->deposit(owed); // else add cash to bank
    payed = true;
}

void Debt::bankrupt() {
    if (owedFrom->getCash() >= owed) {
        throw GameException{"You can pay your debt, no reason to go bankrupt."};
    }
    //otherwise, allow bankruptcy
    owedFrom->setBankrupt();
}

std::string Debt::getMessage() {
    std::ostringstream ss{};
    std::string name = owedTo? "\"" + owedTo->getName() + "\"": "the Bank";
    if (!payed) {
        ss << "You owe " << name << " $" << owed;
        ss << ". Find a way to pay them or declare bankruptcy.\n";
    }
    else {
        ss << "You no longer owe money to " << name << "\n";
    }
    return ss.str();
}

