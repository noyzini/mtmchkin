
#include "Vampire.h"


Vampire::Vampire() : BattleCards(FORCE,DAMAGE,LOOT)
{
}

void Vampire::playCard(Player& player) const
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
        player.loseForce();
        printLossBattle(player.getName(),m_monsterName);
    }
}

void Vampire::print(std::ostream& os) const
{
    printCardDetails(os,m_monsterName);
    printMonsterDetails(os,m_force,m_damageOnLoss,m_coinsOnWin,false);
    printEndOfCardDetails(os);
}