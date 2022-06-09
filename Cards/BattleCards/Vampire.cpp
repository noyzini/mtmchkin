
#include "Vampire.h"


Vampire::Vampire() : BattleCards(FORCE,DAMAGE,LOOT)
{
}

void Vampire::playCard(Player& player)
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