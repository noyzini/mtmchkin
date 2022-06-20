
#include "Gang.h"

Gang::Gang() : Card() {

}

void Gang::addMonster(std::unique_ptr<BattleCards> &card) {
    m_gang.push_back(std::move(card));
}

void Gang::playCard(Player &player) const {
    int index=0;
    bool playOn= true;
    int gangSize=m_gang.size();
    for(; index < gangSize && playOn; index++)
    {
        if (player.getAttackStrength() >= m_gang[index]->m_force)
        {
            player.addCoins(m_gang[index]->m_coinsOnWin);
        }
        else
        {
            playOn= false;
        }
    }
    if(playOn)
    {
        player.levelUp();
        printWinBattle(player.getName(),GANG_NAME);
    } else
    {
        index--;
        for(; index < gangSize; index++)
        {
            player.damage(m_gang[index]->m_damageOnLoss);
            printLossBattle(player.getName(),m_gang[index]->m_name);
        }
    }
}

void Gang::print(std::ostream &os) const {
    os<<"This is a Gang card\n";
    int gangSize=m_gang.size();
    for(int i=0;i<gangSize;i++)
    {
        m_gang[i]->print(os);
    }
    os<<"End of Gang card\n";
}