
#include "Leaderboard.h"

Leaderboard::Leaderboard() : m_winners(), m_losers()
{
}

void Leaderboard::addPlayer(std::unique_ptr<Player>& player) {
    if(player->isKnockedOut())
    {
        m_losers.push_back(std::move(player));
    } else
    {
        m_winners.push_back(std::move(player));
    }
}

void Leaderboard::printBoard(const std::deque<std::unique_ptr<Player>>& players) const {
    printLeaderBoardStartMessage();
    int place=1;
    for (int i = 0 ; i < m_winners.size(); i ++)
    {
        printPlayerLeaderBoard(place, *m_winners[i]);
        place++;
    }
    for (int i =0 ; i < players.size(); i++)
    {
        printPlayerLeaderBoard(place,*players[i]);
        place++;
    }

    for (int i = m_losers.size() - 1 ; i >= 0; i--) //consider doing push front for a normal loop
    {
        printPlayerLeaderBoard(place,*m_losers[i]);
        place++;
    }
}
//