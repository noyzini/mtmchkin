
#ifndef MTMCHKIN_H_ROGUE_H
#define MTMCHKIN_H_ROGUE_H

#include "Player.h"
#include "../utilities.h"
#include <iostream>
#include "../utilities.h"

class Rogue : public Player {
public:
    /*
     * C'tor of the player:
     *
     * @param name - The name of the player.
     * @result
     *      An instance of Rogue
    */
    explicit Rogue(const std::string& name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Rogue() override= default;
    Rogue(const Rogue&) = default;
    Rogue& operator=(const Rogue&) = default;

    /*
     * Add coins to the player
     *
     * @param coins - coins to add to the player
     * @return
     *          void
    */
    void addCoins(int coins) override;

protected:
    /*
     * Virtual print function
     */
    void print(std::ostream& os) const override;

private:
    static const std::string ROGUE_NAME;
};

#endif //MTMCHKIN_H_ROGUE_H
