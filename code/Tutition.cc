#include "Tutition.h"

#include <string>
Tutition::Tutition(): NonProperty{TUITION}{

}
void Tutition::land(Player* p){
    applyEffect(p);
}


void Tutition::applyEffect(Player* p){
    if(/* we choose 300 */){
        p->withdraw(300);
    } else {
        p->withdraw(0.1 * p->displayTotalWorth()); // need to be updated 
    }
}