#include "Pitfall.h"

const std::string Pitfall::PITFALL ="Pitfall";

Pitfall::Pitfall():Card() {

}

void Pitfall::playCard(Player &player) const {
    Rogue* ptr = dynamic_cast<Rogue*>(&player);
    if(ptr == nullptr)
    {
        player.damage(DAMAGE);
        printPitfallMessage(false);
    }
    else
    {
        printPitfallMessage(true);
    }
}

void Pitfall::print(std::ostream &os) const
{
    printCardDetails(os,PITFALL);
    printEndOfCardDetails(os);
}