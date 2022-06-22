
#ifndef MTMCHKIN_VAMPIRE_H
#define MTMCHKIN_VAMPIRE_H

#include "BattleCard.h"
#include "../utilities.h"

class Vampire: public BattleCard{
public:
    /*
     * C'tor of Vampire:
     *
     * @result
     *      An instance of Vampire
    */
    Vampire();
    /*
    * Default Copy c'tor, destructor , and operator=
    */
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
