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

class ControlledAllocer{
        public:
        static int allowedAllocs;

        ControlledAllocer()
        {
            if (!allowedAllocs){
                throw std::bad_alloc();
            }
            --allowedAllocs;
        }

        ControlledAllocer(const ControlledAllocer &other)
        {
            if (!allowedAllocs){
                throw std::bad_alloc();
            }
            --allowedAllocs;
        }

        ControlledAllocer &operator=(const ControlledAllocer &other)
        {
            if (!allowedAllocs){
                throw std::bad_alloc();
            }
            --allowedAllocs;
            return *this;
        }
};
int ControlledAllocer::allowedAllocs;
int main() {
    ControlledAllocer::allowedAllocs = 1000;

    Queue<ControlledAllocer> q1, q2;
    ControlledAllocer c;
    for (int i = 0; i < 10; i++)
    {
        q1.pushBack(c);
    }

    ControlledAllocer::allowedAllocs = 0;

    //q1.pushBack(c);

    //REQUIRE_THROWS_AS(q2.pushBack(c), std::bad_alloc);

    ControlledAllocer::allowedAllocs = 5;

    //q2 = q1;

    auto newCopyBadAllocerQ = [](Queue<ControlledAllocer> q)
    {
        Queue<ControlledAllocer> newQ(q);
    };
    ControlledAllocer::allowedAllocs = 5;
    //newCopyBadAllocerQ(q1);

    auto newConstCopyBadAllocerQ = [](Queue<ControlledAllocer> q)
    {
        const Queue<ControlledAllocer> newQ(q);
    };
    ControlledAllocer::allowedAllocs = 5;
    //newConstCopyBadAllocerQ(q1);

    //newConstCopyBadAllocerQ(q1);
    /*
    HealthPoints a = HealthPoints(100);
    HealthPoints b;
    b = a + 100;
    b = a - 100;
    b = 100 + a;
    b = -100 + a;
    if(!(a > b))
        std::cout <<(a > b) <<" false";
    a -= 100;
    std::cout<<(a == b);

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
    int x = 4;
    queue.pushBack(x);
    x++;
    queue.pushBack(x);
    const Queue<int> queue2 = queue;
    queue.operator=(queue2);
    //queue = queue2;
    //queue2.begin();


    const int y = 5;
    const int* z = &y;
    int *const a = &x;
    z++;
    *a = 4;
    //a++;
    for (typename Queue<int>::Iterator it = queue.begin();it != queue.end(); ++it )
    {

    }
    //queue = filter(queue, isEven);
    //Queue<int>::Iterator i = queue
    //iterator
    //for (int num : queue)
    {

    }
    //++queue;
    //int x = 4;
    ++++x;
    std::cout<<x;
    //delete queue;

*/

    return 0;
}


