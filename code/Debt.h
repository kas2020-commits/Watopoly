#ifndef __DEBT_H__
#define __DEBT_H__

#include "LogicException.h"
#include "Player.h"

//
class Debt : public LogicException {
  private:
    Player* owedFrom;
    Player* owedTo;
    int owed;
  public:
    Debt();
    Debt(Player* owedFrom, int owed);
    Debt(Player* owedFrom, Player* owedTo, int owed);
    void pay();
    void bankrupt();
};

#endif

