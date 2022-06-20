
#ifndef MTMCHKIN_CARD_H
#define MTMCHKIN_CARD_H
#include "../Players/Player.h"
#include "../utilities.h"
#include <memory>


class Card {
public:
    Card() = default;
    virtual ~Card() = default;

    virtual void playCard(Player& player) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual void print(std::ostream& os) const = 0;
};


#endif //MTMCHKIN_CARD_H
