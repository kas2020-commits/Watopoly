#ifndef TUIION_H
#define TUITION_H
#include "NonProperty.h"
#include "util.h"
class Tuition: public NonProperty{
 public:
    Tuition();
    void land(Player* p) override;
    void applyEffect(Player* p) override;

}; 





#endif