#ifndef __OSAP_H__
#define __OSAP_H__
#include "NonProperty.h"

class CollectOSAP: public NonProperty{
  public:
    CollectOSAP();
    virtual void land(Player* p) override;
    virtual void pass(Player* p) override;
};

#endif
