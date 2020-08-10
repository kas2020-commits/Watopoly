#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include "Property.h"
#include <map>


class AcademicBuilding : public Property{
	protected:
		int improvementCost;
		int improvementLevel;
		std::string blockName;
		std::vector<int> tuitionAtLevels;
	public:
		friend class IO;
		static std::map<const std::string, int> blockMap;
		AcademicBuilding(std::string name, std::string blockName,
				int purchaseCost, int improvementCost,  int tuit0,
				int tuit1, int tuit2, int tuit3, int tuit4, int tuit5);
		virtual void land(Player* p) override;
		virtual void buy(Player* p) override;
		virtual void mortgage(Player* p) override;
		virtual void unmortgage(Player* p) override;
		void buyImprovement(Player* p);
		void sellImprovement(Player* p);
		int getImprovementLevel();
		virtual bool isAcademicBuilding() override;
};

#endif
