#include <iostream>
#include <string>
#include "Mtmchkin.h"
#include <queue>
#include "Cards/Pitfall.h"

int main() {
    Fighter r("Avia");
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
}


