#ifndef DCTIMSLINE_H
#define DCTIMSLINE_H
#include "NonProperty.h"
#include "util.h"


class DCTimsLine: public NonProperty{
 public:
    DCTimsLine();
    void land(Player* p) override;
    void applyEffect(Player* p) override;

}; 





#endif