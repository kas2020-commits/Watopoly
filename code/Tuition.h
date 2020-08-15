#ifndef __TUITION_H__
#define __TUITION_H__

#include "LogicException.h"
#include "Tile.h"
#include "util.h"

//
class TuitionPayment : public LogicException {
  private:
    Player* player;
  public:
    TuitionPayment();
    TuitionPayment(Player* p);
    void payCash();
    void payPercent();
    void bankrupt();
};

//
class Tuition: public Tile {
  public:
    Tuition();
    void landEffect(Player* p) override;
};

#endif