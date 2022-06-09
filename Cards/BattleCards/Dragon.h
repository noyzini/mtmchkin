//
// Created by aviaa on 6/8/2022.
//

#ifndef MTMCHKIN_DRAGON_H
#define MTMCHKIN_DRAGON_H

#include "BattleCards.h"
#include "../../utilities.h"

class Dragon :public BattleCards {
public:
    Dragon();
    ~Dragon() = default;
    void playCard(Player &player) override;

private:
    const std::string m_monsterName = "Dragon";
    static const int FORCE=25;
    static const int LOOT=1000;
};


#endif //MTMCHKIN_DRAGON_H
