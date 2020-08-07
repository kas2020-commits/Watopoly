#ifndef DCTIMSLINE_H
#define DCTIMSLINE_H
#include "NonProperty.h"
#include "util.h"


class DCTimsLine: public NonProperty{
 public:
    DCTimsLine();
    void land(std::shared_ptr<Player> p) override;
    void applyEffect(std::shared_ptr<Player> p);

}; 





#endif