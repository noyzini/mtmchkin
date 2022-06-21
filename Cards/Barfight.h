#ifndef MTMCHKIN_H_BARFIGHT_H
#define MTMCHKIN_H_BARFIGHT_H
#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"

class Barfight: public Card {
public:
    /*
     * Default Constructor,destructor ,operator and copy constructor
     */
    Barfight();
    ~Barfight() override =default ;
    Barfight& operator=(const Barfight&) =default;
    Barfight(const Barfight&)=default;
    /*
    * Playing Barfight card on a given player
    */
    void playCard(Player &player) const override;
    /*
    * Printing Barfight card information
    */
    void print(std::ostream &os) const override;
private:
    static const int DAMAGE=10;
    static const std::string BARFIGHT;
};


#endif //MTMCHKIN_H_BARFIGHT_H
