#include "Race.h"
#include <string.h>
#include <iostream>

Race::Race() {
	this->m_name = "None";
	this->m_description = "None";
}

Race::Race(std::string name, std::string description)
{
	this->m_name = name;
	this->m_description = description;
}

Race::Race(const Race& RaceObj)
{
	this->m_name = RaceObj.m_name;
	this->m_description = RaceObj.m_description;
}

Race:: ~Race() {}

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