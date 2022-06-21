
#include "Wizard.h"

const std::string Wizard::WIZARD_NAME ="Wizard";

Wizard::Wizard(const char *name) : Player(name)
{
}

void Wizard::heal(int hp) {
    if(hp>0)
    {
        m_hp+=hp*DOUBLE;
    }
}

void Wizard::print(std::ostream& os) const
{
    printPlayerDetails(os,m_name,WIZARD_NAME,m_level,m_force,m_hp.toInt(),m_coins);
}