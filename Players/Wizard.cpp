
#include "Wizard.h"

Wizard::Wizard(const char *name) : Player(name)
{
}

void Wizard::heal(int hp) {
    if(hp>0)
    {
        m_hp+=hp*DOUBLE;
    }
}