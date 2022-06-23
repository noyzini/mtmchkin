#include "Gang.h"

const std::string Gang::GANG_NAME="Gang";
const std::string Gang::VAMPIYRE_CHECK ="Vampire";

Gang::Gang() : Card()
{
}

template<class T>
std::unique_ptr<BattleCard> createCard()
{
    return std::unique_ptr<BattleCard>(new T());
}

typedef std::unique_ptr<BattleCard> (*createCardFunction)(void);
typedef std::map<std::string, createCardFunction> StringToFunctionMap;


std::unique_ptr<BattleCard> Gang::makeCard(std::string& cardName)
{
    StringToFunctionMap map;
    map["Dragon"] = createCard<Dragon>;
    map["Goblin"] = createCard<Goblin>;
    map["Vampire"] = createCard<Vampire>;

    if (map.find(cardName) == map.end())
        return nullptr;
    return map.find(cardName)->second();
}







void Gang::addMonster(std::unique_ptr<BattleCard> &card) {
    m_gang.push_back(std::move(card));
}

void Gang::playCard(Player &player) const
{
    int index=0;
    bool playOn= true;
    int gangSize=m_gang.size();
    for(; index < gangSize && playOn; index++)
    {
        if (player.getAttackStrength() >= m_gang[index]->m_force)
        {
            player.addCoins(m_gang[index]->m_coinsOnWin);
        }
        else
        {
            playOn= false;
        }
    }
    if(playOn)
    {
        player.levelUp();
        printWinBattle(player.getName(),GANG_NAME);
    } else
    {
        index--;
        for(; index < gangSize; index++)
        {
            player.damage(m_gang[index]->m_damageOnLoss);
            if(m_gang[index]->m_name==VAMPIYRE_CHECK)
            {
                player.loseForce();
            }
            printLossBattle(player.getName(),m_gang[index]->m_name);
        }
    }
}

void Gang::print(std::ostream &os) const {
    os<<"This is a Gang card\n";
    int gangSize=m_gang.size();
    for(int i=0;i<gangSize;i++)
    {
        m_gang[i]->print(os);
    }
    os<<"End of Gang card\n";
}

Gang &Gang::operator=(const Gang& gang) {
    if (this==&gang)
    {
        return *this;
    }
    int gangSize=gang.m_gang.size();
    int i=0;
    for(;i<gangSize;i++)
    {
        std::unique_ptr<BattleCard> temp(makeCard(gang.m_gang.front()->m_name));
        if (temp == nullptr){
            throw std::exception();
        }
        else
        {
            this->m_gang[i]=std::move(temp);
        }
    }
    int toBeDeleted= this->m_gang.size();
    for(;i<toBeDeleted;i++)
    {
        this->m_gang[i].release();
    }
}

Gang::Gang(const Gang &gang): Card() {
    int gangSize=gang.m_gang.size();
    for(int i=0;i<gangSize;i++) {
        std::unique_ptr<BattleCard> temp(makeCard(gang.m_gang.front()->m_name));
        if (temp == nullptr){
            throw std::exception();
        }
        else
        {
            this->m_gang.push_back(std::move(temp));
        }
    }
}
