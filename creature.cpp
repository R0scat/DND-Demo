#include "creature.h"

int Creature::CalculateAbilityStrenghts()
{
	int ab_str = 0;
	for (int i = 0; i < 18; i++)
		ab_str += this->m_details.skills[i].bonus;
	if (this->m_type == "fiend")
		ab_str = ab_str * 2;// std::cout << "avem polimorfism"; // DEBUG
	if (this->m_type == "celestial")
		ab_str = ab_str * 5;
	return ab_str;
}

void Creature::SetType(std::string type)
{
	this->m_type = type;
}