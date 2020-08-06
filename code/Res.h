#ifndef RES_H
#define RES_H
#include property.h


class Res: public property{
    
    protected:
    
    public:
    Res(std::string name, int purchaseCost);
    
    void land(Player* p) override;
    void buy(Player* p) override;
    void mortgage(Player* p) override;
    void unmortgage(Player* p) override;

};

#endif
