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
    queue.pushBack(15);
    Queue<int> q2;
   /*
    for (typename Queue<int>::Iterator it = queue.begin();
    it != queue.end(); ++it )
    {
    }
    queue = filter(queue, isEven);
*/

    int x = 4;
    ++++x;
    std::cout<<x;
    return 0;
}


