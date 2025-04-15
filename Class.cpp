#include <iostream>
#include <string>
#include "class.h"

Class::Class()
{
	// doar placeholders
	this->m_name = "None";
	this->m_hit_dice = "None";
	this->m_description = "None";
	this->m_class_level = 0;
}

Class::Class(std::string name, std::string hitDice, std::string description, int classLevel)
{
	this->m_name = name;
	this->m_hit_dice = hitDice;
	this->m_description = description;
	this->m_class_level = classLevel;
}

Class::Class(const Class& obj)
{
	this->m_name = obj.m_name;
	this->m_hit_dice = obj.m_hit_dice;
	this->m_description = obj.m_description;
	this->m_class_level = obj.m_class_level;
}

Class::~Class() {}


std::string Class::GetName()
{
	return this->m_name;
}

std::string Class::GetHitDice()
{
	return this->m_hit_dice;
}

std::string Class::GetDescription()
{
	return this->m_description;
}

int Class::GetLevel()
{
	return this->m_class_level;
}

void Class::SetName(std::string name)
{
	this->m_name = name;
}

void Class::SetHitDice(std::string hitDice)
{
	this->m_hit_dice = hitDice;
}

void Class::SetDescription(std::string description)
{
	this->m_description = description;
}

void Class::SetLevel(int level)
{
	if (level >= 1 && level <= 20)
	{
		this->m_class_level = level;
	}
	else
	{
		int newLvl;
		std::cout << "Invalid level, please enter a number between 1 and 20\n";
		std::cin >> newLvl;
		this->SetLevel(newLvl);
	}
}

void Class::ShowClassDetails()
{
	std::cout << "	Class: " << this->m_name << std::endl;
	std::cout << "	Hit Dice: " << this->m_hit_dice << std::endl;
	std::cout << "	Description: " << this->m_description << std::endl;
	std::cout << "	Level: " << this->m_class_level << std::endl << std::endl;
}

std::ostream& operator << (std::ostream& cout, const Class& obj)
{
	cout << "(name: " << obj.m_name << ", hit dice: " << obj.m_hit_dice << ", level: " << obj.m_class_level << ", description: " << obj.m_description << ")";
	return cout;
}