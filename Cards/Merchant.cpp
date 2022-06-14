
#include "Merchant.h"

Merchant::Merchant() :Card(){

}

void Merchant::playCard(Player &player) const {
    int cost=0;
    int type=-1;
    std::string input;
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    while (type<DONT_BUY || type>BUY_FORCE)
    {
        std::getline (std::cin,input);
        try {
            type=std::stoi(input);
        }
        catch (std::exception& e)
        {
            printInvalidInput();
        }
    }
    switch (type) {
        case BUY_HP:
        {
            if(player.getCoins()<COST_HEAL_POINT)
            {
                printMerchantInsufficientCoins(std::cout);
            } else
            {
                player.pay(COST_HEAL_POINT);
                player.heal(1);
                cost=COST_HEAL_POINT;
            }
            break;
        }
        case BUY_FORCE:
        {
            if(player.getCoins()<COST_FORCE_POINT)
            {
                printMerchantInsufficientCoins(std::cout);
            } else
            {
                player.pay(COST_FORCE_POINT);
                player.buff(1);
                cost=COST_FORCE_POINT;
            }
            break;
        }
        default:
            break;
    }
    printMerchantSummary(std::cout,player.getName(),type,cost);
}

void Merchant::print(std::ostream &os) const
{
    printCardDetails(os,MERCHANT);
}