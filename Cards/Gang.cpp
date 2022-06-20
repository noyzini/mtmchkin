
#include "Gang.h"

Gang::Gang() : Card() {

}

void Gang::addMonster(std::unique_ptr<BattleCards> &card) {
    m_gang.push_back(std::move(card));
}

void Gang::playCard(Player &player) const {

    //for (const std::unique_ptr<BattleCards>& monster : m_gang)
    //shuld we print for every win or at the end
    int index=0;
    bool playOn= true;
    for(;index<m_gang.size() && playOn; index++)
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
    } else
    {
        for(;index<m_gang.size();index++)
        {
            player.damage(m_gang[index]->m_damageOnLoss);
        }
    }
}

void Gang::print(std::ostream &os) const {

}