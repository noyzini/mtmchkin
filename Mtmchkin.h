#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <iostream>
#include <fstream> //check if this is the include they used in tutorial!
#include <queue>
#include "Players/Player.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "Cards/Card.h"
#include "Cards/BattleCards.h"
#include "Cards/Dragon.h"
#include "Cards/Goblin.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Fairy.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Pitfall.h"
#include "Cards/Gang.h"
#include "Leaderboard.h"
#include "Exception.h"
#include <memory>

class Mtmchkin{
private:
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Card>> m_cards;
    Leaderboard m_leaderboard;
    int m_round;
    int m_playersNumber;

    static const int MAX_LEVEL=10;
    static const int MIN_AMOUNT_OF_CARDS = 5;
    static const int MAX_NUMBER_PLAYERS=6;
    static const int MIN_NUMBER_PLAYERS=2;

    static bool isValidPlayerName(std::string& name);
    static bool isNumber(std::string& str);
    const std::string GANG_START="Gang";
    const std::string GANG_END="EndGang";

    static Card* makeCard(std::string cardName);
    static Player* makePlayer(std::string playerClass, std::string name);
    static int getNumOfPlayers();
    void getPlayers(int numOfPlayers);
    void getCards(std::ifstream& file);

public:


    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string& fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};



#endif /* MTMCHKIN_H_ */
