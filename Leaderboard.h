

#ifndef MTMCHKIN_CPP_LEADERBOARD_H
#define MTMCHKIN_CPP_LEADERBOARD_H
#include "Players/Player.h"
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
    /*
    * C'tor of the leaderbord:
    *
    * @param name - The name of the player.
    * @result
    *      An instance of Leaderboard
    */
    Leaderboard();
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Leaderboard()=default;
    Leaderboard(const Leaderboard&) = default;
    Leaderboard& operator=(const Leaderboard&) = default;
    /*
     * adding a given player to the leaderboard win or lose
     */
    void addPlayer(std::unique_ptr<Player>& player);
    /*
     * print of the leaderboard
     */
    void printBoard(const std::deque<std::unique_ptr<Player>>& players) const;
};


#endif //MTMCHKIN_CPP_LEADERBOARD_H
