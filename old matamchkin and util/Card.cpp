#include "Card.h"
#include <iostream>
#include "utilities.h"

const bool WIN = true;
const bool LOSE = false;

Card::Card(CardType type, const CardStats& stats) :
m_effect(type),
m_stats(stats)
{
}

void Card::applyEncounter(Player& player) const
{
    switch (m_effect)
    {
        case CardType::Battle:
            if (player.getAttackStrength() >= m_stats.force)
            {
                player.levelUp();
                player.addCoins(m_stats.loot);
                printBattleResult(WIN);
            }
            else
            {
                player.damage(m_stats.hpLossOnDefeat);
                printBattleResult(LOSE);
            }
            break;
        case CardType::Treasure:
            player.addCoins(m_stats.loot);
            break;
        case CardType::Heal:
        case CardType::Buff:
            if (player.pay(m_stats.cost))
            {
                if (m_effect == CardType::Heal)
                {
                    player.heal(m_stats.heal);
                }
                else if (m_effect == CardType::Buff)
                {
                    player.buff(m_stats.buff);
                }
            }
            break;
        default:
            break;
    }
}

void Card::printInfo() const
{
    switch (m_effect)
    {
        case CardType::Battle:
            printBattleCardInfo(m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
            break;
        default:
            break;
    }
}