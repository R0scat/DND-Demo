#include "Entity.h"
#include <algorithm>
#include <cstring>

#pragma warning(disable : 4996)

using namespace std;

Entity::Entity() 
{
	EntityDetails details;
	int hp;
	std::cout << "Creating entity, choose your HP:\n";
	std::cin >> hp;

	std::cout << "\nChose your stats:\n!Note: input must be given in the following format: [strenght dexterity constitution intelligence wisdom charisma]\n";
	std::cin >> details.stats.strength;
	std::cin >> details.stats.dexterity;
	std::cin >> details.stats.constitution;
	std::cin >> details.stats.intelligence;
	std::cin >> details.stats.wisdom;
	std::cin >> details.stats.charisma;

	Entity::PopulateSkills(details);
	Entity::CalculateSkills(details);

	this->m_health_points = hp;
	this->m_details = details;
}

Entity::~Entity() 
{
	//cout << "Destroyed Entity!" << endl;
}

Entity::Entity(int health)
{
	this->m_health_points = health;
	cout << "Created Entity with " << health << " HP!" << endl;
}

void Entity::GetHealth() const
{
	cout << "Health: " << m_health_points << endl;
}

void Entity::SetHealth(int health) {
	m_health_points = health;
}

void Entity::Apply(Effect applied_effect)
{
	this->m_active_effects.push_back(applied_effect);
}

void Entity::Remove(Effect removed_effect)
{
	std::vector<Effect>::iterator position = std::find(m_active_effects.begin(), m_active_effects.end(), removed_effect);
	if (position != m_active_effects.end())
		m_active_effects.erase(position);
}

void Entity::ShowAllEffects()
{
	for (Effect item : this->m_active_effects)
		std::cout << item;
}

void Entity::CalculateSkills(EntityDetails& details)
{
	for (int i = 0; i < 17; i++)
	{
		if (strcmp(details.skills[i].statType, "strenght") == 0)
		{
			details.skills[i].bonus = (details.stats.strength - 10) / 2;
		}
		if (strcmp(details.skills[i].statType, "dexterity") == 0)
		{
			details.skills[i].bonus = (details.stats.dexterity - 10) / 2;
		}
		if (strcmp(details.skills[i].statType, "constitution") == 0)
		{
			details.skills[i].bonus = (details.stats.constitution - 10) / 2;
		}
		if (strcmp(details.skills[i].statType, "intelligence") == 0)
		{
			details.skills[i].bonus = (details.stats.intelligence - 10) / 2;
		}
		if (strcmp(details.skills[i].statType, "wisdom") == 0)
		{
			details.skills[i].bonus = (details.stats.wisdom - 10) / 2;
		}
		if (strcmp(details.skills[i].statType, "charisma") == 0)
		{
			details.skills[i].bonus = (details.stats.charisma - 10) / 2;
		}
	}
		
}

void Entity::PopulateSkills(EntityDetails& details)
{
	char skill_names[50][50] =
	{
		"acrobatics",
		"animal handling",
		"arcana",
		"athletics",
		"deception",
		"history",
		"insight",
		"intimidation",
		"investigation",
		"medicine",
		"nature",
		"perception",
		"performance",
		"persuasion",
		"religion",
		"sleight of hand",
		"stealth",
		"survival"
	};
	char skill_types[50][50] =
	{
		"dexterity",
		"wisdom",
		"intelligence",
		"strenght",
		"charisma",
		"intelligence",
		"wisdom", // insight
		"charisma",
		"intelligence",
		"wisdom",
		"intelligence",
		"wisdom",
		"charisma", // performance
		"persuasion",
		"religion",
		"dexterity",
		"dexterity",
		"wisdom"
	};
	for (int i = 0; i < 18; i++)
	{
		strcpy(details.skills[i].name, skill_names[i]);
		strcpy(details.skills[i].statType, skill_types[i]);
		details.skills[i].proficient = false;
		details.skills[i].expert = false;
		details.skills[i].nr = 0;
	}
}

void Entity::InputMessage()
{
	
}

std::ostream& operator << (std::ostream& cout, const Entity& obj)
{
	cout << "Health Points: " << obj.m_health_points << "\n";
	cout << "Details: \n" << obj.m_details << "\n";
	return cout;
}

