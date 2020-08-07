#ifndef __COOP_FEE_H_
#define __COOP_FEE_H_
#include "NonProperty.h"

//
class CoopFee: public NonProperty{
  public:
    CoopFee();
    void land(std::shared_ptr<Player> p) override;
};

#endif
