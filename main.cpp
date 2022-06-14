#include <iostream>
#include <string>
#include "Mtmchkin.h"
#include <queue>
//#include "Cards/Pitfall.h"
#include <memory>

int main() {


    std::queue<std::unique_ptr<int>> qu;
    std::unique_ptr<int>p1(new int(1));
    std::unique_ptr<int>p2(new int(2));
    qu.push(std::move(p1));
    qu.push(std::move(p2));
    std::cout<<*qu.front();
    std::unique_ptr<int> p3= std::move(qu.front());
    qu.pop();
    std::cout<<*qu.front();
   //
   // std::cout<<qu.front().get();

    //qu.push(b);

    /*
    r.levelUp();
    r.levelUp();
    r.addCoins(1000);
    std::cout << r;
    std::queue<int> q;
    Pitfall pit;
    std::cout << pit;
    pit.playCard(r);

    std::cout << r;
    std::cout << r;
     */
}


