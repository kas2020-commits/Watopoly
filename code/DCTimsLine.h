#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__
#include "NonProperty.h"
#include "util.h"


class DCTimsLine: public NonProperty{
 public:
    DCTimsLine();
    void land(std::shared_ptr<Player> p) override;
    void applyEffect(std::shared_ptr<Player> p);

}; 





#endif