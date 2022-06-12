#include <map>
#include "Mtmchkin.h"

typedef void (*builtFunction)(void);
typedef std::map<std::string, builtFunction> script_map;

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

template<class T>
T* create()
{
    return new T;
}

Card *Mtmchkin::makeCard(std::string cardName)
{



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


//Card* (*createMyClass)(void) = create<Card>;

