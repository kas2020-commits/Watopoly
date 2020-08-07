#ifndef __SLC_H__
#define __SLC_H__
#include "NonProperty.h"

class SLC : public NonProperty {
  public:
    SLC();
    virtual void applyEffect(std::shared_ptr<Player>) override;
};

#endif
