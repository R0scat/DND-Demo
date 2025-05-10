#include "Equipment.h"

//void Equipment::SetDamageType(std::string damage_type)
//{
//	this->m_damage_type = damage_type;
//}
//
//void Equipment::SetDamageDice(std::string damage_dice)
//{
//	this->m_damage_dice = damage_dice;
//}

void Equipment::SetDamage(std::string damage)
{
	this->m_damage = damage;
}

void Equipment::SetCurrencyValue(std::string currency)
{
	this->m_value = currency;
}

void Equipment::SetWeight(std::string weight)
{
	this->m_weight = weight;
}

//const std::string Equipment::GetDamageType()
//{
//	return this->m_damage_type;
//}
//
//const std::string Equipment::GetDamageDice()
//{
//	return this->m_damage_dice;
//}

const std::string Equipment::GetDamage() const
{
	return this->m_damage;
}

const std::string Equipment::GetCurrencyValue() const
{
	return this->m_value;
}

const std::string Equipment::GetWeight() const
{
	return this->m_weight;
}

void Equipment::Equip(Class* entity)
{

}

void Equipment::Unequip(Class* entity)
{

}

std::ostream& operator<<(std::ostream& os, const Equipment& equipment)
{
	os << "Name: " << equipment.m_name << "\n";
	os << "Description: " << equipment.m_description << "\n";
	//os << "Level: " << equipment.m_level << "\n";
	os << "Damage: " << equipment.m_damage << "\n";
	os << "Value: " << equipment.m_value << "\n";
	os << "Weight: " << equipment.m_weight << "\n";
	os << "Type: " << equipment.m_type << "\n";
	return os;
}