
#pragma once
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Atribute.h"

struct Value
{
	std::string currency; // type of currency (gold, silver, copper)
	int number;
};

class Equipment : public Atribute {
private:
	std::string m_damage_type; // type of damage (slashing, piercing, bludgeoning)
	std::string m_damage_dice; // dice for damage (1d6, 1d4 etc.)
	Value m_value;
public:
	void SetDamageType(std::string damage_type);
	void SetDamageDice(std::string damage_dice);
	void SetValue(std::string currency, int value);
	const std::string GetDamageType();
	const std::string GetDamageDice();
	const Value GetValue();

};

#endif // !EQUIPMENT_H
