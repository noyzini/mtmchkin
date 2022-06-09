//
// Created by aviaa on 6/8/2022.
//

#ifndef MTMCHKIN_BATTLECARDS_H
#define MTMCHKIN_BATTLECARDS_H

#include "../Card.h"

class BattleCards : public Card {
public:
    BattleCards(int force, int damageOnLoss, int coinsOnWin);
    virtual ~BattleCards() = default;

    virtual void playCard(Player &player) = 0;
    virtual void print(std::ostream& os) const = 0;

protected:
    int m_force;
    int m_damageOnLoss;
    int m_coinsOnWin;

};


#endif //MTMCHKIN_BATTLECARDS_H
