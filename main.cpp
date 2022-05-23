#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Mtmchkin.h"
#include <string>
#include "HealthPoints.h"
#include <stdio.h>

int main() {
    HealthPoints hp(100);
    hp += 5;
    hp = hp + 2;
    hp = 2 + hp;
    hp = hp -2;
    hp -= 3;
    3 == hp;
    hp == 1;
    std::cout << hp;
    return 0;
}
