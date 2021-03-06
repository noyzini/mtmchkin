#ifndef MTMCHKIN_GOBLIN_H
#define MTMCHKIN_GOBLIN_H

#include "BattleCard.h"
#include "../utilities.h"

class Goblin:public BattleCard {
public:
    /*
     * C'tor of Goblin:
     *
     * @result
     *      An instance of Goblin
    */
    Goblin();
    /*
    * Default Copy c'tor, destructor , and operator=
    */
    ~Goblin() override = default;
    Goblin& operator=(const Goblin&) =default;
    Goblin(const Goblin&)=default;
    /*
    * Playing Goblin card on a given player
    */
    void playCard(Player &player) const override;
    /*
    * Printing Goblin card information
    */
    void print(std::ostream& os) const override;

private:
    static const std::string m_monsterName;
    static const int FORCE=6;
    static const int DAMAGE=10;
    static const int LOOT=2;
};


#endif //MTMCHKIN_GOBLIN_H
