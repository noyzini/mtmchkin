

#include "Barfight.h"

Barfight::Barfight():Card() {

}

void Barfight::playCard(Player &player) {
    Fighter* ptr =dynamic_cast<Fighter*>(&player);
    if(ptr == nullptr)
    {
        player.damage(DAMAGE);
        printBarfightMessage(true);
    }
    printBarfightMessage(false);
}
