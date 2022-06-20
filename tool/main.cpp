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
    Mtmchkin game("../deck.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
        game.playRound();
    }
    game.printLeaderBoard();
}
/*
template<class T>
Card* createCard()
{
    return new T();
}

typedef Card* (*createCardFunction)(void);
typedef std::map<std::string, createCardFunction> StringToFunctionMap; //check convention about capital letter at the beginning

//wrap this in try catch if invalid card name was entered, or return null ptr, preferably the latter
Card *makeCard(std::string cardName)
{
    StringToFunctionMap map;
    map["Dragon"] = createCard<Dragon>;
    map["Goblin"] = createCard<Goblin>;
    map["Vampire"] = createCard<Vampire>;
    map["Barfight"] = createCard<Barfight>;
    map["Fairy"] = createCard<Fairy>;
    map["Merchant"] = createCard<Merchant>;
    map["Pitfall"] = createCard<Pitfall>;
    map["Treasure"] = createCard<Treasure>;

    if (map.find(cardName) == map.end())
        return nullptr;
    return map.find(cardName)->second();
}

int main() {
    //Fighter r("Avia");
//    int x;
//    std::unique_ptr<int> ptr(&x);
//    std::unique_ptr<int> ptr2 = std::move(ptr);


    std::string s = "../inputs/badFormat_test_start_of_file.txt";
    std::ifstream file(s);
    //file.open("deck.txt");
    std::string str;
    if (!file)
    {
        throw DeckFileNotFound();
    }

    int currentLine = 1;
    while (getline (file, str))
    {
        std::unique_ptr<Card> temp(makeCard(str));
        if (temp == nullptr)
        {
            try {
                throw DeckFileFormatError(currentLine);
            }
            catch (DeckFileFormatError& e)
            {
                std::cout << e.what();
            }
        }
        currentLine++;
    }


    Mtmchkin game("../deck.txt");
    int maxRounds = 50;
    while (!game.isGameOver() && game.getNumberOfRounds() < maxRounds)
    {
        game.playRound();
    }
    game.printLeaderBoard();

    std::string input;
    std::getline(std::cin, input);
    int spaceIndex = input.find(" ");
    std::string name = input.substr(0,spaceIndex), playerClass = input.substr(spaceIndex+1,input.length()-1);
    std::cout << "Name is:" << name << "Class is:" << playerClass << "Test is";

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

}
 */

