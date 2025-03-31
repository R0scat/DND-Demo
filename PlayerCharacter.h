#ifndef PLAYERCHARACTER_H
#define PLAYERCHACTER_H

#pragma once
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
	Class getCharacterClasses();
	Race getCharacterRaces();
	// settere
	void setPlayerName();
	void setCharacterName();
	void addCharacterClass();				// se va folosi de nrClasses pt a adauga o clasa
	void setCharacterRace();
	// OBS: nu poti modifica variabila de nrClasses, aceasta se modifica simultan cu clasele
	void showPlayerCharacterDetails();		// afisare tot
	void modifyClass(int classPos);			// modifica clasa aflata pe pozitia classPos
};

#endif