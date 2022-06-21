
#ifndef MTMCHKIN_H_WIZARD_H
#define MTMCHKIN_H_WIZARD_H

#include "Player.h"
#include "../utilities.h"

class Wizard : public Player{
public:
    /*
     * C'tor of the game:
     *
     * @param name - The name of the player.
     * @result
     *      An instance of Rogue
    */
    Wizard(const char* name);
    ~Wizard() override=default;
    Wizard(const Wizard&) = default;
    Wizard& operator=(const Wizard&) = default;
    /*
     * Heals the player, up to max hp
     *
     * @param hp - health points to add to the player
     * @return
     *          void
    */
    void heal(int hp) override;

protected:
    /*
     * Virtual print function
     */
    void print(std::ostream& os) const override;
private:
    static const std::string WIZARD_NAME;
};


#endif //MTMCHKIN_H_WIZARD_H
