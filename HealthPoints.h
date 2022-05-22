//
// Created by aviaa on 5/22/2022.
//

#ifndef MTMCHKIN_HEALTHPOINTS_H
#define MTMCHKIN_HEALTHPOINTS_H

#include <exception>

class HealthPoints : std::exception
{
public:
    HealthPoints(int hp = 100);



private:

    int m_hp;
    int m_maxHP;

};

#endif //MTMCHKIN_HEALTHPOINTS_H
