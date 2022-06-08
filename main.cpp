#include <iostream>
#include "Mtmchkin.h"
#include <string>
#include "HealthPoints.h"
#include "Queue.h"


bool isEven(int n)
{
    return (n % 2 == 0);
}

class DivideBy
{
public:
    int divideBy;
    DivideBy(int divideBy);
    bool operator()(int x) const;
};

DivideBy::DivideBy(int divideBy) : divideBy(divideBy) {}
bool DivideBy::operator()(int x) const
{
    return x % divideBy == 0;
}

int main() {

}


