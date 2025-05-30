
#pragma once
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Atribute.h"
#include "iequippable.h" 
//#include "class.h"
#include "entity.h"
#include <iostream>

// obs: orice echipament poate fi folosit la orice level atata timp cat personajul are proficiency cu tipul de echipament
class Equipment : public Atribute, public Iequippable
{
protected:
	std::string m_damage; // dice for damage (1d6, 1d4 etc.) + type of damage (slashing, piercing, bludgeoning)
	std::string m_value;
	std::string m_weight; // in pounds bc thats what dnd uses
public:
	void SetDamage(std::string damage);
	//void SetDamageType(std::string damage_type);
	//void SetDamageDice(std::string damage_dice);
	void SetCurrencyValue(std::string currency);
	//const std::string GetDamageType();
	//const std::string GetDamageDice();
	void SetWeight(std::string weight);
	const std::string GetDamage() const;
	const std::string GetCurrencyValue() const;
	const std::string GetWeight() const;
	void Equip(Entity* entity) override;
	void Unequip(Entity* entity) override;
	friend std::ostream& operator<<(std::ostream& os, const Equipment& equipment);
};
// obs: Equipment va avea id-ul de tip Atribute1, Atribute2, ... pt ca mosteneste clasa 

#endif // !EQUIPMENT_H