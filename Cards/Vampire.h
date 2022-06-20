//
// Created by aviaa on 6/8/2022.
//

#ifndef MTMCHKIN_VAMPIRE_H
#define MTMCHKIN_VAMPIRE_H

#include "BattleCards.h"
#include "../utilities.h"

class Vampire: public BattleCards{
public:
    Vampire();
    void playCard(Player &player) const override;
    void print(std::ostream& os) const override;
private:
    static const std::string m_monsterName;
    static const int FORCE=10;
    static const int DAMAGE=10;
    static const int LOOT=2;

};


#endif //MTMCHKIN_VAMPIRE_H
