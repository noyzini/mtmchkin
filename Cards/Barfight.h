
#ifndef MTMCHKIN_H_BARFIGHT_H
#define MTMCHKIN_H_BARFIGHT_H
#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"

class Barfight: public Card {
public:
    Barfight();
    ~Barfight()=default;
    void playCard(Player &player) override;

private:
    static const int DAMAGE=10;
};


#endif //MTMCHKIN_H_BARFIGHT_H
