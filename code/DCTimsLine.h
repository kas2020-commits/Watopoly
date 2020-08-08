#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__
#include "NonProperty.h"
#include "util.h"


class DCTimsLine: public NonProperty{
 public:
    DCTimsLine();
    void land(Player* p) override;
    void applyEffect(Player* p);

}; 





#endif