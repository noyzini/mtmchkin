#ifndef MTMCHKIN_H_PITFALL_H
#define MTMCHKIN_H_PITFALL_H
#include "Card.h"
#include "../Players/Rogue.h"

class Pitfall: public Card{
public:
    /*
     * Default Constructor,destructor ,operator and copy constructor
    */
    Pitfall();
    ~Pitfall() override =default;
    Pitfall& operator=(const Pitfall&) =default;
    Pitfall(const Pitfall&)=default;
    /*
    * Playing Pitfall card on a given player
    */
    void playCard(Player &player) const override;
    /*
    * Printing Pitfall card information
    */
    void print(std::ostream& os) const override;

private:
    static const int DAMAGE=10;
    static const std::string PITFALL ;
};


#endif //MTMCHKIN_H_PITFALL_H
