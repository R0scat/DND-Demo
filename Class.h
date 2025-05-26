#pragma once
#ifndef CLASS_H
#define CLASS_H

#include <string>
#include "equipment.h"
#include <vector>
#include "ability.h"
//#include "player_character.h"

//struct SpellAtributes { // for spellcasting classes, will be calculated from stats 
//	int spell_save_dc;
//	int spell_attack_bonus;
//	int number_of_spells;
//};
//
//struct SpellSlots { // keeps track of the number of spell slots available for each level FOR THE CURRENT CHARAXTER (aka determined by class level)
//	int first_lvl;
//	int second_lvl;
//	int third_lvl;
//	int fourth_lvl;
//	int fifth_lvl;
//	int sixth_lvl;
//	int seventh_lvl;
//	int eighth_lvl;
//	int ninth_lvl;
//};

// lista dinamica de proficiencies (fiind mai multe si diferite in functie de clasa e mai bine decat sa aloc un anumit numar lowk random)
struct Proficiency
{
	std::string name;
	Proficiency* next;
};


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
	Proficiency* m_first_prf;
	Proficiency* m_last_prf;
	EquippedItem* m_first_equipped;
	EquippedItem* m_last_equipped;
	std::vector<Ability> m_vector_abilities;
	static std::vector<Equipment> m_available_equipment;
	static int m_total_equipment;

public:
	Class();															     // constructor simplu clasa
	Class(std::string name, std::string hitDice, std::string description, int classLevel);   // constructor parametrii OBS: nu sunt citite proficiency-urile, asta se va face doar printr-o metoda separata
	Class(const Class& obj);											     // constructor copiere
	~Class();															     // destructor
	std::string GetName() const;												     // getter nume -> returneaza numele
	std::string GetHitDice() const;											     // getter hd ---> returneaza hit dice-ul
	std::string GetDescription() const;										     // getter desc -> returneaza desc
	int GetLevel() const;														     // getter lvl --> returneaza level-ul
	void SetName(std::string name);										     // setter nume
	void SetHitDice(std::string hitDice);								     // setter hd
	void SetDescription(std::string description);						     // setter desc
	void SetLevel(int level);											     // setter lvl + verifica daca valoarea e valida (intre 1 si 20 momentan)
	void ShowClassDetails();											     // afiseaza toate detaliile clasei cu mesaj frumos <3
	friend std::ostream& operator << (std::ostream& cout, const Class& obj); // overload pt operatorul "<<"
	// urm functiile care lucreaza pe lista dinamic alocata de proficiencies
	void AddProficiency(std::string name);
	void ShowProficiencies();
	void DeleteFirstProficiency();
	void DeleteLastProficiency();
	// functii pt echipament (lista dinamica)
	void AddEquipment(Equipment item);
	void ShowEquipment();
	void DeleteFirstEquippedItem();
	void DeleteLastEquippedItem();
	// functie pt vectorul de abilitati
	void AddAbility(Ability de_adaugat);
	void ShowAbilities();
	//std::vector<Ability> GetAbilities(); 
	// functii pt variabila statica m_available_equipment
	static void SetAvailableEquipment(Equipment array[100], int nr_elements);
	static std::vector<Equipment> GetAvailableEquipment();
	static void ShowAllAvailableEquipment();
	static Equipment GetSpecificAvailableEquipment(int contor);
};

#endif // !CLASS_H