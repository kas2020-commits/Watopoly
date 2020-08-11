#include "NeedlesHall.h"

NeedlesHall::NeedlesHall(): Tile{NEEDLES_HALL}{}

void NeedlesHall::landEffect(Player* p){
    int rutr = rand() % 100 + 1;
    if (rutr == 1){
        if(p->getTimsCups() < 4){
			p->setTimsCups(p->getTimsCups() + 1);
            updateObservers("You move forward two tiles");
        }
        // roll up the rim
    }

    int v1 = rand() % 18 + 1;
    if( v1 == 1) {
        p->withdraw(200);
        updateObservers("You lose $200 \n");
    } else if(( v1 == 2) && (v1 == 3)){
        p->withdraw(100);
        updateObservers("You lose $100 \n");
    } else if(( v1 >= 3) && (v1 <= 5)){
        p->withdraw(50);
        updateObservers("You lose $50 \n");
    } else if(( v1 >= 6) && (v1 <= 12)){
        p->deposit(25);
        updateObservers("You win $25 \n");
    } else if(( v1 >= 13) && (v1 <= 15)){
        p->deposit(50);
        updateObservers("You win $50 \n");
    } else if(( v1 >= 16 ) && (v1 <= 17)){
        p->deposit(100);
        updateObservers("You win $100 \n");
    } else if(v1 == 18){
        p->deposit(200);
        updateObservers("You win $200 \n");
    }
}
