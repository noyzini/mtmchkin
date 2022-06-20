
#ifndef MTMCHKIN_H_GANG_H
#define MTMCHKIN_H_GANG_H
#include "Card.h"
#include "BattleCards.h"
#include <iostream>
#include <vector>
#include <memory>

class Gang: public Card {
public:
    Gang();
    ~Gang()=default;
    void print(std::ostream& os) const override;
    void playCard(Player &player) const override;
    void addMonster (std::unique_ptr<BattleCards> &card);

private:
    std::vector<std::unique_ptr<BattleCards>> m_gang;
    const std::string GANG_NAME="Gang";

};


#endif //MTMCHKIN_H_GANG_H
