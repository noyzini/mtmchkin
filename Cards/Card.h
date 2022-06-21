#ifndef MTMCHKIN_CARD_H
#define MTMCHKIN_CARD_H
#include "../Players/Player.h"
#include "../utilities.h"
#include <memory>


class Card {
public:
    /*
     * Default Constructor,destructor ,operator and copy constructor
     */
    Card() = default;
    virtual ~Card() = default;
    Card& operator=(const Card&)=default;
    Card(const Card&)=default;
    /*
    * Playing card on a given player-pure virtual
    */
    virtual void playCard(Player& player) const = 0;
    /*
    * Printing card information operator and function
    */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual void print(std::ostream& os) const = 0;
};


#endif //MTMCHKIN_CARD_H
