
#include "Goblin.h"

const std::string Goblin::m_monsterName = "Goblin";

Goblin::Goblin() : BattleCards(FORCE,DAMAGE,LOOT,m_monsterName)
{
}

void Goblin::playCard(Player& player) const
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

void Goblin::print(std::ostream& os) const
{
    printCardDetails(os,m_monsterName);
    printMonsterDetails(os,m_force,m_damageOnLoss,m_coinsOnWin,false);
    printEndOfCardDetails(os);
}