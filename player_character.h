#pragma once
#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <string>
#include "entity.h"
#include "class.h"
#include "race.h"
//#include "ieffect.h"


class PlayerCharacter : public Entity {
	std::string m_player_name;
	std::string m_character_name;
	Class m_character_class[12];				// can multiclass up to ten classes max (ca doar atatea sunt ca idee)
	Race m_character_race;
	//CharacterDetails m_character_details;	// structura care contine detalii despre caracter (stats, skills, proficiencies, saving throws, hp)
	int m_nr_classes;
	int m_level;
public:
	// constructori si destructor
	PlayerCharacter();
	PlayerCharacter(std::string playerName, std::string characterName, Class& firstCharacterClass, Race characterRace);
	PlayerCharacter(const PlayerCharacter& PC);
	~PlayerCharacter();
	// gettere
	std::string GetPlayerName() const;
	std::string GetCharacterName() const;
	Class GetSpecificCharacterClass(int pos) const; // de la 0 btw
	Race GetCharacterRace() const;
	int GetNumberOfClasses() const;
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

	// override functie din entity
	int CalculateAbilityStrenghts() override;
	void InputMessage() override;
	// debug function
	/*void AddFirstClass(Class& de_adaugat);
	Class GetFirstClass();*/

	// vector debug function
	/*void AddClassToVector(Class de_adaugat);
	Class ReturnSpecificClass(int pos);*/
};

#endif