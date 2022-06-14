
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

void Leaderboard::printBoard(std::queue<std::unique_ptr<Player>> players) {
    printLeaderBoardStartMessage();
    int place=1;
    int index=0;
    while ( index < m_winners.size() ) {
        index++;
        printPlayerLeaderBoard(place,*m_winners[index]);
        place++;
    }
    index=0;
    while (index<players.size())
    {
        std::unique_ptr<Player> current_player=std::move(players.front());
        players.pop();
        printPlayerLeaderBoard(place,*current_player);
        players.push(std::move(current_player));
        place++;
    }
    for (std::vector<std::unique_ptr<Player>>::reverse_iterator i = m_losers.rbegin();i != m_losers.rend(); ++i )
    {
        printPlayerLeaderBoard(place,**i);
        place++;
    }
}