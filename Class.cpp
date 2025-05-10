#include <iostream>
#include <string>
#include "class.h"

#pragma warning(disable : 4996)

Class::Class()
{
	// doar placeholders
	this->m_name = "None";
	this->m_hit_dice = "None";
	this->m_description = "None";
	this->m_class_level = 0;
	this->m_first_prf = NULL;
	this->m_last_prf = NULL;
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


std::string Class::GetName() const
{
	return this->m_name;
}

std::string Class::GetHitDice() const
{
	return this->m_hit_dice;
}

std::string Class::GetDescription() const
{
	return this->m_description;
}

int Class::GetLevel() const
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

void Class::AddProficiency(std::string name) // adauga in lista la final
{
	Proficiency* newProficiency = new Proficiency;
	newProficiency->name = name; // copiaza datele relevante
	newProficiency->next = NULL; // nu are la ce altceva sa pointeze pt ca e la finalul listei
	if (this->m_first_prf == NULL) // verific daca lista are elem
	{
		// primul si ultimul "nod" sunt identice daca lista are un singur elem
		this->m_first_prf = newProficiency;
		this->m_last_prf = newProficiency;
	}
	else
	{
		// adaugarea propriu-zisa yay :P
		this->m_last_prf->next = newProficiency;
		this->m_last_prf = newProficiency;
	}
}

void Class::ShowProficiencies()
{
	Proficiency* current = this->m_first_prf;
	while (current != NULL)
	{
		std::cout << current->name << std::endl;
		current = current->next;
	}
}

void Class::DeleteFirstProficiency()
{
	Proficiency* temp = this->m_first_prf;
	this->m_first_prf = this->m_first_prf->next; // efectiv muti inceputul la pozitia urmatoare
	delete temp; // sterge nodul ramas + prevents memory leak :P
}

void Class::DeleteLastProficiency()
{
	// pt ca e o lista simpla si nu dubla inlantuita (tre sa parcurg tot pt a ajunge la ultimul elem)
	Proficiency* current = this->m_first_prf;
	while (current->next->next != NULL) // caut penultimul nod (ultimul nod are next ul nul deci next->next pt penultimul)
	{
		current = current->next;
	}

	current->next = NULL; // next ar fi fost ultima pozitie asa ca sterg
	this->m_last_prf = current; // mut ultimul nod la penultimul
	delete current->next;
}