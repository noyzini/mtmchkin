#include <map>
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string fileName):m_round(0)
{
    std::string card;
    std::ifstream file(fileName);

    while (getline (file, card)) {
        m_cards.push(makeCard(card));
    }

// Close the file
    file.close();
}

//remove this after reception hour
class Factory {
public:
    static Card* createDragon() { //why cant we do Dragon* ?? Can we do it without Code duplicating so much?
        return new Dragon();
    }
};

template<class T>
Card* create()
{
    return new T();
}

typedef Card* (*createFunctions)(void);
typedef std::map<std::string, createFunctions> StringToFunctionMap; //check convention about capital letter at the beginning

//wrap this in try catch if invalid card name was entered, or return null ptr, preferably the latter
Card *Mtmchkin::makeCard(std::string& cardName)
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
    int index=0;
    while (index<m_playersNumber)
    {
        Player* current_player=m_players.front();
        m_players.pop();
        printTurnStartMessage(current_player->getName());
        Card* current_card = m_cards.front();
        m_cards.pop();
        current_card->playCard(*current_player);
        m_cards.push(current_card);
        if(current_player->getLevel()>=MAX_LEVEL || current_player->isKnockedOut() )
        {
            //add to leaderbord
            m_playersNumber--;
        }
        else
        {
            m_players.push(current_player);
        }
        index++;
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




