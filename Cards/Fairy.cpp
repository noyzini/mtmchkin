
#include "Fairy.h"

Fairy::Fairy():Card() {

}

void Fairy::playCard(Player &player) const {
    Wizard* ptr =dynamic_cast<Wizard*>(&player); // I don't think so but is try catch needed?
    if(ptr!= nullptr)
    {
        player.heal(HEAL_POINTS);
        printFairyMessage(true);
    }
    else
    {
        printFairyMessage(false);
    }
}

void Fairy::print(std::ostream &os) const
{
    printCardDetails(os,FAIRY); //add const here
}