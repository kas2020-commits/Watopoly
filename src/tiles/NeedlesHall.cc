#include "NeedlesHall.h"

NeedlesHall::NeedlesHall(): Tile{NEEDLES_HALL}{}

void NeedlesHall::landEffect(Player* p){
	int theTimsBeLike = getRand(0, 100);
	int timCups = p->getTimsCups();
	// You must compare the random number to 42, otherwise the meaning of life
	// is lost :( (comparing to 1 number gives you a 1% chance of winning)
	if (theTimsBeLike == 42 && timCups < 4)
	{
		p->setTimsCups(timCups + 1);
		updateObservers("Congratulations! You just won a Roll the Rims Cup");
	}

	int rndRoll = getRand(0, 17);
	if (rndRoll == 0) {
		p->withdraw(200);
		updateObservers("You lose $200 \n");
	} else if (rndRoll == 1 || rndRoll == 2) {
		p->withdraw(100);
		updateObservers("You lose $100 \n");
	} else if (rndRoll == 3 || rndRoll == 4 || rndRoll == 5) {
		p->withdraw(50);
		updateObservers("You lose $50 \n");
	} else if (rndRoll > 5 && rndRoll < 12) {
		p->deposit(25);
		updateObservers("You win $25 \n");
	} else if (rndRoll == 12 || rndRoll == 13 || rndRoll == 14) {
		p->deposit(50);
		updateObservers("You win $50 \n");
	} else if (rndRoll == 15 || rndRoll == 16) {
		p->deposit(100);
		updateObservers("You win $100 \n");
	} else if (rndRoll == 17) {
		p->deposit(200);
		updateObservers("You win $200 \n");
	}

}

