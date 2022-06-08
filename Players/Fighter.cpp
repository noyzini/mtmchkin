//
// Created by Noy Zini on 07/06/2022.
//

#include "Fighter.h"
#include <iostream>

Fighter::Fighter(const char *name) : Player(name)
{
    const std::string s = "t";
}

int Fighter::getAttackStrength() const
{
    return (Player::getAttackStrength() + Player::getLevel());
}

void Fighter::print(std::ostream &os) const
{
    printPlayerDetails(os,m_name,FIGHTER_NAME,m_level,m_force,m_hp.toInt(),m_coins);
}