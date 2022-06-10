
#ifndef MTMCHKIN_H_TREASURE_H
#define MTMCHKIN_H_TREASURE_H

#include "../utilities.h"
#include "Card.h"


class Treasure: public Card {
public:
    Treasure();
    ~Treasure()=default;
    void playCard(Player &player) override;

private:
    static const int TREASURE=10;

};


#endif //MTMCHKIN_H_TREASURE_H
