#include <iostream>
#include <string>
#include "Class.h"

Class::Class()
{
	this->name = "None";
	this->hitDice = "None";
	this->description = "None";
}

Class::Class(std::string name, std::string hitDice, std::string description)
{
	this->name = name;
	this->hitDice = hitDice;
	this->description = description;
}

Class::Class(const Class& obj)
{
	this->name = obj.name;
	this->hitDice = obj.hitDice;
	this->description = obj.description;
}

Class::~Class() {}


std::string Class::getName()
{
	return this->name;
}

std::string Class::getHitDice()
{
	return this->hitDice;
}

std::string Class::getDescription()
{
	return this->description;
}

int Class::getLevel()
{
	return this->level;
}

void Class::setName(std::string name)
{
	this->name = name;
}

void Class::setHitDice(std::string hitDice)
{
	this->hitDice = hitDice;
}

void Class::setDescription(std::string description)
{
	this->description = description;
}

void Class::setLevel(int level)
{
	if (level >= 1 && level <= 20)
	{
		this->level = level;
	}
	else
	{
		std::cout << "Invalid level, please enter a number between 1 and 20\n";
		std::cin >> level;
		this->setLevel(level);
	}
}

void Class::showClassDetails()
{
	std::cout << "Class: " << this->name << std::endl;
	std::cout << "Hit Dice: " << this->hitDice << std::endl;
	std::cout << "Description: " << this->description << std::endl;
	std::cout << "Level: " << this->level << std::endl;
}