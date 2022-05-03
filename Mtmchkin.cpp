//
// Created by aviaa on 02/05/2022.
//

#include "Mtmchkin.h"

const bool WIN = true;
const bool LOSE = false;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :
        m_player(playerName), m_cards(new Card[numOfCards]), m_cardsCount(numOfCards),
        m_currentCard(0),m_status(GameStatus::MidGame)
{
    for (int i = 0; i < numOfCards ; i++)
    {
        m_cards[i] = cardsArray[i];
    }
}

Mtmchkin::Mtmchkin(const Mtmchkin &mtmchkin):
        m_player(mtmchkin.m_player),m_cards(new Card[mtmchkin.m_cardsCount]),m_cardsCount(mtmchkin.m_cardsCount),
        m_currentCard(mtmchkin.m_currentCard),m_status(mtmchkin.m_status)
{
    for (int i = 0; i < mtmchkin.m_cardsCount ; i++)
    {
        m_cards[i] = mtmchkin.m_cards[i];
    }
}

Mtmchkin::~Mtmchkin() {
    delete[] m_cards;
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& mtmchkin)
{
    if(this==&mtmchkin)
    {
        return *this;
    }
    m_player=mtmchkin.m_player;
    m_cardsCount=mtmchkin.m_cardsCount;
    m_status=mtmchkin.m_status;
    m_currentCard=mtmchkin.m_currentCard;

    delete[] m_cards;
    m_cards=new Card[mtmchkin.m_cardsCount];
    for (int i = 0; i < mtmchkin.m_cardsCount ; i++)
    {
        m_cards[i] = mtmchkin.m_cards[i];
    }
    return *this;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}

void Mtmchkin::playNextCard()
{
    Card currentCard = m_cards[m_currentCard];
    currentCard.printInfo();

    m_currentCard++;
    if (m_currentCard == m_cardsCount)
        m_currentCard = 0;

    int level = m_player.getLevel();
    int hp = m_player.getHP();

    currentCard.applyEncounter(m_player);

    if (level < m_player.getLevel())
    {
        printBattleResult(WIN);
    }
    else if (hp > m_player.getHP()) //can we use this function??
    {
        printBattleResult(LOSE);
    }

    m_player.printInfo();
}

bool Mtmchkin::isOver()
{
    if (m_status == GameStatus::MidGame)
    {
        return false;
    }
    return true;
}
