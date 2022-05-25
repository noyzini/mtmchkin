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
    //Node<int> n(4);

    Queue<int> queue;
    queue.pushBack(1);
    queue.pushBack(2);
    queue.pushBack(3);
    queue.popFront();
    queue.popFront();
    Queue<int> q2=queue;
    /*
    for (typename Queue<int>::Iterator it = queue.begin();it != queue.end(); ++it )
    {
    }
    queue = filter(queue, isEven);
*/
    //iterator
    //for (int num : queue)
    {

    }
    //++queue;
    int x = 4;
    ++++x;
    std::cout<<x;
    return 0;
}


