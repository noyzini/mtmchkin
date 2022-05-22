//
// Created by aviaa on 5/22/2022.
//

#ifndef MTMCHKIN_HEALTHPOINTS_H
#define MTMCHKIN_HEALTHPOINTS_H

class HealthPoints
{
public:
    HealthPoints(int hp = 100):
            m_hp(hp),m_maxHP(hp)
    {
    }


private:

    int m_hp;
    int m_maxHP;

};

#endif //MTMCHKIN_HEALTHPOINTS_H
