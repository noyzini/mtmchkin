#include "Barfight.h"

const std::string Barfight::BARFIGHT= "Barfight";

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
    printCardDetails(os,BARFIGHT);
    printEndOfCardDetails(os);
}
