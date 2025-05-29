#include "Race.h"
#include <string>
#include <iostream>

std::string Race::GetName() const
{
	return this->m_name;
}

std::string Race::GetDescription() const
{
	return this->m_description;
}

void Race::SetName(std::string name)
{
	this->m_name = name;
}

void Race::SetDescription(std::string description)
{
	this->m_description = description;
}

void Race::ShowRaceDetails()
{
	std::cout << "Name: " << this->m_name << std::endl;
	std::cout << "Description: " << this->m_description << std::endl;
}

std::ostream& operator << (std::ostream& cout, const Race& obj)
{
	cout << "	Name: " << obj.m_name << "\n	description: " << obj.m_description;
	return cout;
}

void Race::SetId()
{
	GameObject::m_id++; // creste contorul total al obiectelor
	this->m_object_type = "Race"; // seteaza tipul obiectului
	this->m_full_id = m_object_type + std::to_string(GameObject::m_id);
}