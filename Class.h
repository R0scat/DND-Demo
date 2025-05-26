
#pragma once
#ifndef CLASS_H
#define CLASS_H

#include <string>
#include "equipment.h" 
#include <vector>
#include "ability.h"   

// lista dinamica de proficiencies (fiind mai multe si diferite in functie de clasa e mai bine decat sa aloc un anumit numar lowk random)
// data de tip string si pointerul catre urm elem din lista
struct Proficiency
{
	std::string name;
	Proficiency* next;
};

// lista simplu inlantuita pt toate echipamentele pe care o sa le aiba personajul 
// tine data de tip Equipment si pointerul catre urmatorul element din lista
struct EquippedItem
{
	Equipment item;
	EquippedItem* next;
};

class Class {
protected:
	std::string m_name;
	std::string m_hit_dice;
	std::string m_description;
	int m_class_level;

	// pt lista de proficiencies
	Proficiency* m_first_prf;
	Proficiency* m_last_prf;

	// pt lista de equipment
	EquippedItem* m_first_equipped;
	EquippedItem* m_last_equipped;

	// vector pt toate abilitatile 
	std::vector<Ability> m_vector_abilities;

	// vector static ce pastreaza toate tipurile standard de echipamente (am mai multe file-uri cu diferite tipuri de echipamente, ele sunt citite cu o functie din namespace-ul Atribute_Helper)
	static std::vector<Equipment> m_available_equipment;
	
	// functie ajutatoare pt destructor (cu asta se vor dealoca listele!)
	void ClearLists();

public:
	Class();
	Class(std::string name, std::string hitDice, std::string description, int classLevel);
	Class(const Class& other);											 // copy constructor
	Class& operator=(const Class& other);                                // copy assignment operator 
	~Class();															 // destructor

	std::string GetName() const;
	std::string GetHitDice() const;
	std::string GetDescription() const;
	int GetLevel() const;

	void SetName(std::string name);
	void SetHitDice(std::string hitDice);
	void SetDescription(std::string description);
	void SetLevel(int level);

	void ShowClassDetails();
	friend std::ostream& operator << (std::ostream& cout, const Class& obj);

	// proficiencies
	void AddProficiency(std::string name);
	void ShowProficiencies() const; // Made const as it doesn't modify
	void DeleteFirstProficiency();
	void DeleteLastProficiency();
	// added for completeness if needed by copy/assignment logic, or for external use
	Proficiency* GetFirstProficiency() const { return m_first_prf; }


	// equipment
	void AddEquipment(const Equipment& item); // Pass by const reference
	void ShowEquipment() const; // Made const
	void DeleteFirstEquippedItem();
	void DeleteLastEquippedItem();
	EquippedItem* GetFirstEquippedItem() const { return m_first_equipped; }


	// abilities
	void AddAbility(const Ability& de_adaugat); // pass by const reference
	void ShowAbilities() const; // made const
	const std::vector<Ability>& GetAbilities() const { return m_vector_abilities; } // getter for abilities


	// static available equipment
	static void SetAvailableEquipment(const Equipment array[], int nr_elements); // pass array by const
	static const std::vector<Equipment>& GetAvailableEquipment(); // return const reference
	static void ShowAllAvailableEquipment();
	static Equipment GetSpecificAvailableEquipment(int contor);
};

#endif // !CLASS_H
