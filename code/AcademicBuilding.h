#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include "Property.h"
#include <map>


class AcademicBuilding: public Property{

    protected:
    int improvementCost;
    int improvementLevel;
    std::vector<int> tuitionAtLevels;
    std::string blockName;

    public:
    static std::map<const std::string, int> blockMap;
    AcademicBuilding( std::string name, std::string blockName, int purchaseCost, int improvementCost,  int tutzero, int tutone, int tuttwo, int tutthree, int tutfour, int tutfive);
    void land(std::shared_ptr<Player> p) override;
    void buy(std::shared_ptr<Player> p) override;
    void mortgage(std::shared_ptr<Player> p) override;
    void unmortgage(std::shared_ptr<Player> p) override;
    void buyImprovement(std::shared_ptr<Player> p);
    void sellImprovement(std::shared_ptr<Player> p);
    int getImprovementLevel();
    bool isAcademicBuilding();

};

#endif
