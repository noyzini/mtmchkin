//
// Created by aviaa on 6/8/2022.
//

#ifndef MTMCHKIN_CARD_H
#define MTMCHKIN_CARD_H
#include "../Players/Player.h"

class Card {
public:
    Card() = default;
    virtual ~Card() = default;

    virtual void playCard(Player& player) = 0;

};


#endif //MTMCHKIN_CARD_H
