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

std::ostream& operator<<(std::ostream& os, const Ability& ability)
{
	os << "Name: " << ability.m_name << "\n";
	os << "Description: " << ability.m_description << "\n";
	os << "Level: " << ability.m_level << "\n";
	return os;
}