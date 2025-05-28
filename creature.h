#pragma once
#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
//#include "ieffect.h"
#include <iostream>

class Creature : public Entity
{
	std::string m_type; // humanoid, plant, fiend etc.

public:
	void SetType(std::string type);
	int CalculateAbilityStrenghts() override;
	//void InputMessage() override;
};

#endif // !CREATURE_H
