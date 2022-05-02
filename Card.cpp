//
// Created by aviaa on 02/05/2022.
//

#include "Card.h"
#include <iostream>
#include "utilities.h"

Card::Card(CardType type, const CardStats& stats)
{
    this->m_effect = type;
    this->m_stats = stats;
}

void Card::printInfo() const {
    switch (m_effect) {
        case CardType::Battle:
            printBattleCardInfo(this->m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(this->m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(this->m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(this->m_stats);
            break;
        default:
            break;
    }
}