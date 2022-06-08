//
// Created by Noy Zini on 07/06/2022.
//

#include "Wizard.h"

Wizard::Wizard(const char *name) : Player(name)
{
}

void Wizard::heal(int hp) {
    Player::heal(hp*DOUBLE);
}