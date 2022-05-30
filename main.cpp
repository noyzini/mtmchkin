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

template<class T>
class DivideBy
{
public:
    int divideBy;
    DivideBy(int divideBy);
    bool operator()(int x);
};

template<class T>
DivideBy<T>::DivideBy(int divideBy) : divideBy(divideBy) {}
template<class T>
bool DivideBy<T>::operator()(int x)
{
    return x % divideBy == 0;
}

int main() {


    DivideBy<int> divideByFour(4);

    Queue<int> queue;
    int x = 5;
    queue.pushBack(x);
    queue.pushBack(4);
    filter(queue, isEven);
    queue = filter(queue,divideByFour);
    std::cout << queue.front();
    return 0;
    x++;
    queue.pushBack(x);
    const Queue<int> queue2 = queue;
    queue.operator=(queue2);
    //queue = queue2;
    queue2.begin();
    Queue<int>::ConstIterator it = queue2.begin();
    //queue2.begin();


    const int y = 5;
    const int* z = &y;
    int *const a = &x;
    z++;

    *a == y == *z;
    *a = 4;
    //a++;
    //for (typename Queue<int>::Iterator it = queue.begin();
    //it != queue.end(); ++it )
    //{
    //}
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

    return 0;
}


