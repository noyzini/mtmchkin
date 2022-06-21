#include "Dragon.h"

const std::string Dragon::m_monsterName = "Dragon";

Dragon::Dragon() : BattleCard(FORCE,INT32_MAX,LOOT,m_monsterName)
{
}

void Dragon::playCard(Player& player) const
{
    if (player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_coinsOnWin);
        printWinBattle(player.getName(),m_monsterName);
    }
    else
    {
        player.damage(m_damageOnLoss);
        printLossBattle(player.getName(),m_monsterName);
    }
}

void Dragon::print(std::ostream& os) const
{
    printCardDetails(os,m_monsterName);
    printMonsterDetails(os,m_force,m_damageOnLoss,m_coinsOnWin, true);
    printEndOfCardDetails(os);
}