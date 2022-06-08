#ifndef MTMCHKIN_H_FIGHTER_H
#define MTMCHKIN_H_FIGHTER_H

#include "Player.h"
#include "../utilities.h"

class Fighter : public Player
{

public:
Fighter(const char* name);
    int getAttackStrength() const override;
    ~Fighter()=default;

protected:
    void print(std::ostream& os) const;
    const std::string FIGHTER_NAME = "Fighter";

private:
    static const int DOUBLE=2;
};


#endif //MTMCHKIN_H_FIGHTER_H
