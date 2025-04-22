#pragma once
#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <string>
#include "entity.h"
#include "class.h"
#include "race.h"

struct Stats { // will keep the actual number like 13 st, 14 cha lalala
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
};

struct Skills { // calculating (according to chosen proficiencies) the bonus to those rolls
	int acrobatics;
	int animalHandling;
	int arcana;
	int athletics;
	int deception;
	int history;
	int insight;
	int intimidation;
	int investigation;
	int medicine;
	int nature;
	int perception;
	int performance;
	int persuasion;
	int religion;
	int sleightOfHand;
	int stealth;
	int survival;
};

struct Proficiencies { // given by chosen class
	// true or false for most of these except the tools since the tools are objects not a specific type of object
	bool lightArmor;
	bool mediumArmor;
	bool heavyArmor;
	bool shields;
	bool simpleWeapons;
	bool martialWeapons;
	std::string tools;
};

struct CharacterDetails
{ 
	Stats stats;
	Skills skills;
	Proficiencies proficiencies;
	int total_hp;
	int current_hp;
	int level;
};

class PlayerCharacter : public Entity {
	std::string m_player_name;
	std::string m_character_name;
	Class m_character_class[12];				// can multiclass up to ten classes max (ca doar atatea sunt ca idee)
	Race m_character_race;
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
	// OBS: nu poti modifica variabila de nrClasses, aceasta se modifica simultan cu clasele
	void ShowPlayerCharacterDetails();				// afisare tot
	void ModifyClass(PlayerCharacter& givenCharacter, int classPos, std::string name = "", int level = 0);			// modifica clasa aflata pe pozitia classPos
	void RecalculateLevel(PlayerCharacter &givenCharacter);
	// schimba o clasa din vectorul chosenClass al structurii PlayercCharacter, valorile sunt date default si modifica clasa doar atunci cand sunt introduse valori noi
};

#endif