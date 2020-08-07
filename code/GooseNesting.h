#ifndef __GOOSE_NESTING_H__
#define __GOOSE_NESTING_H__
#include "NonProperty.h"

//
class GooseNesting : public NonProperty{
  public:
    GooseNesting(std::string name);
    void applyEffect(std::shared_ptr<Player> p) override;
};

#endif
