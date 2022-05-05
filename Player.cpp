//
// Created by Noy Zini on 02/05/2022.
//

#include "Player.h"
#include <string>
#include "utilities.h"

using namespace std;


Player::Player(const string& name, int maxHP, int force) : // if value <0 need to inshore defult value
m_name(name),
m_level(1),
m_force(force),
m_maxHP(maxHP),
m_HP(maxHP),
m_coins(0)
{
    if(force<0)
    {
        m_force=5;
    }
    if(maxHP<0)
    {
        m_maxHP=100;
        m_HP=100;
    }
}

void Player::printInfo() {
    printPlayerInfo(this->m_name.c_str(), this->m_level, this->m_force, this->m_HP, this->m_coins);
}

int Player::getLevel() {
    return this->m_level;
}

void Player::heal(int hp)  ///can we assume hp > 0 ??
{
    if(hp>0)
    {
        m_HP += hp;
    }
    if (m_HP > m_maxHP)
    {
        m_HP = m_maxHP;
    }
}

bool Player::isKnockedOut()
{
    return m_HP==0;
}

bool Player::pay(int coins)
{
    if (m_coins >= coins)
    {
        m_coins -= coins;
        return true;
    }
    return false;
}

void Player::levelUp(){
    if(m_level<MAX_LEVEL)
    {
        m_level++;
    }
}

void Player::buff(int boost) {//added check for >0
    if(boost>0)
    {
        this->m_force+=boost;
    }
}

void Player::damage(int damage) {//added check for >0
    if(damage>0)
    {
        this->m_HP-=damage;
    }
    if(this->m_HP<0)
    {
        this->m_HP=0;
    }
}

void Player::addCoins(int coins) {//added check for >0
    if(coins>0)
    {
        this->m_coins+=coins;
    }
}

int Player::getAttackStrength() {
    return (this->m_force+ this->m_level);
}
