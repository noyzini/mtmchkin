//
// Created by Noy Zini on 07/06/2022.
//

#ifndef MTMCHKIN_H_WIZARD_H
#define MTMCHKIN_H_WIZARD_H

#include "Player.h"
#include "../utilities.h"

class Wizard : public Player{
public:
    Wizard(const char* name);
    void heal (int hp) override;
    ~Wizard()=default;
protected:
    void print(std::ostream& os) const;
private:
    static int const DOUBLE=2;
    const std::string WIZARD_NAME = "Wizard";
};


#endif //MTMCHKIN_H_WIZARD_H
