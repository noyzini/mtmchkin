#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <iostream>
#include <fstream>
#include <queue>
#include "Players/Player.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "Cards/Card.h"
#include "Cards/BattleCard.h"
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

private:
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Card>> m_cards;
    Leaderboard m_leaderboard;
    int m_round;
    int m_playersNumber;

    static const int MIN_AMOUNT_OF_CARDS = 5;
    static const int MAX_NUMBER_PLAYERS = 6;
    static const int MIN_NUMBER_PLAYERS = 2;

    static const std::string GANG_START;
    static const std::string GANG_END;
    static const std::string SPACE;

    //static bool isNumber(std::string& str);

    /*
     * Helper functions for Mtmchkin C'tor
     */
    static bool isValidPlayerName(std::string& name);
    static std::unique_ptr<Card> makeCard(std::string& cardName);
    static std::unique_ptr<Player> makePlayer(std::string& playerClass, std::string& name);
    static int getNumOfPlayers();
    void getPlayers(int numOfPlayers);
    void getCards(std::ifstream& file);

};



#endif /* MTMCHKIN_H_ */
