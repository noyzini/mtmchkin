#ifndef MTMCHKIN_H_MERCHANT_H
#define MTMCHKIN_H_MERCHANT_H
#include "Card.h"


class Merchant : public Card{
public:
    /*
    * Default Constructor,destructor ,operator and copy constructor
    */
    Merchant();
    ~Merchant() override =default;
    Merchant& operator=(const Merchant&) =default;
    Merchant(const Merchant&)=default;
    /*
    * Playing Merchant card on a given player
    */
    void playCard(Player& player) const override;
    /*
    * Printing Merchant card information
    */
    void print(std::ostream &os) const override;
private:
    static const int COST_HEAL_POINT = 5;
    static const int COST_FORCE_POINT= 10;
    static const int DONT_BUY = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;
    static const int UNDEFINED =-1;
    static const std::string MERCHANT ;
};


#endif //MTMCHKIN_H_MERCHANT_H
