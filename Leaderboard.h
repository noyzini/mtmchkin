

#ifndef MTMCHKIN_CPP_LEADERBOARD_H
#define MTMCHKIN_CPP_LEADERBOARD_H
#include "/Players/player.h"
#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include "utilities.h"

class Leaderboard {
private:
    std::vector<std::unique_ptr<Player>> m_winners;
    std::vector<std::unique_ptr<Player>> m_losers;

public:
    Leaderboard();
    ~Leaderboard()=default;
    void addPlayer(std::unique_ptr<Player> player);
    void printBoard(std::queue<std::unique_ptr<Player>> players);
};


#endif //MTMCHKIN_CPP_LEADERBOARD_H
