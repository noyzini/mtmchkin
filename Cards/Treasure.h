
#ifndef MTMCHKIN_H_TREASURE_H
#define MTMCHKIN_H_TREASURE_H

#include "../utilities.h"
#include "Card.h"


class Treasure: public Card {
public:
    Treasure();
    ~Treasure()=default;
    void playCard(Player &player) const override;
    void print(std::ostream& os) const override;
private:
    static const int LOOT=10;
    const std::string TREASURE = "Treasure";

};


#endif //MTMCHKIN_H_TREASURE_H
