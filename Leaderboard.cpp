
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
    for (const std::unique_ptr<Player> & winner : m_winners)
    {
        printPlayerLeaderBoard(place, *winner);
        place++;
    }
    for (const std::unique_ptr<Player>& player : players)
    {
        printPlayerLeaderBoard(place,*player);
        place++;
    }

    for (std::vector<std::unique_ptr<Player>>::const_reverse_iterator i = m_losers.rbegin(); i != m_losers.rend(); i++)
    {
        printPlayerLeaderBoard(place,**i);
        place++;
    }
}