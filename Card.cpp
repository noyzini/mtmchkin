//
// Created by aviaa on 02/05/2022.
//

#include "Card.h"
#include <iostream>

Card::Card(CardType type, const CardStats& stats)
{
    this->m_effect = type;
    this->m_stats = stats;
}
