#ifndef __GO_TO_TIMS_H__
#define __GO_TO_TIMS_H__
#include "NonProperty.h"

//
class GoToTims : public NonProperty {
  public:
    GoToTims(std::string name);
    void land(Player* p) override;
};

#endif
