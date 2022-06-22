
#include "Fighter.h"

const std::string Fighter::FIGHTER_NAME = "Fighter";

Fighter::Fighter(const std::string& name) : Player(name)
{
}

int Fighter::getAttackStrength() const
{
    return (m_force*DOUBLE + m_level);
}

void Fighter::print(std::ostream &os) const
{
    printPlayerDetails(os,m_name,FIGHTER_NAME,m_level,m_force,m_hp.toInt(),m_coins);
}