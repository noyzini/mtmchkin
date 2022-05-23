#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Mtmchkin.h"
#include <string>
#include "HealthPoints.h"
#include "Queue.h"


bool isEven(int n)
{
    return (n % 2 == 0);
}

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

    Queue<int> queue;
    queue.pushBack(1);
    queue.pushBack(2);
    queue.pushBack(3);
    queue.pushBack(4);
    queue = filter(queue, isEven);

    return 0;
}


