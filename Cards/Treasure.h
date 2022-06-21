
#ifndef MTMCHKIN_H_TREASURE_H
#define MTMCHKIN_H_TREASURE_H

#include "../utilities.h"
#include "Card.h"


class Treasure: public Card {
public:
    /*
    * Default Constructor,destructor ,operator and copy constructor
    */
    Treasure();
    ~Treasure()=default;
    Treasure& operator=(const Treasure&) =default;
    Treasure(const Treasure&)=default;
    /*
    * Playing Treasure card on a given player
    */
    void playCard(Player &player) const override;
    /*
    * Printing Treasure card information
    */
    void print(std::ostream& os) const override;
private:
    static const int LOOT=10;
    static const std::string TREASURE;

};


#endif //MTMCHKIN_H_TREASURE_H
