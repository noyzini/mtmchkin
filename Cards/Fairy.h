
#ifndef MTMCHKIN_H_FAIRY_H
#define MTMCHKIN_H_FAIRY_H
#include "Card.h"
#include "../Players/Wizard.h"
class Fairy : public Card{
public:
    /*
    * Default Constructor,destructor ,operator and copy constructor
    */
    Fairy();
    ~Fairy()=default;
    Fairy& operator=(const Fairy&) =default;
    Fairy(const Fairy&)=default;
    /*
    * Playing Fairy card on a given player
    */
    void playCard(Player& player) const override;
    /*
    * Printing Fairy card information
    */
    void print(std::ostream &os) const override;
private:
    static const int HEAL_POINTS = 10;
    static const int DOUBLE=2;
    static const std::string FAIRY ;
};


#endif //MTMCHKIN_H_FAIRY_H
