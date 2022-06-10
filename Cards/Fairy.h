
#ifndef MTMCHKIN_H_FAIRY_H
#define MTMCHKIN_H_FAIRY_H
#include "Card.h"
#include "../Players/Wizard.h"
class Fairy : public Card{
private:
    Fairy();
    ~Fairy()=default;
    void playCard(Player& player) override;

private:
    static const int HEAL_POINTS = 10;
    static const int DOUBLE=2;
};


#endif //MTMCHKIN_H_FAIRY_H
