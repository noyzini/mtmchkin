
#include "Pitfall.h"

Pitfall::Pitfall():Card() {

}

void Pitfall::playCard(Player &player) const {
    /*
     * Notes:
     * Understand why it works, but nice!
     * Switched conditions and true/false on prints
     * need to fix other cpps accordingly, and add function print
     */
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
    printCardDetails(os,PITFALL); //add const here
}