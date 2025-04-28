#include "Equipment.h"

void Equipment::SetDamageType(std::string damage_type)
{
	this->m_damage_type = damage_type;
}

void Equipment::SetDamageDice(std::string damage_dice)
{
	this->m_damage_dice = damage_dice;
}

void Equipment::SetValue(std::string currency, int number)
{
	this->m_value.currency = currency;
	this->m_value.number = number;
}

const std::string Equipment::GetDamageType()
{
	return this->m_damage_type;
}

const std::string Equipment::GetDamageDice()
{
	return this->m_damage_dice;
}

const Value Equipment::GetValue()
{
	return this->m_value;
}

