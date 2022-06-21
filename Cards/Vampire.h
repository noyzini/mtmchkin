
#ifndef MTMCHKIN_VAMPIRE_H
#define MTMCHKIN_VAMPIRE_H

#include "BattleCards.h"
#include "../utilities.h"

class Vampire: public BattleCards{
public:
    /*
    * Default Constructor,destructor ,operator and copy constructor
    */
    Vampire();
    ~Vampire() override=default;
    Vampire& operator=(const Vampire&) =default;
    Vampire(const Vampire&)=default;
    /*
    * Playing Vampire card on a given player
    */
    void playCard(Player &player) const override;
    /*
    * Printing Vampire card information
    */
    void print(std::ostream& os) const override;
private:
    static const std::string m_monsterName;
    static const int FORCE=10;
    static const int DAMAGE=10;
    static const int LOOT=2;

};


#endif //MTMCHKIN_VAMPIRE_H
