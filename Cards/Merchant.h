

#ifndef MTMCHKIN_H_MERCHANT_H
#define MTMCHKIN_H_MERCHANT_H
#include "Card.h"


class Merchant : public Card{
public:
    Merchant();
    ~Merchant()=default;
    void playCard(Player& player) const override;
    void print(std::ostream &os) const override;
private:
    static const int COST_HEAL_POINT = 5;
    static const int COST_FORCE_POINT= 10;
    static const int DONT_BUY = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;
    const std::string MERCHANT = "Merchant";
};


#endif //MTMCHKIN_H_MERCHANT_H
