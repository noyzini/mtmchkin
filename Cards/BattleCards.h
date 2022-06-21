#ifndef MTMCHKIN_BATTLECARDS_H
#define MTMCHKIN_BATTLECARDS_H

#include "Card.h"

class BattleCards : public Card {
public:
    /*
    * Default Constructor,destructor ,operator and copy constructor
    */
    BattleCards(int force, int damageOnLoss, int coinsOnWin,std::string name);
    virtual ~BattleCards() = default;
    BattleCards& operator=(const BattleCards&) =default;
    BattleCards(const BattleCards&)=default;
    /*
    * Playing BattleCards card on a given player-pure virtual
    */
    virtual void playCard(Player &player) const = 0;
    /*
    * Printing Barfight card information-pure virtual
    */
    virtual void print(std::ostream& os) const = 0;

protected:
    int m_force;
    int m_damageOnLoss;
    int m_coinsOnWin;
    std::string m_name;

    friend class Gang;

};


#endif //MTMCHKIN_BATTLECARDS_H
