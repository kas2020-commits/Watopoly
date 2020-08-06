#ifndef NONPROPERTY_H
#define NONPROPERTY_H
#include "Tile.h"
#include "Player.h"


class NonProperty : public Tile{

    protected:

    public:
    NonProperty(std::string name);
    virtual void applyEffect(Player*);
<<<<<<< HEAD
    virtual bool setIsProperty() override;
=======
    bool setIsProperty() override;
    
>>>>>>> f1838a8af29f331755e1a5a56655a910b0a63c30

};

#endif
