//
// Created by aviaa on 5/22/2022.
//

#include "HealthPoints.h"

HealthPoints::HealthPoints(int hp) :
m_hp(hp),m_maxHP(hp)
{
    if (hp <= 0)
    {
        throw InvalidArgument();
    }
}



HealthPoints& HealthPoints::operator+=(const int hp)
{
    m_hp += hp;
    if (m_hp > m_maxHP)
        m_hp = m_maxHP;
    if (m_hp < 0)
        m_hp = 0;
    return *this;
}

HealthPoints operator+(HealthPoints& hp1, int hp2)
{
    hp1 += hp2;
    return hp1;
}

HealthPoints operator+(int hp1, HealthPoints& hp2)
{
    hp2 += hp1;
    return hp2;
}

HealthPoints& HealthPoints::operator-=(int hp)
{
    *this += -hp;
    return *this;
}

HealthPoints operator-(HealthPoints& hp1, int hp2)
{
    hp1 += -hp2;
    return hp1;
}

bool operator==(HealthPoints hp1, HealthPoints hp2)
{
    return hp1.m_hp == hp2.m_hp;
}

bool operator!=(HealthPoints hp1, HealthPoints hp2)
{
    return !(hp1 == hp2);
}

bool operator<=(HealthPoints hp1, HealthPoints hp2)
{
    return hp1.m_hp <= hp2.m_hp;
}

bool operator>=(HealthPoints hp1, HealthPoints hp2)
{
    return (hp1 == hp2 || !(hp1 <= hp2));
}

bool operator<(HealthPoints hp1, HealthPoints hp2)
{
    return (hp1 <= hp2 && hp1 != hp2);
}

bool operator>(HealthPoints hp1, HealthPoints hp2)
{
    return (hp1 >= hp2 && hp1 != hp2);
}

std::ostream& operator<<(std::ostream &os, const HealthPoints &hp)
{
    return (os << hp.m_hp << "(" << hp.m_maxHP << ")");
}

