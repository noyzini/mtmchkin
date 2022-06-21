#ifndef MTMCHKIN_H_GANG_H
#define MTMCHKIN_H_GANG_H
#include "Card.h"
#include "BattleCards.h"
#include <iostream>
#include <vector>
#include <memory>


class Gang: public Card {
public:
    /*
     * Default Constructor,destructor ,operator and copy constructor
    */
    Gang();
    ~Gang()=default;
    Gang& operator=(const Gang&) =default;
    Gang(const Gang&)=default;
    /*
    * Playing Gang card on a given player
    */
    void playCard(Player &player) const override;
    /*
    * Printing Gang card information
    */
    void print(std::ostream& os) const override;
    /*
    * Gang contains monster cards, this function adds a monster to the gang.
    */
    void addMonster (std::unique_ptr<BattleCards> &card);

private:
    std::vector<std::unique_ptr<BattleCards>> m_gang;
    static const std::string GANG_NAME;

};


#endif //MTMCHKIN_H_GANG_H
