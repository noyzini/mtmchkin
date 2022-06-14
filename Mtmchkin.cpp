#include <map>
#include "Mtmchkin.h"

//add this to .h file later
bool isNumber(std::string str) {
    for (char i : str)
        if (!isdigit(i))
            return false;
    return true;
}

bool isValidPlayerName(std::string name)
{
    int charCount = 0;
    for (char c : name)
    {
        if (std::isdigit(c))
            return false;
        charCount++;
    }
    return charCount <= 15;
}

Mtmchkin::Mtmchkin(const std::string fileName):m_round(0)
{
    printStartGameMessage();

    std::string card;
    std::ifstream file(fileName);

    while (getline (file, card)) {
        std::unique_ptr<Card> temp(makeCard(card));
        m_cards.push_back(std::move(temp));
    }

    //put this in a function later
    int numOfPlayers = 0;
    do {
        printEnterTeamSizeMessage();
        std::string input;
        std::getline(std::cin, input);
        if (!isNumber(input) || stoi(input) < 2 || stoi(input) > 6)
        {
            printInvalidTeamSize();
        }
        else
        {
            numOfPlayers = stoi(input);
        }
    }
    while (!numOfPlayers);

    int playersEntered = 0;

    while (playersEntered < numOfPlayers)
    {
        std::string name, playerClass;
        std::string input;
        std::getline(std::cin, input);
        int spaceIndex = input.find(" ");
        name = input.substr(0, spaceIndex);
        playerClass = input.substr(spaceIndex + 1,input.length() - 1);

        if (isValidPlayerName(name))
        {
            std::unique_ptr<Player> temp(makePlayer(playerClass, name));
            if (temp != nullptr)
            {
                m_players.push_back(std::move(temp));
                playersEntered++;
            }
            else
            {
                printInvalidClass();
            }
        }
        else
        {
            printInvalidName();
        }
    }

// Close the file
    file.close();
}


template<class T>
Player* createPlayer(const char *name) //should we change this on all Player to string instead of char* ??
{
    return new T(name);
}

typedef Player* (*createPlayerFunction)(const char*);
typedef std::map<std::string, createPlayerFunction> StringToPlayerCreateMap;

Player* Mtmchkin::makePlayer(std::string playerClass, std::string name)
{
    StringToPlayerCreateMap map;
    map["Rogue"] = createPlayer<Rogue>;
    map["Fighter"] = createPlayer<Fighter>;
    map["Wizard"] = createPlayer<Wizard>;

    if (map.find(playerClass) == map.end())
        return nullptr;
    return map.find(playerClass)->second(name.c_str());
}

template<class T>
Card* createCard()
{
    return new T();
}

typedef Card* (*createCardFunction)(void);
typedef std::map<std::string, createCardFunction> StringToFunctionMap; //check convention about capital letter at the beginning

//wrap this in try catch if invalid card name was entered, or return null ptr, preferably the latter
Card *Mtmchkin::makeCard(std::string cardName)
{
    StringToFunctionMap map;
    map["Dragon"] = createCard<Dragon>;
    map["Goblin"] = createCard<Goblin>;
    map["Vampire"] = createCard<Vampire>;
    map["Barfight"] = createCard<Barfight>;
    map["Fairy"] = createCard<Fairy>;
    map["Merchant"] = createCard<Merchant>;
    map["Pitfall"] = createCard<Pitfall>;
    map["Treasure"] = createCard<Treasure>;

    if (map.find(cardName) == map.end())
        return nullptr;
    return map.find(cardName)->second();
}

void Mtmchkin::playRound() {
    m_round++;
    printRoundStartMessage(m_round);
    int roundIndex=m_playersNumber;
    while (roundIndex>0)
    {
        roundIndex--;
        std::unique_ptr<Player> current_player=std::move(m_players.front());
        m_players.pop_front();

        printTurnStartMessage(current_player->getName());

        std::unique_ptr<Card> current_card=std::move(m_cards.front());
        m_cards.pop_front();

        current_card->playCard(*current_player);
        m_cards.push_back(std::move(current_card));

        if(current_player->getLevel()>=MAX_LEVEL || current_player->isKnockedOut() )
        {
            m_leaderboard.addPlayer(current_player);
            m_playersNumber--;
        }
        else
        {
            m_players.push_back(std::move(current_player));
        }
        //index++;
        if(isGameOver())
        {
            printGameEndMessage();
        }
    }
}

bool Mtmchkin::isGameOver() const {
    if (m_players.empty())
    {
        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_round;
}

void Mtmchkin::printLeaderBoard() const {
    m_leaderboard.printBoard(m_players);
}




