#include "Fairy.h"

const std::string Fairy::FAIRY= "Fairy";

Fairy::Fairy():Card() {

}

void Fairy::playCard(Player &player) const {
    Wizard *ptr = dynamic_cast<Wizard*>(&player);
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
    printCardDetails(os,FAIRY);
    printEndOfCardDetails(os);
}