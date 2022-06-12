#include <map>
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string fileName)
{
    std::string card;
    std::ifstream file(fileName);

    while (getline (file, card)) {
        m_cards.push(makeCard(card));
    }

// Close the file
    file.close();
}

template<class T>
T* create()
{
    return new T;
}

Card *Mtmchkin::makeCard(std::string cardName)
{
    std::map<std::string,Card*> map;
    //Dragon* myClass = create<Dragon>();
    map["Dragon"] = create<Dragon>();

}



//Card* (*createMyClass)(void) = create<Card>;

