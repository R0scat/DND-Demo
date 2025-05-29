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

	do
	{
		std::cout << "\nChose your stats:\n!Note: input must be in the interval [0, 30] and given in the following format: [strenght dexterity constitution intelligence wisdom charisma]\n";
		std::cin >> details.stats.strength;
		std::cin >> details.stats.dexterity;
		std::cin >> details.stats.constitution;
		std::cin >> details.stats.intelligence;
		std::cin >> details.stats.wisdom;
		std::cin >> details.stats.charisma;
	} while (Entity::CheckIfStatsInInterval() != true);
	

	Entity::PopulateSkills(details);
	Entity::CalculateSkills(details);

	this->m_health_points = hp;
	this->m_details = details;
}

Entity::Entity(const Entity& obj)
{
	this->m_health_points = obj.m_health_points;
	this->m_details = obj.m_details;
	this->m_active_effects = obj.m_active_effects;
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

Effect Entity::GetEffectByName(std::string effect_name)
{
	for (auto item : m_active_effects)
		if (item.GetName() == effect_name)
			return item;
}

void Entity::Remove(std::string effect_name)
{
	Effect removed_effect = this->GetEffectByName(effect_name);

	std::vector<Effect>::iterator position = std::find(m_active_effects.begin(), m_active_effects.end(), removed_effect);
	if (position != m_active_effects.end())
		m_active_effects.erase(position);
}

void Entity::ShowAllEffects()
{
	for (Effect item : this->m_active_effects)
	{
		std::cout << item;
		std::cout << "\n";
	}
}

void Entity::CalculateSkills(EntityDetails& details)
{
	for (int i = 0; i < 18; i++)
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
		"charisma",
		"intelligence",
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

int Entity::CalculateAbilityStrenghts()
{
	return 0;
}

std::ostream& operator << (std::ostream& cout, const Entity& obj)
{
	cout << "Health Points: " << obj.m_health_points << "\n";
	cout << "Details: \n" << obj.m_details << "\n";
	return cout;
}

void Entity::ChangeCharacterStats()
{
	do
	{
		std::cout << "To change stats you must first give new values\n";
		std::cout << "Note: input must be in the interval [0, 30] and given in the following format: [strenght dexterity constitution intelligence wisdom charisma]\n";
		std::cin >> this->m_details.stats.strength;
		std::cin >> this->m_details.stats.dexterity;
		std::cin >> this->m_details.stats.constitution;
		std::cin >> this->m_details.stats.intelligence;
		std::cin >> this->m_details.stats.wisdom;
		std::cin >> this->m_details.stats.charisma;
		std::cout << "Stats changed!\n";
	} while (Entity::CheckIfStatsInInterval() != true);
	
	// recalculating skills after ability change
	Entity::CalculateSkills(this->m_details);
}

void Entity::ChangeGivenProficiency(char prf_name[50])
{
	for (int i = 0; i < 18; i++)
		if (strcmp(this->m_details.skills[i].name, prf_name) == 0)
		{
			if (this->m_details.skills[i].nr == 0) // verific daca avea deja proficiency 
			{
				this->m_details.skills[i].proficient = true;
				this->m_details.skills[i].bonus += 2;
				this->m_details.skills[i].nr++;
			}
			if (this->m_details.skills[i].nr == 1) // daca avea deja proficiency se pune expertise 
			{
				this->m_details.skills[i].expert = true;
				this->m_details.skills[i].bonus += 2;
				this->m_details.skills[i].nr++;
			}
			// dnd nu are mai mult de atat soooo aiaie
		}
}

std::vector<Effect> Entity::ReturnEffectVector()
{
	return this->m_active_effects;
}

bool Entity::CheckIfStatsInInterval()
{
	if (this->m_details.stats.strength < 0 || this->m_details.stats.strength > 30)
		return false;
	if (this->m_details.stats.dexterity < 0 || this->m_details.stats.dexterity > 30)
		return false;
	if (this->m_details.stats.constitution < 0 || this->m_details.stats.constitution > 30)
		return false;
	if (this->m_details.stats.intelligence < 0 || this->m_details.stats.intelligence > 30)
		return false;
	if (this->m_details.stats.wisdom < 0 || this->m_details.stats.wisdom > 30)
		return false;
	if (this->m_details.stats.charisma < 0 || this->m_details.stats.charisma > 30)
		return false;
	return true;
}

void Entity::SetId()
{
	GameObject::m_id++; // creste contorul total al obiectelor
	this->m_object_type = "Entity"; // seteaza tipul obiectului
	this->m_full_id = m_object_type + std::to_string(GameObject::m_id);
}