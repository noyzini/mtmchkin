#include "Player.h"
#include "../utilities.h"

Player::Player(const char* name, int maxHP, int force) :
m_name(name),
m_level(1),
m_force(force > 0 ? force : PLAYER_FORCE_DEFAULT),
m_maxHP(maxHP > 0 ? maxHP : MAX_HP_DEFAULT),
m_HP(m_maxHP),
m_coins(0)
{
}

void Player::printInfo() const
{
    //printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}

int Player::getLevel() const
{
    return m_level;
}

void Player::heal(int hp)
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

bool Player::isKnockedOut() const
{
    return m_HP==0;
}

bool Player::pay(int coins)
{
    if (coins <= 0)
    {
        return true;
    }

    if (m_coins >= coins)
    {
        m_coins -= coins;
        return true;
    }

    return false;
}

void Player::levelUp()
{
    if(m_level<MAX_LEVEL)
    {
        m_level++;
    }
}

void Player::buff(int boost)
{
    if(boost>=0)
    {
        m_force+=boost;
    }
}

void Player::damage(int damage)
{
    if(damage>=0)
    {
        m_HP-=damage;
    }
    if(m_HP<0)
    {
        m_HP=0;
    }
}

void Player::addCoins(int coins)
{
    if(coins>=0)
    {
        m_coins+=coins;
    }
}

int Player::getAttackStrength() const
{
    return (m_force + m_level);
}
