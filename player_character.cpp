#include <string.h>
#include <iostream>
#include "player_character.h"
#include "dnd_helper.h"

PlayerCharacter::PlayerCharacter() // constructor care creeaza un obiect cu valori nule/ placeholders
{
	Class emptyClass;
	Race emptyRace;
	this->m_player_name = "None";
	this->m_character_name = "None";
	this->m_character_class[0] = emptyClass;
	this->m_nr_classes = 1;
	this->m_character_race = emptyRace;
	this->m_level = 0; // placeholder, teoretic n-are niciun nivel inca
}

PlayerCharacter::PlayerCharacter(std::string playerName, std::string characterName, Class firstChosenClass, Race characterRace)
{
	this->m_player_name = playerName;
	this->m_character_name = characterName;
	this->m_character_class[0] = firstChosenClass;
	this->m_nr_classes = 1;
	this->m_character_race = characterRace;
	this->m_level = firstChosenClass.GetLevel();
}

PlayerCharacter::PlayerCharacter(const PlayerCharacter& obj)
{
	this->m_player_name = obj.m_player_name;
	this->m_character_name = obj.m_character_name;
	for (int pos = 0; pos < obj.m_nr_classes; pos++) // pt ca e posibil sa fie mai multe clase trebuie trecute prin toate yaya
	{
		this->m_character_class[pos] = obj.m_character_class[pos];
	}
	this->m_nr_classes = obj.m_nr_classes;
	this->m_character_race = obj.m_character_race;
	this->m_level = obj.m_level;

}

PlayerCharacter::~PlayerCharacter() 
{
	char option;
	std::cout << "Character deleted, would you like to make a new one? Y/N";
	std::cin >> option;
	if (option == 'Y' || option == 'y')
	{
		std::cout << "Ok! You need to repick your class, race level, etc. if so!";
		Dnd_Helper::PickPlayerCharacter();
	}
	else
		std::cout << "oh well ...";
}

std::string PlayerCharacter::GetPlayerName()
{
	return this->m_player_name;
}


std::string PlayerCharacter::GetCharacterName()
{
	return this->m_character_name;
}


Race PlayerCharacter::GetCharacterRace()
{
	return this->m_character_race;
}

Class PlayerCharacter::GetSpecificCharacterClass(int pos)
{
	return this->m_character_class[pos];
}

int PlayerCharacter::GetNumberOfClasses()
{
	return this->m_nr_classes;
}

void PlayerCharacter::ShowAllCharacterClasses()
{
	for (int i = 0; i < this->m_nr_classes; i++)
		std::cout << this->m_character_class[i];
}

void PlayerCharacter::SetPlayerName(std::string name)
{
	this->m_player_name = name;
}

void PlayerCharacter::SetCharacterName(std::string name)
{
	this->m_character_name = name;
}

void PlayerCharacter::AddCharacterClass(Class toBeAdded)
{
	this->m_nr_classes++;
	this->m_character_class[this->m_nr_classes - 1] = toBeAdded;
}


void PlayerCharacter::SetCharacterRace(Race toSet)
{
	this->m_character_race = toSet;
}

void PlayerCharacter::SetLevel(int level)
{
	this->m_level = level;
}

void PlayerCharacter::ShowPlayerCharacterDetails()
{
	std::cout << "Player Name: " << this->m_player_name << "\n";
	std::cout << "Character Name: " << this->m_character_name << "\n";
	std::cout << "Level: " << this->m_level << "\n";
	std::cout << "Race details:\n" << this->m_character_race << "\n";
	std::cout << "Number of Classes: " << this->m_nr_classes << "\n";
	std::cout << "Class Details:\n";
	for (int i = 0; i < this->m_nr_classes; i++)
	{
		m_character_class[i].ShowClassDetails();
		std::cout << "\n";
	}
}

void PlayerCharacter::ModifyClass(PlayerCharacter &givenCharacter, int classPos, std::string name, int level)
{
	if (name != "")
		this->m_character_class[classPos].SetName(name);
	if (m_character_class[classPos].GetLevel() == 20)
	{
		std::cout << "You have reached the maximum level for this class and so can't level it up\n";
		return;
	}
	else 
		if (level)
			this->m_character_class[classPos].SetLevel(this->m_character_class[classPos].GetLevel() + 1);
	givenCharacter.RecalculateLevel(givenCharacter);
}

void PlayerCharacter::RecalculateLevel(PlayerCharacter& givenCharacter)
{
	this->m_level = 0;
	for (int i = 0; i < this->m_nr_classes; i++)
		this->m_level += this->m_character_class[i].GetLevel();
}

void PlayerCharacter::SetCharacterStats(int str, int dex, int con, int intl, int wis, int chars)
{
	this->m_character_details.stats.strength = str;
	this->m_character_details.stats.dexterity = dex;
	this->m_character_details.stats.constitution = con;
	this->m_character_details.stats.charisma = chars;
	this->m_character_details.stats.intelligence = intl;
	this->m_character_details.stats.wisdom = wis;
}

void PlayerCharacter::CalculateSkillBonuses()
{

}