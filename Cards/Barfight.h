
#ifndef MTMCHKIN_H_BARFIGHT_H
#define MTMCHKIN_H_BARFIGHT_H
#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"

class Barfight: public Card {
public:
    Barfight();
    ~Barfight()=default;
    void playCard(Player &player) const override;
    void print(std::ostream &os) const override;
private:
    static const int DAMAGE=10;
    const std::string BARFIGHT = "Barfight";
};


#endif //MTMCHKIN_H_BARFIGHT_H
