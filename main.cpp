#include <iostream>
#include <string>
#include "Mtmchkin.h"

int main() {
    Rogue r("Avia");
    r.levelUp();
    r.levelUp();
    r.addCoins(1000);
    std::cout << r;
}


