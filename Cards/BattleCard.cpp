#include "BattleCard.h"

BattleCard::BattleCard(int force,int damageOnLoss,int coinsOnWin, const std::string& name) :
m_force(force),m_damageOnLoss(damageOnLoss),m_coinsOnWin(coinsOnWin), m_name(name)
{
}

