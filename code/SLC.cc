#include <string>
#include "SLC.h"
#include "util.h"

//
SLC::SLC(): NonProperty{SLC_S} {}

//
void SLC::land(Player* p){ 
    int rutr = rand() % 100 + 1;
    if (rutr == 1 && p->getTotalTimsCups() < 4) {
        p->changeTimsCups(1);
        updateObservers("You won a Roll Up the Rim cup");
    }
    int v1 = rand() % 24 + 1;
    if(( v1 >= 1) && (v1 <=3)){
        //Back 3
        p->move(-3);
        updateObservers("You move back three tiles");
    } else if(( v1 >= 4) && (v1 <= 7)){
        //Back 2
        p->move(-2);
        updateObservers("You move back two tiles");
    } else if(( v1 >= 8) && (v1 <= 11)){
        //Back 1
        p->move(-1);
        updateObservers("You move back a tile");
    } else if(( v1 >= 12) && (v1 <= 14)){
        //Forward 1
        p->move(1);
        updateObservers("You move forward a tile");
    } else if(( v1 >= 15) && (v1 <= 18)){
        //Forward 2
        p->move(2);
        updateObservers("You move forward two tiles");
    } else if(( v1 >= 19) && (v1 <= 22)){
        //Forward 3
        p->move(3);
        updateObservers("You move forward three tiles");
    } else if(v1 == 23){
        //Go to DC Tims Line
        p->move("DC Tims Line");
        updateObservers("You move to DC Tims Line");
    } else if(v1 == 24){
        //Advance to Collect OSAP
        p->move("Collect OSAP");
        updateObservers("You move Collect OSAP");
    }
}
