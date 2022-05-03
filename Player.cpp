//
// Created by Noy Zini on 02/05/2022.
//

#include "Player.h"
#include <string>
#include "utilities.h"

using namespace std;

const int MAX_LEVEL = 10;// check if needs to move to the h file ???

Player::Player(const string& name, int maxHP, int force) :
m_name(name),
m_level(1),
m_force(force),
m_maxHP(maxHP),
m_HP(maxHP),
m_coins(0)
{}

void Player::printInfo() {
    printPlayerInfo(this->m_name.c_str(), this->m_level, this->m_force, this->m_HP, this->m_coins);
}

int Player::getLevel() {
    return this->m_level;
}

void Player::heal(int hp)  ///can we assume hp > 0 ??
{
    m_HP += hp;
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

void Player::buff(int boost) {
    this->m_force+=boost;
}

void Player::damage(int damage) {
    this->m_HP-=damage;
    if(this->m_HP<0)
    {
        this->m_HP=0;
    }
}

void Player::addCoins(int coins) {
    this->m_coins+=coins;
}

int Player::getAttackStrength() {
    return (this->m_force+ this->m_level);
}
