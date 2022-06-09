//
// Created by aviaa on 6/8/2022.
//

#include "Card.h"

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.print(os);
    return os;
}

