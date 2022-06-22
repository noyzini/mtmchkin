#ifndef MTMCHKIN_H_FIGHTER_H
#define MTMCHKIN_H_FIGHTER_H

#include "Player.h"
#include "../utilities.h"

class Fighter : public Player
{
public:
    /*
     * C'tor of the player:
     *
     * @param name - The name of the player.
     * @result
     *      An instance of Rogue
    */
    Fighter(const std::string& name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Fighter() override =default;
    Fighter(const Fighter&) = default;
    Fighter& operator=(const Fighter&) = default;
    /*
     * Returns the attack strength of the player.
     * Fighter's attack strength is twice the force + player level
     *
     * @return
     *          Player's attack strength
    */
    int getAttackStrength() const override;

protected:
    /*
     * Virtual print function
     */
    void print(std::ostream& os) const override;

private:
    static const std::string FIGHTER_NAME;
};


#endif //MTMCHKIN_H_FIGHTER_H
