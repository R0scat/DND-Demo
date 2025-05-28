#pragma once
#ifndef DMHELPER_H
#define DMHELPER_H

#include <iostream>
#include "creature.h"
#include "player_character.h"
#include "entity_manager.h"
#include <cstdlib>
#include <time.h>
#include <windows.h>

namespace DM_Helper {
	inline void RollDiceMessage()
	{
		std::cout << "What kind of dice do you want to roll?\n";
		std::cout << "1. 1d4\n";
		std::cout << "2. 1d6\n";
		std::cout << "3. 1d8\n";
		std::cout << "4. 1d10\n";
		std::cout << "5. 1d12\n";
		std::cout << "6. 1d20\n";
	}

	inline int ChooseDice(int option)
	{
		if (option == 1)
			return 4;
		if (option == 2)
			return 6;
		if (option == 3)
			return 8;
		if (option == 4)
			return 10;
		if (option == 5)
			return 12;
		if (option == 6)
			return 20;
		std::cout << "Option unavailable... :(\nTry another input:\n";
		std::cin >> option;
		ChooseDice(option);
	}

	inline void RollDice(int option)
	{
		int zar = ChooseDice(option); 
		int output_value;

		srand(time(0));
		output_value = (rand() % zar) + 1; // aici se calculeaza propriu-zis valoarea

		for (int i = 1; i <= 3; i++)
		{
			std::cout << "Rolling...\n\n";
			Sleep(1250); //1,25 seconde de stall
		}

		std::cout << "Dice rolled!! The value you are looking for is: " << output_value << "\n";
	}

	inline void RollDiceMenu()
	{
		int option;
		RollDiceMessage();
		std::cin >> option;
		RollDice(option);
	}

	inline void ShowDmMenu()
	{
		std::cout << "Dungeon Master settings:\n";
		std::cout << "1. create a creature\n";
		std::cout << "2. create a character\n";
		std::cout << "3. show all entities\n";
		std::cout << "4. calculate strenghts for all entities\n";
		std::cout << "5. apply effect on given entity\n";
		std::cout << "6. roll dice menu\n";
		std::cout << "7. exit\n";
	}

	inline void DmMenuPicker(int option, bool &ongoing)
	{
		Dnd_Helper::ClearScreen();

		switch (option)
		{
		case 1:
		{
			std::string type;
			std::cout << "Input what type this creature will be: \n";
			std::cin >> type;

			Creature* made_creature = new Creature();
			made_creature->SetType(type);

			Entity* entity_ptr = made_creature;
			EntityManager::AddEntity(entity_ptr); 

			break;
		}
		case 2:
		{
			// analog start PlayerMode
			char option_string[256];
			int option_int, lvl;
			std::string character_name, username = "Dungeon Master";
			Class chosen_class;
			Race chosen_race;

			Dnd_Helper::PickClassMessage();
			std::cin.getline(option_string, 256);
			option_int = Dnd_Helper::ParseMessage(option_string, 1);
			chosen_class = Dnd_Helper::PickClass(option_int);

			Atribute_Helper::ReadAtributes(chosen_class);

			std::cout << "Choose character level: \n";
			std::cin >> lvl;
			chosen_class.SetLevel(lvl);

			std::cin.get();

			Dnd_Helper::PickRaceMessage();
			std::cin.getline(option_string, 256);
			option_int = Dnd_Helper::ParseMessage(option_string, 2);
			chosen_race = Dnd_Helper::PickRace(option_int);

			std::cout << "What will this character be called?";
			std::getline(std::cin, character_name); // aici se ia numele personajului

			Entity* new_entity = new PlayerCharacter(username, character_name, chosen_class, chosen_race);

			EntityManager::AddEntity(new_entity);

			break;
		}
		case 3:
		{
			EntityManager::ShowAllEntities();
			break;
		}
		case 4:
		{
			int index = 0;
			for (Entity* current_entity : EntityManager::GetEntityVector())
			{
				std::cout << "For entity number " << ++index << " their strenghts indicator is: ";

				std::cout << current_entity->CalculateAbilityStrenghts();

				std::cout << "\n";

			}
			break;
		}
		case 5:
		{
			int index;

			std::string effect_name, effect_desc;
			std::cout << "To apply an effect you must first give it a name and a description.\nInput effect name:\n";
			std::cin >> effect_name;
			std::cout << "Input effect description:\n";
			std::cin >> effect_desc;

			Effect made_effect;
			made_effect.name = effect_name;
			made_effect.description = effect_desc;
			std::cout << "Effect created!\nNow choose what entity you want the effect to be applied to (introduce it's index number):\n";
			std::cin >> index;

			//std::cout << EntityManager::GetEntityVector().size() << "\n";
			
			if (EntityManager::GetEntityVector().size() >= index)
			{
				EntityManager::GetSpecificEntity(index - 1)->Apply(made_effect);
				std::cout << "Effect applied!\n";
			}
			else
				std::cout << "No such entity exists, try another input or creating a new one?\n";
			break;
		}
		case 6:
		{
			RollDiceMenu();
			break;
		}
		case 7:
		{
			std::cout << "Quitting...";
			ongoing = false;
			break;
		}
		default:
		{
			std::cout << "Option unavailable, try another input?";
			std::cin >> option;
			DmMenuPicker(option, ongoing);
			break;
		}
			
		}
	}
}

#endif // !DMHELPER_H
