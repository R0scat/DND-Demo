#include "Atribute.h"
#include <iostream>
//#include <fstream>

Atribute::Atribute() 
{
	this->type = "None";
	this->name = "None";
	this->description = "None";
	this->level = -1;
}

Atribute::Atribute(std::string type, std::string name, std::string description, int level)
{
	this->type = type;
	this->name = name;
	this->description = description;
	this->level = level;
}

Atribute::Atribute(const Atribute& atrbuteObject)
{
	this->type = atrbuteObject.type;
	this->name = atrbuteObject.name;
	this->description = atrbuteObject.description;
	this->level = atrbuteObject.level;
}

Atribute::~Atribute() {}

void Atribute::setAtributeType(std::string type)
{
	this->type = type;
}

void Atribute::setAtributeName(std::string name)
{
	this->name = name;
}

void Atribute::setAtributeDescription(std::string description)
{
	this->description = description;
}

void Atribute::setAtributeLevel(int level)
{
	this->level = level;
}

std::string Atribute::getAtributeType()
{
	return this->type;
}

std::string Atribute::getAtributeName()
{
	return this->name;
}

std::string Atribute::getAtributeDescription()
{
	return this->description;
}

int Atribute::getAtributeLevel()
{
	return this->level;
}
