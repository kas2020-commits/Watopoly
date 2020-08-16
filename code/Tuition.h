#ifndef __TUITION_H__
#define __TUITION_H__

#include "LogicException.h"
#include "Tile.h"
#include "util.h"
#include "Player.h"
#include "GameException.h"

//
class TuitionPayment : public LogicException {
  private:
    Player* player;
    bool payed;
  public:
    TuitionPayment();
    TuitionPayment(Player* p);
    void payCash();
    void payPercent();
    void bankrupt();
    virtual std::string getMessage() override;
};

//
class Tuition: public Tile {
  public:
    Tuition();
    void landEffect(Player* p) override;
};

#endif

