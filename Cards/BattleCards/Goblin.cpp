
#include "Goblin.h"


Goblin::Goblin() : BattleCards(FORCE,DAMAGE,LOOT)
{
}

void Goblin::playCard(Player& player)
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