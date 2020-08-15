#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include <map>
#include "Property.h"
#include "Debt.h"

//
class AcademicBuilding : public Property {
	friend class IO;

	private:
	bool ownerHasMonopoly();

	protected:
	static std::map<const std::string, int> blockMonopoly;
	int improvementCost;
	int improvementLevel;
	std::string block;
	std::vector<int> tuitionAtLevels;
	virtual void applyFee(Player* p) override;
	virtual void gainPropEffect() override;
	virtual void losePropEffect() override;
	virtual void otherMortgageExcepts() override;

	public:
	AcademicBuilding(std::string name, std::string block,
			int purchaseCost, int improvementCost, int tuit0,
			int tuit1, int tuit2, int tuit3, int tuit4, int tuit5);
	void buyImprovement();
	void sellImprovement();
	int getImprovementLevel();
	virtual bool isAcademicBuilding() override;
};

#endif
