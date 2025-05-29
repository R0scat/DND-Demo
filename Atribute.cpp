#include "atribute.h"
#include <iostream>
//#include <fstream>

// majoritatea functiilor de aici sunt simple si doar ajutatoare (gen returneaza valoarea unui membru sau functie pt constructori)
// singura chiar relevanta este SetId care e functia overriden din clasa abstracta GameObject

Atribute::Atribute() 
{
	this->m_type = "None";
	this->m_name = "None";
	this->m_description = "None";
	//this->m_level = -1;
	// initial aveam level pt atribute, dupa am vazut ca echipamentul n-are nevoie de lvl --> mutat doar pe abilitati
}

Atribute::Atribute(std::string type, std::string name, std::string description, int level)
{
	this->m_type = type;
	this->m_name = name;
	this->m_description = description;
	//this->m_level = level;
}

Atribute::Atribute(const Atribute& atrbuteObject)
{
	this->m_type = atrbuteObject.m_type;
	this->m_name = atrbuteObject.m_name;
	this->m_description = atrbuteObject.m_description;
	//this->m_level = atrbuteObject.m_level;
}

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

std::string Atribute::GetAtributeType() const
{
	return this->m_type;
}

std::string Atribute::GetAtributeName() const
{
	return this->m_name;
}

std::string Atribute::GetAtributeDescription() const
{
	return this->m_description;
}

void Atribute::SetId()
{
	GameObject::m_id++; // creste contorul total al obiectelor
	this->m_object_type = "Atribute"; // seteaza tipul obiectului
	this->m_full_id = m_object_type + std::to_string(GameObject::m_id);
}
