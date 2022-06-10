
#include "Pitfall.h"

Pitfall::Pitfall():Card() {

}

void Pitfall::playCard(Player &player) {
    Rogue* ptr =dynamic_cast<Rogue*>(&player);
    if(ptr == nullptr)
    {
        player.damage(DAMAGE);
        printPitfallMessage(true);
    }
    printPitfallMessage(false);
}