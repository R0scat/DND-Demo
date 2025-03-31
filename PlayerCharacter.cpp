#include <string.h>
#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() // constructor care creeaza un obiect cu valori nule/ placeholders
{
	Class emptyClass;
	Race emptyRace;
	this->playerName = "None";
	this->characterName = "None";
	this->characterClass[0] = emptyClass;
	this->nrClasses = 1;
	this->characterRace = emptyRace;
	this->level = 1; // placeholder, teoretic n-are niciun nivel inca
}

PlayerCharacter::PlayerCharacter(std::string, std::string characterName, Class firstChosenClass, Race characterRace)
{

}

PlayerCharacter::PlayerCharacter(const PlayerCharacter& obj)
{/*
	this->name = obj.name;
	this->hitDice = obj.hitDice;
	this->description = obj.description;*/
}

PlayerCharacter::~PlayerCharacter() {}

