
#include "Treasure.h"


Treasure::Treasure() : Card( )
{
}

void Treasure::playCard(Player &player) {
    player.addCoins(TREASURE);
    printTreasureMessage();
}