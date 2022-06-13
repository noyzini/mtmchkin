
#include "Goblin.h"


Goblin::Goblin() : BattleCards(FORCE,DAMAGE,LOOT)
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
    printMonsterDetails(os,m_force,m_damageOnLoss,m_coinsOnWin,false);
}