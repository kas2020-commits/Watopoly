#ifndef __TUITION_H__
#define __TUITION_H__
#include "NonProperty.h"
#include "util.h"

/*
class PayTuition {
  private:
    Player* player;
    Tuition* tuition;
  public:
    void payCash();
    void payPercent();
};
*/

//
class Tuition: public NonProperty{
  public:
    Tuition();
    void land(Player* p) override;
};

#endif