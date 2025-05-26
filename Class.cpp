
#include <iostream>
#include <string>
#include <vector>
#include "class.h"
#pragma warning(disable : 4996) 

// definitie pt membrul static
std::vector<Equipment> Class::m_available_equipment;

// helper function to deallocate lists
void Class::ClearLists() {
	// clear proficiencies
	Proficiency* current_prf = m_first_prf;
	while (current_prf != nullptr) // cat timp nu e null elem curent
	{
		Proficiency* next_prf = current_prf->next; // se pastreaza urm elem din lista
		delete current_prf;  // se sterge elem curent
		current_prf = next_prf; // se copiaza urm element in cel curent (se trece la urm)
	}
	m_first_prf = nullptr;
	m_last_prf = nullptr;

	// clear equipment
	// analog ca mai sus
	EquippedItem* current_eq = m_first_equipped;
	while (current_eq != nullptr) {
		EquippedItem* next_eq = current_eq->next;
		delete current_eq;
		current_eq = next_eq;
	}
	m_first_equipped = nullptr;
	m_last_equipped = nullptr;
}

Class::Class()
{
	this->m_name = "None";
	this->m_hit_dice = "None";
	this->m_description = "None";
	this->m_class_level = 0;
	// pointerii initializati cu nullptr 
	this->m_first_prf = nullptr; 
	this->m_last_prf = nullptr;
	this->m_first_equipped = nullptr;
	this->m_last_equipped = nullptr;
	// m_vector_abilities e construit default empty
}

Class::Class(std::string name, std::string hitDice, std::string description, int classLevel)
{
	// populez doar valorile care nu sunt dinamice
	this->m_name = name;
	this->m_hit_dice = hitDice;
	this->m_description = description;
	this->m_class_level = classLevel;
	// pointerii sunt nuli ca in constructorul simplu
	this->m_first_prf = nullptr; 
	this->m_last_prf = nullptr;
	this->m_first_equipped = nullptr;
	this->m_last_equipped = nullptr;
}

// copy Constructor
Class::Class(const Class& other)
{
	// membrii simpli se copiaza usor
	this->m_name = other.m_name;
	this->m_hit_dice = other.m_hit_dice;
	this->m_description = other.m_description;
	this->m_class_level = other.m_class_level;

	// deep copy for the vector of abilities
	this->m_vector_abilities = other.m_vector_abilities; // std::vector handles its own deep copy

	// Initialize list heads for the new object
	// se initializeaza inceputul si finalul (ale ambelor liste) pt obiectul nou
	this->m_first_prf = nullptr;
	this->m_last_prf = nullptr;
	this->m_first_equipped = nullptr;
	this->m_last_equipped = nullptr;

	// "deep copy" for proficiencies linked list 
	// i.e. se copiaza element cu element 
	Proficiency* current_other_prf = other.m_first_prf;
	while (current_other_prf != nullptr) {
		this->AddProficiency(current_other_prf->name);
		current_other_prf = current_other_prf->next;
	}

	// "deep copy" for equipment linked list
	EquippedItem* current_other_eq = other.m_first_equipped;
	while (current_other_eq != nullptr) {
		this->AddEquipment(current_other_eq->item); // AddEquipment takes Equipment by value or const ref
		current_other_eq = current_other_eq->next;
	}
}

// copy assignment operator (=)
Class& Class::operator=(const Class& other)
{
	// daca e egal n-ai ce schimba 
	if (this == &other) {
		return *this;
	}

	// se sterg toate datele alocate dinamic vechi pastrate de obiect (alocarea dinamica neavand un numar fix de elemente chetia asta e necesara pt ca altfel se poate ramane cu date in surplus - also probabil memory leak dar im not that sure abt it)
	ClearLists(); // dealocare ambele liste (cu functia privata)
	this->m_vector_abilities.clear(); // Clear the vector

	// copiere membrii simpli
	this->m_name = other.m_name;
	this->m_hit_dice = other.m_hit_dice;
	this->m_description = other.m_description;
	this->m_class_level = other.m_class_level;

	// deep copy dynamic members
	this->m_vector_abilities = other.m_vector_abilities; 

	// analog ca la constructorul de copiere
	this->m_first_prf = nullptr;
	this->m_last_prf = nullptr;
	this->m_first_equipped = nullptr;
	this->m_last_equipped = nullptr;

	// elemente proficiency
	Proficiency* current_other_prf = other.m_first_prf;
	while (current_other_prf != nullptr) {
		this->AddProficiency(current_other_prf->name);
		current_other_prf = current_other_prf->next;
	}
	// elemente equipment
	EquippedItem* current_other_eq = other.m_first_equipped;
	while (current_other_eq != nullptr) {
		this->AddEquipment(current_other_eq->item);
		current_other_eq = current_other_eq->next;
	}

	return *this;
}


// destructor
Class::~Class()
{
	ClearLists(); // dealocare liste dinamica
	// m_vector_abilities se va dealoca de la sine
}


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
	// verif daca e in intervalul [1, 20] daca nu se reapeleaza functia pana cand este
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
	// apelarea recursiva nu ar tb sa fie o problema pt ca nu e un proiect mare care sa nu mai aiba memorie 
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

void Class::AddProficiency(std::string name)
{
	Proficiency* newProficiency = new Proficiency; // se creeaza un nou pointer de tip proficiency (ce urm sa fie adaugat in lista)
	newProficiency->name = name; // se populeaza informatia din elementul listei
	newProficiency->next = nullptr; // elementul va fi pus la coada deci nu va pointa (arata?) catre niciun alt element din lista
	if (this->m_first_prf == nullptr) // daca lista e vida
	{
		// si primul si ultimul element vor fi egale
		this->m_first_prf = newProficiency;
		this->m_last_prf = newProficiency;
	}
	else
	{
		// altfel se lipeste de ultimul membru al listei prin pointerul next si dupa se modifica elementul pastrat in m_last_prf pt a semnaliza noul final de lista
		this->m_last_prf->next = newProficiency;
		this->m_last_prf = newProficiency;
	}
}

void Class::ShowProficiencies() const
{
	Proficiency* current = this->m_first_prf; // primul elem din lista
	if (current == nullptr) // daca lista e goala
	{
		std::cout << "No proficiencies to show :((" << std::endl;
		return;
	}
	while (current != nullptr)
	{
		// se afiseaza element cu element
		std::cout << current->name << std::endl;
		current = current->next;
	}
}

void Class::DeleteFirstProficiency()
{
	if (m_first_prf == nullptr) 
		return; // lista nu are elemente

	Proficiency* temp = this->m_first_prf;
	this->m_first_prf = this->m_first_prf->next;
	delete temp;
	if (this->m_first_prf == nullptr)
	{ 
		// lista nu mai are elem / a fost sters ultimul elem
		this->m_last_prf = nullptr;
	}
}

void Class::DeleteLastProficiency()
{
	// analog cu metoda de mai sus doar ca tb parcursa toata lista pt a putea gasi utimul element
	if (m_first_prf == nullptr)
		return; 

	if (m_first_prf == m_last_prf) // lista are un singur elem
	{ 
		
		delete m_first_prf;
		m_first_prf = nullptr;
		m_last_prf = nullptr;
		return;
	}

	Proficiency* current = this->m_first_prf; // current va fi elementul curent din lista cu ajutorul caruia se va itera prin lista
	while (current->next != m_last_prf) // caut penultimul nod
	{
		current = current->next;
	}

	delete m_last_prf; // se sterge ultimul nod
	current->next = nullptr; // penultimul devine ultimul 
	this->m_last_prf = current;
}

void Class::AddEquipment(const Equipment& item) 
{
	// analog pt the equipment list
	EquippedItem* newItem = new EquippedItem;
	newItem->item = item; 
	newItem->next = nullptr;
	if (this->m_first_equipped == nullptr)
	{
		this->m_first_equipped = newItem;
		this->m_last_equipped = newItem;
	}
	else
	{
		this->m_last_equipped->next = newItem;
		this->m_last_equipped = newItem;
	}
}
void Class::ShowEquipment() const
{
	EquippedItem* current = this->m_first_equipped;
	if (current == nullptr) 
	{
		std::cout << "No equipment to show :((" << std::endl;
		return;
	}
	while (current != nullptr)
	{
		std::cout << current->item << std::endl; // Assumes Equipment has operator<<
		current = current->next;
	}
}
void Class::DeleteFirstEquippedItem()
{
	if (m_first_equipped == nullptr) return;

	EquippedItem* temp = this->m_first_equipped;
	this->m_first_equipped = this->m_first_equipped->next;
	delete temp;
	if (this->m_first_equipped == nullptr) 
	{
		this->m_last_equipped = nullptr;
	}
}
void Class::DeleteLastEquippedItem()
{
	if (m_first_equipped == nullptr) return;

	if (m_first_equipped == m_last_equipped) 
	{
		delete m_first_equipped;
		m_first_equipped = nullptr;
		m_last_equipped = nullptr;
		return;
	}

	EquippedItem* current = this->m_first_equipped;
	while (current->next != m_last_equipped)
	{
		current = current->next;
	}
	delete m_last_equipped;
	current->next = nullptr;
	this->m_last_equipped = current;
}

void Class::AddAbility(const Ability& de_adaugat) 
{
	this->m_vector_abilities.push_back(de_adaugat); 
}

void Class::ShowAbilities() const
{
	if (m_vector_abilities.empty()) 
	{
		std::cout << "No abilities to show :((" << std::endl;
		return;
	}
	for (const Ability& item : m_vector_abilities) 
		std::cout << item << '\n'; 
}

// static methods
void Class::SetAvailableEquipment(const Equipment array[], int nr_elements)
{
	// se creeaza vectorul de la un array deja parsat in functia ReadEquipment din atribute_helper
	m_available_equipment.assign(array, array + nr_elements);
}

const std::vector<Equipment>& Class::GetAvailableEquipment()
{
	// returneaza tot vectorul 
	return m_available_equipment;
}

void Class::ShowAllAvailableEquipment()
{
	// trece prin elem vectorului static m_available_equipment
	for (const Equipment& item : m_available_equipment)
	{
		std::cout << item << '\n';
	}
}

Equipment Class::GetSpecificAvailableEquipment(int contor)
{
	// verif daca ai elementul
	if (contor >= 0 && contor < m_available_equipment.size()) 
	{
		return m_available_equipment[contor];
	}
	return Equipment(); // daca nu exista elementul cu contorul dat se returneaza un default Equipment object
}
