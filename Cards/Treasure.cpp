#include "Treasure.h"

const std::string Treasure::TREASURE = "Treasure";

Treasure::Treasure() : Card( )
{
}

void Treasure::playCard(Player &player) const {
    player.addCoins(LOOT);
    printTreasureMessage();
}

void Treasure::print(std::ostream &os) const {
    printCardDetails(os,TREASURE);
    printEndOfCardDetails(os);
}
