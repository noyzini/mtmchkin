#include "Player.h"
#include "../utilities.h"

Player::Player(const char* name) :
m_name(name),
m_level(1),
m_force(PLAYER_FORCE_DEFAULT),
m_hp(MAX_HP_DEFAULT),
m_coins(DEFAULT_COINS)
{
}


int Player::getLevel() const
{
    return m_level;
}


void Player::heal(int hp)
{
    if(hp>0)
    {
        m_hp+=hp;
    }
}

bool Player::isKnockedOut() const
{
    return m_hp==0;
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
        m_hp-=damage;
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

string Player::getName() const
{
    return m_name;
}

std::ostream& operator<<(std::ostream& os,const Player& player)
{
    player.print(os);
    return os;
}

