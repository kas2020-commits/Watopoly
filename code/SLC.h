#ifndef SLC_H
#define SLC_H
#include <cstdlib>

class SLC:public NonProperty{
    
    protected:
    
    public:
    SLC(std::string name);
    void land(Player* p) override;
    void applyEffect(Player* p) override;

};

#endif
