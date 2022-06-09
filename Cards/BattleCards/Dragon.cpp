//
// Created by aviaa on 6/8/2022.
//

#include "Dragon.h"

//add defines
Dragon::Dragon() : BattleCards(FORCE,INT32_MAX,LOOT)
{
}

void Dragon::playCard(Player& player)
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