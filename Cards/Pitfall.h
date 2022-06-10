

#ifndef MTMCHKIN_H_PITFALL_H
#define MTMCHKIN_H_PITFALL_H
#include "Card.h"
#include "../Players/Rogue.h"

class Pitfall: public Card{
public:
    Pitfall();
    ~Pitfall()=default;
    void playCard(Player &player) override;

private:
    static const int DAMAGE=10;
};


#endif //MTMCHKIN_H_PITFALL_H
