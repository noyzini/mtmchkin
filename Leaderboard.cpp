
#include "Leaderboard.h"

Leaderboard::Leaderboard():m_losers(std::vector<std::unique_ptr<Player>>())
    ,m_winners(std::vector<std::unique_ptr<Player>>())
{
}

void Leaderboard::addPlayer(std::unique_ptr<Player> player) {
    if(player->isKnockedOut())
    {
        m_losers.push_back(std::move(player));
    } else
    {
        m_winners.push_back(std::move(player));
    }
}

void Leaderboard::printBoard(const std::deque<std::unique_ptr<Player>> players) const {
    printLeaderBoardStartMessage();
    int place=1;
    int index=0;
    while ( index < m_winners.size() ) {
        index++;
        printPlayerLeaderBoard(place,*m_winners[index]);
        place++;
    }
    for (int i =0 ; i < players.size(); i++)
    {
        printPlayerLeaderBoard(place,*players[i]);
        place++;
    }
    index = m_losers.size()-1;
    while (index>=0)
    {
        printPlayerLeaderBoard(place,*m_losers[index]);
        place++;
        index--;
    }
}