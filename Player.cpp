//
// Created by Noy Zini on 02/05/2022.
//

#include "Player.h"
#include <string>
#include "utilities.h"

using namespace std;

Player::Player(string& name, int maxHP, int force) :
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

