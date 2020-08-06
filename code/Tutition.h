#ifndef TUTITION_H
#define TUTITION_H
#include "NonProperty.h"
#include "util.h"
class Tutition: public NonProperty{
 public:
    Tutition();
    void land(Player* p) override;
    void applyEffect(Player* p) override;

}; 





#endif