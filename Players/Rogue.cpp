
#include "Rogue.h"

const std::string Rogue::ROGUE_NAME = "Rogue";

Rogue::Rogue(const std::string& name): Player(name)
{
}

void Rogue::addCoins(int coins)
{
    if(coins>=0)
    {
        m_coins+=coins*DOUBLE;
    }
}

void Rogue::print(std::ostream &os) const
{
    printPlayerDetails(os,m_name,ROGUE_NAME,m_level,m_force,m_hp.toInt(),m_coins);
}