#pragma once
#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <string>
#include "entity.h"
#include "class.h"
#include "race.h"

#include "ieffect.h"

struct Stats { // will keep the actual number like 13 st, 14 cha lalala
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
};

//struct Skills { // calculating (according to chosen proficiencies) the bonus to those rolls
//	int acrobatics;
//	int animalHandling;
//	int arcana;
//	int athletics;
//	int deception;
//	int history;
//	int insight;
//	int intimidation;
//	int investigation;
//	int medicine;
//	int nature;
//	int perception;
//	int performance;
//	int persuasion;
//	int religion;
//	int sleightOfHand;
//	int stealth;
//	int survival;
//};

struct Skill
{
	char name[50]; // nume skill
	char statType[50]; // tipul skill-ului (str, dex, int, wis, cha)
	int bonus;   // asta e gen +2 la arcana sau + 4 perception-ul in sine
	bool proficient; // true sau false, daca e true se adauga proficiency bonusul
	bool expert; // same thing cu proficient doar ca mai adauga bonusul o data
	int nr; // pastreaza de cate ori a fost adaugat numarul la skill
};

struct SavingThrows { // will be calculated from stats + should be modified by FIRST chosen class 
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
};

struct CharacterDetails // pun toate astea intr-un singru struct INAINTE sa le pun in clasa PlayerCharacter pt ca pare mai organizat
{ 
	Stats stats;
	Skill skills[18]; // sunt mereu aceleasi skil-uri deci nu are sens sa le pun intr- strctura de date dinamica (cum e lista de proficiencies)
	SavingThrows saving_throws;
	int total_hp;
	int current_hp;
	int level;
};

class PlayerCharacter : public Entity, public IEffect {
	std::string m_player_name;
	std::string m_character_name;
	Class m_character_class[12];				// can multiclass up to ten classes max (ca doar atatea sunt ca idee)
	Race m_character_race;
	CharacterDetails m_character_details;	// structura care contine detalii despre caracter (stats, skills, proficiencies, saving throws, hp)
	int m_nr_classes;
	int m_level;
public:
	// constructori si destructor
	PlayerCharacter();
	PlayerCharacter(std::string playerName, std::string characterName, Class firstCharacterClass, Race characterRace);
	PlayerCharacter(const PlayerCharacter& PC);
	~PlayerCharacter();
	// gettere
	std::string GetPlayerName();
	std::string GetCharacterName();
	Class GetSpecificCharacterClass(int pos);
	Race GetCharacterRace();
	int GetNumberOfClasses();
	void ShowAllCharacterClasses();
	// settere
	void SetPlayerName(std::string name);
	void SetCharacterName(std::string name);
	void AddCharacterClass(Class toBeAdded);		// se va folosi de nrClasses pt a adauga o clasa
	void SetCharacterRace(Race toSet);
	void SetLevel(int level);
	void SetCharacterStats(int str, int dex, int con, int intl, int wis, int chars); // sets base stats
	// OBS: nu poti modifica variabila de nrClasses, aceasta se modifica simultan cu clasele
	void ShowPlayerCharacterDetails();				// afisare tot
	void ModifyClass(PlayerCharacter& givenCharacter, int classPos, std::string name = "", int level = 0);			// modifica clasa aflata pe pozitia classPos
	void RecalculateLevel(PlayerCharacter &givenCharacter);
	void CalculateSkillBonuses(); 
	// schimba o clasa din vectorul chosenClass al structurii PlayercCharacter, valorile sunt date default si modifica clasa doar atunci cand sunt introduse valori noi
	// override functii virtuale --
	void Apply() override;
	void Remove() override;
};

#endif