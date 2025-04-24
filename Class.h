#pragma once
#ifndef CLASS_H
#define CLASS_H

#include <string>
//#include "player_character.h"

struct SpellAtributes { // for spellcasting classes, will be calculated from stats 
	int spell_save_dc;
	int spell_attack_bonus;
	int number_of_spells;
};

struct SpellSlots { // keeps track of the number of spell slots available for each level FOR THE CURRENT CHARAXTER (aka determined by class level)
	int first_lvl;
	int second_lvl;
	int third_lvl;
	int fourth_lvl;
	int fifth_lvl;
	int sixth_lvl;
	int seventh_lvl;
	int eighth_lvl;
	int ninth_lvl;
};

//struct Proficiencies
//{ // given by chosen class
//	// true or false for most of these except the tools since the theyre actual objects not a specific type of thing
//	bool lightArmor;
//	bool mediumArmor;
//	bool heavyArmor;
//	bool shields;
//	bool simpleWeapons;
//	bool martialWeapons;
//	std::string tools;
//};

// lista dinamica de proficiencies (fiind mai multe si diferite in functie de clasa e mai bine decat sa aloc un anumit numar lowk random)
struct Proficiency
{
	char name[50];
	Proficiency* next;
};

struct ClassBonus
{
	
};

class Class {
	std::string m_name;
	std::string m_hit_dice;
	std::string m_description;
	int m_class_level;
	Proficiency* m_first_prf;
	Proficiency* m_last_prf;

public:
	Class();															     // constructor simplu clasa
	Class(std::string name, std::string hitDice, std::string description, int classLevel);   // constructor parametrii OBS: nu sunt citite proficiency-urile, asta se va face doar printr-o metoda separata
	Class(const Class& obj);											     // constructor copiere
	~Class();															     // destructor
	std::string GetName();												     // getter nume -> returneaza numele
	std::string GetHitDice();											     // getter hd ---> returneaza hit dice-ul
	std::string GetDescription();										     // getter desc -> returneaza desc
	int GetLevel();														     // getter lvl --> returneaza level-ul
	void SetName(std::string name);										     // setter nume
	void SetHitDice(std::string hitDice);								     // setter hd
	void SetDescription(std::string description);						     // setter desc
	void SetLevel(int level);											     // setter lvl + verifica daca valoarea e valida (intre 1 si 20 momentan)
	void ShowClassDetails();											     // afiseaza toate detaliile clasei cu mesaj frumos <3
	friend std::ostream& operator << (std::ostream& cout, const Class& obj); // overload pt operatorul "<<"
	// urm functiile care lucreaza pe lista dinamic alocata de proficiencies
	void AddProficiency(char name[50]);
	void ShowProficiencies();
	void DeleteFirstProficiency();
	void DeleteLastProficiency();
};


#endif // !CLASS_H