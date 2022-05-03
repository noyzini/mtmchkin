//
// Created by Noy Zini on 02/05/2022.
//

#ifndef MTMCHKIN_PLAYER_H
#define MTMCHKIN_PLAYER_H
#include <string>

using namespace std;

//add fancy /* */ above functions

class Player{

    string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

public:
    Player(const string& name, int maxHP = 100, int force = 5);
    Player(const Player&)=default;//ask on piaza if its ok
    Player& operator=(const Player&)=default;
    ~Player()=default;

    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int boost);
    void heal(int hp);
    void damage(int damage);
    bool isKnockedOut();
    void addCoins(int coins);
    bool pay(int coins);
    int getAttackStrength();

    int getHP(); ///Can we do this??????

};


#endif //MTMCHKIN_PLAYER_H
