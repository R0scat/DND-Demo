#include <string.h>
#include <iostream>
#include "PlayerCharacter.h"
#include "DndHelper.h"

PlayerCharacter::PlayerCharacter() // constructor care creeaza un obiect cu valori nule/ placeholders
{
	Class emptyClass;
	Race emptyRace;
	this->playerName = "None";
	this->characterName = "None";
	this->characterClass[0] = emptyClass;
	this->nrClasses = 1;
	this->characterRace = emptyRace;
	this->level = 0; // placeholder, teoretic n-are niciun nivel inca
}

PlayerCharacter::PlayerCharacter(std::string playerName, std::string characterName, Class firstChosenClass, Race characterRace)
{
	this->playerName = playerName;
	this->characterName = characterName;
	this->characterClass[0] = firstChosenClass;
	this->nrClasses = 1;
	this->characterRace = characterRace;
	this->level = firstChosenClass.getLevel(); 
}

PlayerCharacter::PlayerCharacter(const PlayerCharacter& obj)
{
	this->playerName = obj.playerName;
	this->characterName = obj.characterName;
	for (int pos = 0; pos < obj.nrClasses; pos++) // pt ca e posibil sa fie mai multe clase trebuie trecute prin toate yaya
	{
		this->characterClass[pos] = obj.characterClass[pos];
	}
	this->nrClasses = obj.nrClasses;
	this->characterRace = obj.characterRace;
	this->level = obj.level;

}

PlayerCharacter::~PlayerCharacter() 
{
	char option;
	std::cout << "Character deleted, would you like to make a new one? Y/N";
	std::cin >> option;
	if (option == 'Y' || option == 'y')
	{
		std::cout << "Ok! You need to repick your class, race level, etc. if so!";
		dndHelper::pickPlayerCharacter();
	}
	else
		std::cout << "oh well ...";
}

std::string PlayerCharacter::getPlayerName()
{
	return this->playerName;
}


std::string PlayerCharacter::getCharacterName()
{
	return this->characterName;
}


Race PlayerCharacter::getCharacterRace()
{
	return this->characterRace;
}

Class PlayerCharacter::getSpecificCharacterClass(int pos)
{
	return this->characterClass[pos];
}

int PlayerCharacter::getNumberOfClasses()
{
	return this->nrClasses;
}

void PlayerCharacter::showAllCharacterClasses()
{
	for (int i = 0; i < this->nrClasses; i++)
		std::cout << this->characterClass[i];
}

void PlayerCharacter::setPlayerName(std::string name)
{
	this->playerName = name;
}

void PlayerCharacter::setCharacterName(std::string name)
{
	this->characterName = name;
}

void PlayerCharacter::addCharacterClass(Class toBeAdded)
{
	this->nrClasses++;
	this->characterClass[this->nrClasses - 1] = toBeAdded;
}


void PlayerCharacter::setCharacterRace(Race toSet)
{
	this->characterRace = toSet;
}

void PlayerCharacter::setLevel(int level)
{
	this->level = level;
}

void PlayerCharacter::showPlayerCharacterDetails()
{
	std::cout << "Player Name: " << this->playerName << "\n";
	std::cout << "Character Name: " << this->characterName << "\n";
	std::cout << "Level: " << this->level << "\n";
	std::cout << "Race details:\n" << this->characterRace << "\n";
	std::cout << "Number of Classes: " << this->nrClasses << "\n";
	std::cout << "Class Details:\n";
	for (int i = 0; i < this->nrClasses; i++)
	{
		characterClass[i].showClassDetails();
		std::cout << "\n";
	}
}

void PlayerCharacter::modifyClass(PlayerCharacter &givenCharacter, int classPos, std::string name, int level)
{
	if (name != "")
		this->characterClass[classPos].setName(name);
	if (characterClass[classPos].getLevel() == 20)
	{
		std::cout << "You have reached the maximum level for this class and so can't level it up\n";
		return;
	}
	else 
		if (level)
			this->characterClass[classPos].setLevel(this->characterClass[classPos].getLevel() + 1);
	givenCharacter.recalculateLevel(givenCharacter);
}

void PlayerCharacter::recalculateLevel(PlayerCharacter& givenCharacter)
{
	this->level = 0;
	for (int i = 0; i < this->nrClasses; i++)
		this->level += this->characterClass[i].getLevel();
}
