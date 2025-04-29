
#pragma once
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Atribute.h"
#include "iequippable.h"
#include <iostream>

struct Value
{
	std::string currency; // type of currency (gold/ GP, silver/ SP, copper/ CP)
	int number; // the actual ammount :P
	
	/*std::ostream& operator << (const Value& obj)
	{
		std::cout << obj.number << " " << obj.currency << std::endl;
		return std::cout;
	}*/
};

class Equipment : public Atribute, public IEquippable {
private:
	std::string m_damage; // dice for damage (1d6, 1d4 etc.) + type of damage (slashing, piercing, bludgeoning)
	Value m_value;
public:
	void SetDamageType(std::string damage_type);
	void SetDamageDice(std::string damage_dice);
	void SetValue(std::string currency, int value);
	const std::string GetDamageType();
	const std::string GetDamageDice();
	const Value GetValue();
	void Equip(Class* enitity) override;
	void Unequip(Class* enitity) override;
};

#endif // !EQUIPMENT_H
