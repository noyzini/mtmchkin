#include <iostream>
#include <string>
#include "../Mtmchkin.h"
#include <queue>
//#include "Cards/Pitfall.h"
#include <memory>
#include "../Exception.h"
#include <map>

int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try
    {
        Mtmchkin game("deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS)
        {
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
}
