#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include "Property.h"
#include <map>


class AcademicBuilding : public Property{
  protected:
    int improvementCost;
    int improvementLevel;
    std::vector<int> tuitionAtLevels;
    std::string blockName;
  public:
    static std::map<const std::string, int> blockMap;
    AcademicBuilding(std::string name, std::string blockName,
        int purchaseCost, int improvementCost,  int tuit0,
        int tuit1, int tuit2, int tuit3, int tuit4, int tuit5);
    void land(Player* p) override;
    void buy(Player* p) override;
    void mortgage(Player* p) override;
    void unmortgage(Player* p) override;
    void buyImprovement(Player* p);
    void sellImprovement(Player* p);
    int getImprovementLevel();
    bool isAcademicBuilding();
};

#endif
