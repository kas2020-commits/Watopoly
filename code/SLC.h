#ifndef __SLC_H__
#define __SLC_H__
#include "NonProperty.h"

class SLC : public NonProperty {
  public:
    SLC();
    void land(std::shared_ptr<Player> p) override;
};

#endif
