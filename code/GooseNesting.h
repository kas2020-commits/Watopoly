#ifndef __GOOSE_NESTING_H__
#define __GOOSE_NESTING_H__
#include "NonProperty.h"

//
class GooseNesting : public NonProperty{
  public:
    GooseNesting();
    void land(Player* p) override;
};

#endif
