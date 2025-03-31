#include <string.h>
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
	this->level = 1; // placeholder, teoretic n-are niciun nivel inca
}

PlayerCharacter::PlayerCharacter(std::string, std::string characterName, Class firstChosenClass, Race characterRace)
{

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

//
//std::string PlayerCharacter::getPlayerName()
//{
//	return this->playerName;
//}



