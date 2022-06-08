//
// Created by Noy Zini on 07/06/2022.
//

#ifndef MTMCHKIN_H_WIZARD_H
#define MTMCHKIN_H_WIZARD_H

#include "Player.h"

class Wizard : public Player{
public:
    Wizard(const char* name);
    void heal (int hp) override;
private:
    static int const DOUBLE=2;
};


#endif //MTMCHKIN_H_WIZARD_H
