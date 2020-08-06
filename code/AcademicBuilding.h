#ifndef ACADEMICBUILDING_H
#define ACADEMICBUILDING_H
#include "Property.h"


class AcademicBuilding: public Property{

    protected:
    int improvementCost;
    int improvementLevel;
    std::vector<int> tuitionAtLevels;
    std::string blockName;

    public:
    static std::map<const std::string, int> blockMap;
    AcademicBuilding( std::string name, std::string blockName, int purchaseCost, int improvementCost,  int tutzero, int tutone, int tuttwo, int tutthree, int tutfour, int tutfive);

    void land(Player* p) override;
    void buy(Player* p) override;
    void mortgage(Player* p) override;
    void unmortgage(Player* p) override;
    void improve(Player* p);


};

#endif
