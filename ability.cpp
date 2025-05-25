#include "ability.h"
#include "class.h"
//
//void Ability::Equip(Class entity)
//{
//
//}
//
//void Ability::Unequip(Class entity)
//{
//
//}

void Ability::SetAbilityLevel(int level)
{
	this->m_level = level;
}

int Ability::GetAbilityLevel() const
{
	return this->m_level;
}