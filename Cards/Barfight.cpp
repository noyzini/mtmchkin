

#include "Barfight.h"

Barfight::Barfight():Card() {

}

void Barfight::playCard(Player &player) const {
    Fighter* ptr =dynamic_cast<Fighter*>(&player);
    if(ptr == nullptr)
    {
        player.damage(DAMAGE);
        printBarfightMessage(false);
    }
    else
    {
        printBarfightMessage(true);
    }
}

void Barfight::print(std::ostream &os) const
{
    printCardDetails(os,BARFIGHT); //add const here
}
