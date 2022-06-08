//
// Created by Noy Zini on 07/06/2022.
//

#include "Rogue.h"

Rogue::Rogue(const char *name): Player(name)
{
}

void Rogue:: addCoins(int coins)
{
    Player::addCoins(coins*DOUBLE);
}