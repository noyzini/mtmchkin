#ifndef MTMCHKIN_H_GANG_H
#define MTMCHKIN_H_GANG_H
#include "Card.h"
#include "BattleCard.h"
#include <iostream>
#include <vector>
#include <memory>


class Gang: public Card {
public:
    /*
     * Default Constructor,destructor ,operator and copy constructor
    */
    Gang();
    ~Gang() override =default;
    Gang& operator=(const Gang&) =delete;
    Gang(const Gang&)=delete;
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
    void addMonster (std::unique_ptr<BattleCard> &card);

private:
    std::vector<std::unique_ptr<BattleCard>> m_gang;
    static const std::string GANG_NAME;
    static const std::string VAMPIYRE_CHECK;

};


#endif //MTMCHKIN_H_GANG_H
