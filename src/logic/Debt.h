#ifndef __DEBT_H__
#define __DEBT_H__

#include "LogicException.h"
#include "../data/Player.h"

//
class Debt : public LogicException {
  private:
    Player* owedFrom;
    Player* owedTo;
    int owed;
    bool payed;
  public:
    Debt();
    Debt(Player* owedFrom, int owed);
    Debt(Player* owedFrom, Player* owedTo, int owed);
    void pay();
    void bankrupt();
    virtual std::string getMessage() override;
};

#endif

