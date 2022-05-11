#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :
        m_player(playerName),
        m_cards(new Card[numOfCards]),
        m_cardsCount(numOfCards),
        m_currentCard(0),
        m_status(GameStatus::MidGame)
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

Mtmchkin::~Mtmchkin()
{
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

    Card* tempCards = new Card[mtmchkin.m_cardsCount];
    for (int i = 0; i < mtmchkin.m_cardsCount ; i++)
    {
        tempCards[i] = mtmchkin.m_cards[i];
    }

    delete[] m_cards;
    m_cards = tempCards;
    return *this;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}

void Mtmchkin::playNextCard()
{
    if (getGameStatus() == GameStatus::MidGame)
    {
        Card currentCard = m_cards[m_currentCard];
        currentCard.printInfo();

        m_currentCard++;
        if (m_currentCard == m_cardsCount) {
            m_currentCard = 0;
        }

        currentCard.applyEncounter(m_player);

        if (m_player.getLevel() == Player::MAX_LEVEL) {
            m_status = GameStatus::Win;
        }
        if (m_player.isKnockedOut()) {
            m_status = GameStatus::Loss;
        }

        m_player.printInfo();
    }
}

bool Mtmchkin::isOver() const
{
    if (m_status == GameStatus::MidGame)
    {
        return false;
    }
    return true;
}
