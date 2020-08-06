#ifndef TILE_H
#define TILE_H


class Tile{
    
    protected:
    std::string name;
    bool isProperty;
    
    public:
    Tile(std::string name);
    virtual void land(Player *) = 0;
    virtual void pass(Player *);
    virtual bool isProperty() = 0;
    

};

#endif
