#include "atribute.h"
#include <iostream>
//#include <fstream>

Atribute::Atribute() 
{
	this->m_type = "None";
	this->m_name = "None";
	this->m_description = "None";
	this->m_level = -1;
}

Atribute::Atribute(std::string type, std::string name, std::string description, int level)
{
	this->m_type = type;
	this->m_name = name;
	this->m_description = description;
	this->m_level = level;
}

Atribute::Atribute(const Atribute& atrbuteObject)
{
	this->m_type = atrbuteObject.m_type;
	this->m_name = atrbuteObject.m_name;
	this->m_description = atrbuteObject.m_description;
	this->m_level = atrbuteObject.m_level;
}

Atribute::~Atribute() {}

void Atribute::SetAtributeType(std::string type)
{
	this->m_type = type;
}

void Atribute::SetAtributeName(std::string name)
{
	this->m_name = name;
}

void Atribute::SetAtributeDescription(std::string description)
{
	this->m_description = description;
}

void Atribute::SetAtributeLevel(int level)
{
	this->m_level = level;
}

std::string Atribute::GetAtributeType()
{
	return this->m_type;
}

std::string Atribute::GetAtributeName()
{
	return this->m_name;
}

std::string Atribute::GetAtributeDescription()
{
	return this->m_description;
}

int Atribute::GetAtributeLevel()
{
	return this->m_level;
}
