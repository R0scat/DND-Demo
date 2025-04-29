#pragma once
#ifndef ABILITY_H
#define ABILITY_H

#include "atribute.h"
#include "iequippable.h"
#include "entity.h"

// clasa folosita mai mult pt a putea echipa abilitatea in functie de level-ul personajului
class Ability: public Atribute, public IEquippable // interfata pt toate efectele pe care le poate avea un pc / any living creature
{
public:
	void Equip(Entity* enitty) override;
	void Unequip(Entity* enitty) override;
};


#endif // !ABILITY_H
