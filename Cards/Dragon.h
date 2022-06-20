
#ifndef MTMCHKIN_DRAGON_H
#define MTMCHKIN_DRAGON_H

#include "BattleCards.h"
#include "../utilities.h"

class Dragon :public BattleCards {
public:
    Dragon();
    ~Dragon() = default;
    void playCard(Player &player) const override;
    void print(std::ostream& os) const;

private:
    static const std::string m_monsterName;
    static const int FORCE=25;
    static const int LOOT=1000;
};


#endif //MTMCHKIN_DRAGON_H
