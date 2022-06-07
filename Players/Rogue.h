//
// Created by Noy Zini on 07/06/2022.
//

#ifndef MTMCHKIN_H_ROGUE_H
#define MTMCHKIN_H_ROGUE_H

#include "Player.h"

class Rogue : public Player{
public:
Rogue(const char* name );
void addCoins(int coins) override;
private:

    static int const DOUBLE=2;
};


#endif //MTMCHKIN_H_ROGUE_H
