
#ifndef MTMCHKIN_DRAGON_H
#define MTMCHKIN_DRAGON_H

#include "BattleCard.h"
#include "../utilities.h"

class Dragon :public BattleCard {
public:
    /*
     * C'tor of Dragon:
     *
     * @result
     *      An instance of Dragon
    */
    Dragon();
    /*
    * Default Copy c'tor, destructor , and operator=
    */
    ~Dragon() override = default;
    Dragon& operator=(const Dragon&) =default;
    Dragon(const Dragon&)=default;
    /*
    * Playing Dragon card on a given player
    */
    void playCard(Player &player) const override;
    /*
    * Printing Dragon card information
    */
    void print(std::ostream& os) const override;

private:
    static const std::string m_monsterName;
    static const int FORCE=25;
    static const int LOOT=1000;
};


#endif //MTMCHKIN_DRAGON_H
