#include <iostream>
#include "Player.h"

int main() {
    std::cout << "Hello, World!!" << std::endl;
    Player p("Avia");
    Player p2 = p;
    p = p2;
    return 0;
}
