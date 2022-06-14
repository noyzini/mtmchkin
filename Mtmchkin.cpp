#include <map>
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string fileName):m_round(0)
{
    std::string card;
    std::ifstream file(fileName);
    while (getline (file, card)) {
        std::unique_ptr<Card> temp(makeCard(card));
        m_cards.push(std::move(temp));
    }

// Close the file
    file.close();
}


template<class T>
Card* create()
{
    return new T();
}

typedef Card* (*createFunctions)(void);
typedef std::map<std::string, createFunctions> StringToFunctionMap; //check convention about capital letter at the beginning

//wrap this in try catch if invalid card name was entered, or return null ptr, preferably the latter
Card *Mtmchkin::makeCard(std::string cardName)
{
    StringToFunctionMap map;
    map["Dragon"] = create<Dragon>;
    map["Goblin"] = create<Goblin>;
    map["Vampire"] = create<Vampire>;
    map["Barfight"] = create<Barfight>;
    map["Fairy"] = create<Fairy>;
    map["Merchant"] = create<Merchant>;
    map["Pitfall"] = create<Pitfall>;
    map["Treasure"] = create<Treasure>;

    if (map.find(cardName) == map.end())
        return nullptr;
    return map.find(cardName)->second();
}

void Mtmchkin::playRound() {
    m_round++;
    printRoundStartMessage(m_round);
    int roundIndex=m_playersNumber;
    while (roundIndex>0)
    {
        roundIndex--;
        std::unique_ptr<Player> current_player=std::move(m_players.front());
        m_players.pop();

        printTurnStartMessage(current_player->getName());

        std::unique_ptr<Card> current_card=std::move(m_cards.front());
        m_cards.pop();

        current_card->playCard(*current_player);
        m_cards.push(std::move(current_card));

        if(current_player->getLevel()>=MAX_LEVEL || current_player->isKnockedOut() )
        {
            m_leaderboard.addPlayer(std::move(current_player));
            m_playersNumber--;
        }
        else
        {
            m_players.push(std::move(current_player));
        }
        if(isGameOver())
        {
            printGameEndMessage();
        }
    }
}

bool Mtmchkin::isGameOver() const {
    if (m_players.empty())
    {
        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_round;
}

void Mtmchkin::printLeaderBoard() const {
    m_leaderboard.printBoard(m_players);
}


