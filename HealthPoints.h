//
// Created by aviaa on 5/22/2022.
//

#ifndef MTMCHKIN_HEALTHPOINTS_H
#define MTMCHKIN_HEALTHPOINTS_H

#include <iostream>

/*
 * TO DO:
 * Where should the +- operators be?
 *adding defult distractor
 */

class HealthPoints
{
public:
    HealthPoints(int hp = 100);

    HealthPoints& operator+=(int hp);
    HealthPoints& operator-=(int hp);

    friend bool operator==(HealthPoints hp1, HealthPoints hp2);
    friend bool operator<=(HealthPoints hp1, HealthPoints hp2);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);

    class InvalidArgument {};
private:

    int m_hp;
    int m_maxHP;

};

HealthPoints operator+(HealthPoints& hp1, int hp2);
HealthPoints operator+(int hp1, HealthPoints& hp2);
HealthPoints operator-(HealthPoints& hp1, int hp);

bool operator!=(HealthPoints hp1, HealthPoints hp2);
bool operator<(HealthPoints hp1, HealthPoints hp2);
bool operator>=(HealthPoints hp1, HealthPoints hp2);
bool operator>(HealthPoints hp1, HealthPoints hp2);


#endif //MTMCHKIN_HEALTHPOINTS_H
