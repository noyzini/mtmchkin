
#include "Fairy.h"

Fairy::Fairy():Card() {

}

void Fairy::playCard(Player &player) {
    Wizard* ptr =dynamic_cast<Wizard*>(&player); // I don't think so but is try catch needed?
    if(ptr!= nullptr)
    {
        player.heal(HEAL_POINTS);
        printFairyMessage(false);
    }
    printFairyMessage(true);
}