//
// Created by Noy Zini on 02/05/2022.
//

#include "Player.h"
#include <string>

using namespace std;

Player::Player(string name, int maxHP, int force) :
m_name(name),
m_level(1),
m_force(force),
m_maxHP(maxHP),
m_coins(0)
{
}

