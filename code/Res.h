#ifndef __RES_H__
#define __RES_H__
#include "Property.h"
#include <string>



class Res: public Property{
    
    protected:
    
    public:
    Res(std::string name, int purchaseCost);
    
    void land(std::shared_ptr<Player> p) override;
    void buy(std::shared_ptr<Player> p) override;
    void mortgage(std::shared_ptr<Player> p) override;
    void unmortgage(std::shared_ptr<Player> p) override;

};

#endif
