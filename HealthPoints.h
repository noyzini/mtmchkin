
#ifndef MTMCHKIN_HEALTHPOINTS_H
#define MTMCHKIN_HEALTHPOINTS_H

#include <iostream>
#include <stdio.h>


class HealthPoints
{
public:
    /*
     * C'tor of Heal Points:
     * @param hp - max and start hp.
     *      An instance of Mtmchkin
    */
    HealthPoints(int hp = DEFAULT_HP);

    /*
    * Here we are explicitly telling the compiler to use the default methods for copy c'tor, d'tor and
     * assignment operator
    */
    HealthPoints(const HealthPoints& hp) = default;
    ~HealthPoints()=default;
    HealthPoints& operator=(const HealthPoints& hp)=default;
    /*
    * Returns the hp as an integer
     *
     * @return
     *          hp (int)
    */
    int toInt() const;
    /*
    *operators and friend operators for Health Points
    */
    HealthPoints& operator+=(int hp);
    HealthPoints& operator-=(int hp);

    friend bool operator==(HealthPoints hp1, HealthPoints hp2);
    friend bool operator<=(HealthPoints hp1, HealthPoints hp2);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);

    /*
    *class for exceptions
    */
    class InvalidArgument {};

private:
    int m_hp;
    int m_maxHP;

    static int const DEFAULT_HP=100;
};

/*
*operators for Health Points
*/
HealthPoints operator+(HealthPoints& hp1, int hp2) ;
HealthPoints operator+(int hp1, HealthPoints& hp2) ;
HealthPoints operator-(HealthPoints& hp1, int hp) ;

bool operator!=(HealthPoints hp1, HealthPoints hp2);
bool operator<(HealthPoints hp1, HealthPoints hp2);
bool operator>=(HealthPoints hp1, HealthPoints hp2);
bool operator>(HealthPoints hp1, HealthPoints hp2);


#endif //MTMCHKIN_HEALTHPOINTS_H
