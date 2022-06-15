#include <iostream>
#include <string>
#include "Mtmchkin.h"
#include <queue>
//#include "Cards/Pitfall.h"
#include <memory>
#include "Exception.h"


int main() {
    //Fighter r("Avia");
//    int x;
//    std::unique_ptr<int> ptr(&x);
//    std::unique_ptr<int> ptr2 = std::move(ptr);
    Mtmchkin game("../deck.txt");
    int maxRounds = 50;
    while (!game.isGameOver() && game.getNumberOfRounds() < maxRounds)
    {
        game.playRound();
    }
    game.printLeaderBoard();
    /*
    std::string input;
    std::getline(std::cin, input);
    int spaceIndex = input.find(" ");
    std::string name = input.substr(0,spaceIndex), playerClass = input.substr(spaceIndex+1,input.length()-1);
    std::cout << "Name is:" << name << "Class is:" << playerClass << "Test is";
    */
    /*
    r.levelUp();
    r.levelUp();
    r.addCoins(1000);
    std::cout << r;
    std::queue<int> q;
    Pitfall pit;
    std::cout << pit;
    pit.playCard(r);

    std::cout << r;
    std::cout << r;
     */
}


