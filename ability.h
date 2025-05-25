#pragma once
#ifndef ABILITY_H
#define ABILITY_H

#include "atribute.h"
#include "iequippable.h"
#include "entity.h"

// clasa folosita mai mult pt a putea echipa abilitatea in functie de level-ul personajului
class Ability: public Atribute// public IEquippable // interfata pt toate efectele pe care le poate avea un pc / any living creature
{
	int m_level;
public:
	//void Equip(Class enitty) override;
	//void Unequip(Class enitty) override;
	void SetAbilityLevel(int level);
	int GetAbilityLevel() const;
};


#endif // !ABILITY_H
