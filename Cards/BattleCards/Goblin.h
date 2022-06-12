

#ifndef MTMCHKIN_GOBLIN_H
#define MTMCHKIN_GOBLIN_H

#include "BattleCards.h"
#include "../../utilities.h"

class Goblin:public BattleCards {
public:
    Goblin();
    ~Goblin() = default;
    void playCard(Player &player) override;
    void print(std::ostream& os) const;
    //virtual Goblin* makeCard() const;
private:
    const std::string m_monsterName = "Goblin";
    static const int FORCE=6;
    static const int DAMAGE=10;
    static const int LOOT=2;
};


#endif //MTMCHKIN_GOBLIN_H
