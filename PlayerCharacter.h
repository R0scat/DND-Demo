#pragma once
#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <string>
#include "Entity.h"
#include "Class.h"
#include "Race.h"



class PlayerCharacter : public Entity {
	std::string playerName;
	std::string characterName;
	Class characterClass[12];				// can multiclass up to ten classes max (ca doar atatea sunt ca idee)
	Race characterRace;
	int nrClasses;
	int level;
public:
	// constructori si destructor
	PlayerCharacter();
	PlayerCharacter(std::string playerName, std::string characterName, Class firstCharacterClass, Race characterRace);
	PlayerCharacter(const PlayerCharacter& PC);
	~PlayerCharacter();
	// gettere
	std::string getPlayerName();
	std::string getCharacterName();
	Class getSpecificCharacterClass(int pos);
	Race getCharacterRace();
	void showAllCharacterClasses();
	// settere
	void setPlayerName(std::string name);
	void setCharacterName(std::string name);
	void addCharacterClass(Class toBeAdded);// se va folosi de nrClasses pt a adauga o clasa
	void setCharacterRace(Race toSet);
	// OBS: nu poti modifica variabila de nrClasses, aceasta se modifica simultan cu clasele
	void showPlayerCharacterDetails();		// afisare tot
	void modifyClass(PlayerCharacter givenCharacter, int classPos, std::string name = "default", std::string hitDice = "default", std::string description = "default", int level = 1);			// modifica clasa aflata pe pozitia classPos
};

#endif