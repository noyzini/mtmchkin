
#ifndef MTMCHKIN_H_ROGUE_H
#define MTMCHKIN_H_ROGUE_H

#include "Player.h"
#include "../utilities.h"
#include <iostream>
#include "../utilities.h"

class Rogue : public Player {
public:
    /*
     * Should we do default for operator= and Copy c'tor
     */
    Rogue(const char* name );
    ~Rogue() = default;

    void addCoins(int coins) override;

protected:
    void print(std::ostream& os) const override;

private:
    static const int DOUBLE=2;
    const std::string ROGUE_NAME = "Rogue"; //cant make it static
};

#endif //MTMCHKIN_H_ROGUE_H
