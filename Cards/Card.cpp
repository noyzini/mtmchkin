//
// Created by aviaa on 6/8/2022.
//

#include "Card.h"

Card::Card(CardFactory* factory) : m_factory(factory)
{
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.print(os);
    return os;
}

