#include <map>
#include "Mtmchkin.h"


const std::string Mtmchkin::GANG_START="Gang";
const std::string Mtmchkin::GANG_END = "EndGang";
const std::string Mtmchkin::SPACE = " ";

//add this to .h file later, remove this
/*
bool Mtmchkin::isNumber(std::string& str)
{
    for (char i : str)
        if (!isdigit(i))
            return false;
    return true;
}
 */

void Mtmchkin::getCards(std::ifstream& file)
{
    std::string card;
    int currentLine = 1;
    bool gangMode= false;
    std::unique_ptr<Gang> lastGang(new Gang());
    while (getline (file, card))
    {
        if (strcmp(card.c_str(),GANG_START.c_str()) == 0)
        {
            if (gangMode)
            {
                throw DeckFileFormatError(currentLine);
            }
            gangMode = true;
        }
        else if(strcmp(card.c_str(),GANG_END.c_str()) == 0)
        {
            if (!gangMode)
            {
                throw DeckFileFormatError(currentLine);
            }
            m_cards.push_back(std::move(lastGang));
            lastGang= std::unique_ptr<Gang>(new Gang());
            gangMode = false;
        }
        else
        {
            std::unique_ptr<Card> temp(makeCard(card));
            if (temp == nullptr)
            {
                throw DeckFileFormatError(currentLine);
            }

            if(gangMode)
            {
                BattleCard* monster = dynamic_cast<BattleCard*>(temp.release());
                if(monster!= nullptr)
                {
                    std::unique_ptr<BattleCard> insertMonster(monster);
                    lastGang->addMonster(insertMonster);
                }
                else
                {
                    throw DeckFileFormatError(currentLine);
                }

            } else
            {
                m_cards.push_back(std::move(temp));
            }
        }
        currentLine++;
    }
    if (gangMode)
    {
        throw DeckFileFormatError(currentLine);
    }
}

int Mtmchkin::getNumOfPlayers()
{
    int numOfPlayers = 0;
    do {
        printEnterTeamSizeMessage();
        std::string input;
        std::getline(std::cin, input);
        try
        {
            if (stoi(input) < MIN_NUMBER_PLAYERS || stoi(input) > MAX_NUMBER_PLAYERS)
            {
                printInvalidTeamSize();
            }
            else
            {
                numOfPlayers = stoi(input);
            }
        }
        catch (std::invalid_argument& e)
        {
            printInvalidTeamSize();
        }

    }
    while (!numOfPlayers);

    return numOfPlayers;
}

bool Mtmchkin::isValidPlayerName(std::string& name)
{
    int charCount = 0;
    for (char c : name)
    {
        if (!std::isalpha(c))
        {
            return false;
        }
        charCount++;
    }
    return charCount <= 15;
}

void Mtmchkin::getPlayers(int numOfPlayers)
{
    int playersEntered = 0;
    while (playersEntered < numOfPlayers)
    {
        printInsertPlayerMessage();
        std::string name, playerClass;
        std::string input;
        bool isValid = false;
        do {
            std::getline(std::cin, input);
            int spaceIndex = input.find(SPACE);
            name = input.substr(0, spaceIndex);
            playerClass = input.substr(spaceIndex + 1, input.length() - 1);

            if (isValidPlayerName(name))
            {
                std::unique_ptr<Player> temp(makePlayer(playerClass, name));
                if (temp != nullptr)
                {
                    isValid = true;
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
        } while (!isValid);
    }
}

Mtmchkin::Mtmchkin(const std::string& fileName):m_round(0)
{
    printStartGameMessage();

    std::ifstream file(fileName);
    if (!file)
    {
        throw DeckFileNotFound();
    }
    getCards(file);
    if (m_cards.size() < MIN_AMOUNT_OF_CARDS)
    {
        throw DeckFileInvalidSize();
    }

    m_playersNumber = getNumOfPlayers();
    getPlayers(m_playersNumber);
}

template<class T>
Player* createPlayer(const char *name) //should we change this on all Player to string instead of char* ??
{
    return new T(name);
}

typedef Player* (*createPlayerFunction)(const char*);
typedef std::map<std::string, createPlayerFunction> StringToPlayerCreateMap;

Player* Mtmchkin::makePlayer(std::string& playerClass, std::string& name)
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
Card* createCard() //should it be smart ptr ???? @983 !! :(
{
    return new T();
}

typedef Card* (*createCardFunction)(void);
typedef std::map<std::string, createCardFunction> StringToFunctionMap; //check convention about capital letter at the beginning

//wrap this in try catch if invalid card name was entered, or return null ptr, preferably the latter
Card *Mtmchkin::makeCard(std::string& cardName)
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

void Mtmchkin::playRound()
{
    //if (!isGameOver()) ?????
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

        if(current_player->getLevel()>=Player::MAX_LEVEL || current_player->isKnockedOut() )
        {
            m_leaderboard.addPlayer(current_player);
            m_playersNumber--;
        }
        else
        {
            m_players.push_back(std::move(current_player));
        }

        if(isGameOver())
        {
            printGameEndMessage();
        }
    }
}

bool Mtmchkin::isGameOver() const
{
    return m_players.empty();
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_round;
}

void Mtmchkin::printLeaderBoard() const
{
    m_leaderboard.printBoard(m_players);
}




