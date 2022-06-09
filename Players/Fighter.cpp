
#include "Fighter.h"

Fighter::Fighter(const char *name) : Player(name)
{
    const std::string s = "t";
}

int Fighter::getAttackStrength() const
{
    return (m_force*DOUBLE + m_level);
}

void Fighter::print(std::ostream &os) const
{
    printPlayerDetails(os,m_name,FIGHTER_NAME,m_level,m_force,m_hp.toInt(),m_coins);
}