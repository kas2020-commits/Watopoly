#ifndef __OSAP_H__
#define __OSAP_H__
#include "NonProperty.h"

class CollectOSAP: public NonProperty{
  public:
    CollectOSAP();
    virtual void land(std::shared_ptr<Player> p) override;
    virtual void pass(std::shared_ptr<Player> p) override;
};

#endif
