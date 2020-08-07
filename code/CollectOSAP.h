#ifndef OSAP_H
#define OSAP_H
#include "NonProperty.h"

class CollectOSAP: public NonProperty{
  public:
    CollectOSAP();
    virtual void land(std::shared_ptr<Player> p) override;
    virtual void pass(std::shared_ptr<Player> p) override;
};

#endif
