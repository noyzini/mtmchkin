
#ifndef MTMCHKIN_BATTLECARDS_H
#define MTMCHKIN_BATTLECARDS_H

#include "Card.h"

class BattleCards : public Card {
public:
    BattleCards(int force, int damageOnLoss, int coinsOnWin,std::string name);
    virtual ~BattleCards() = default;

    virtual void playCard(Player &player) const = 0;
    virtual void print(std::ostream& os) const = 0;

protected:
    int m_force;
    int m_damageOnLoss;
    int m_coinsOnWin;
    std::string m_name;

    friend class Gang;

};


#endif //MTMCHKIN_BATTLECARDS_H
