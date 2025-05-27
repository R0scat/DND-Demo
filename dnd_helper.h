#pragma once
#ifndef DNDHELPER_H
#define DNDHELPER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "class.h"
#include "race.h"
#include "player_character.h"
#include "ability.h"
#include "equipment.h"
#include "atribute_helper.h"

namespace Dnd_Helper {
    inline void ClearScreen()
    {
        std::cin.get();
        system("cls");
    }

    inline void PickClassMessage() { // mesajul dat la inceput de tot 

        std::cout << "Pick a class:\n";
        std::cout << "1.  Paladin\n";
        std::cout << "2.  Wizard\n";
        std::cout << "3.  Rogue\n";
        std::cout << "4.  Sorcerer\n";
        std::cout << "5.  Druid\n";
        std::cout << "6.  Warlock\n";
        std::cout << "7.  Fighter\n";
        std::cout << "8.  Barbarian\n";
        std::cout << "9.  Articifer\n";
        std::cout << "10. Cleric\n";
        std::cout << "11. Monk\n";
        std::cout << "12. Bard\n";
    }

    inline void PickRaceMessage() { // mesaj dat pt afisare alegere neam/ rasa

        std::cout << "Great! Now chose your race :P\n";
        std::cout << "1. Human\n";
        std::cout << "2. Elf\n";
        std::cout << "3. Dwarf\n";
        std::cout << "4. Halfling\n";
        std::cout << "5. Dragonborn\n";
		std::cout << "6. Half-Elf\n";
		std::cout << "7. Fairy\n";
		std::cout << "8. Tiefling\n";
    }

    inline int CheckIfNumber(char option_string[50])
    {
        int nr[10], len = 0, option = 0;
        for (int i = 0; i < strlen(option_string); i++)
        {
            if (strchr("0123456789", option_string[i]) != NULL) // verifica daca e printre cifre
            {
				nr[len] = int(option_string[i] - '0'); // converteste in int
                len++;
            }
        }
        if (len == 0)
            return NULL; // returneaza null daca  nu e numar
        else
        {
			for (int i = 0; i < len; i++)
			{
				option = nr[i] + option * 10;
			}
           // std::cout << option; // debug
            return option; // retunreaza nr ales
        }
        
    }

    inline void ConvertStringToFormat(char option_string[50])
    {
        for (int i = 0; i < strlen(option_string); i++)
            if (option_string[i] >= 'A' && option_string[i] <= 'Z')
                option_string[i] += 'a' - 'A';
    }

    inline int MakeInt(char option_string[50], int class_or_race) // class = 1; race = 2
    {
        char choises[12][40];
        Dnd_Helper::ConvertStringToFormat(option_string);
        //std::cout << "\n" << optionString << "\n";    // cod pt debug 
        if (class_or_race == 1) // verifica daca tre sa caute printre clase
        {
            std::ifstream fin("resources/class_names.txt");
            for (int i = 0; i < 12; i++) // for pt a face matricea de char pt clase 
                fin >> choises[i];
            for (int i = 0; i < 12; i++)
                if (strstr(option_string, choises[i]) != NULL)
                    return i + 1; // sunt puse in ordinea din mesajul dat, deci se returneaza pozitia + 1 (indexare de la 0)
        }
		else if (class_or_race == 2) // verifica daca tre sa caute printre rase
		{
			std::ifstream fin("resources/race_names.txt");
			for (int i = 0; i < 8; i++) // for pt a face matricea de char pt rase 
				fin >> choises[i];
            for (int i = 0; i < 8; i++)
                if (strstr(option_string, choises[i]) != NULL)
                    return i + 1;
		}
        return 0;
    }

    inline int ParseMessage(char option_string[50], int class_or_race)
    {
        int optionInt;

        if (Dnd_Helper::CheckIfNumber(option_string) == NULL)
            optionInt = Dnd_Helper::MakeInt(option_string, class_or_race); // cazul in care au introdus an entire ass word! lmao
        else
            optionInt = CheckIfNumber(option_string);
        return optionInt;
    }

    inline Class PickClass(int option) {// big switch case for every available class lol - de la 1 la 12

        int lvl, option_int;
		Class chosen_class;
        char option_string[50];
        switch (option)
        {

        case 1: // paladin
        {
            chosen_class.SetName("paladin");
            chosen_class.SetHitDice("1d10");
            chosen_class.SetDescription("A holy warrior bound to a sacred oath");
            break;
        }
        case 2: // wizard 
        {
            chosen_class.SetName("wizard");
            chosen_class.SetHitDice("1d6");
            chosen_class.SetDescription("A scholarly magic-user capable of manipulating reality");
            break;
        }
        case 3: // rogue
        {
            chosen_class.SetName("rogue");
            chosen_class.SetHitDice("1d8");
            chosen_class.SetDescription("A scoundrel who uses stealth and trickery to overcome obstacles and enemies");
            break;
        
        }
        case 4: // sorcerer
        {
            chosen_class.SetName("sorcerer");
            chosen_class.SetHitDice("1d6");
            chosen_class.SetDescription("A spellcaster who draws on inherent magic from a gift or bloodline");
            break;

        }
        case 5: // druid 
        {
            chosen_class.SetName("druid");
            chosen_class.SetHitDice("1d8");
            chosen_class.SetDescription("A priest of the Old Faith, wielding the powers of nature and adopting animal forms");
            break;
        }
        case 6: // warlock
        {
            chosen_class.SetName("warlock");
            chosen_class.SetHitDice("1d8");
            chosen_class.SetDescription("A wielder of magic that is derived from a bargain with an extraplanar entity");
            break;
        }
        case 7: // fighter
        {
            chosen_class.SetName("fighter");
            chosen_class.SetHitDice("1d10");
            chosen_class.SetDescription("A master of martial combat, skilled with a variety of weapons and armor");
            break;
        }
        case 8: // barbarian
        {
            chosen_class.SetName("barbarian");
            chosen_class.SetHitDice("1d12");
            chosen_class.SetDescription("A fierce warrior of primitive background who can enter a battle rage");
            break;
        }
        case 9: // artificer
        {
            chosen_class.SetName("artificer");
            chosen_class.SetHitDice("1d8");
            chosen_class.SetDescription("A master of invention, artificers use ingenuity and magic to unlock extraordinary capabilities in objects");
            break;
        }
        case 10: // cleric
        {
            chosen_class.SetName("cleric");
            chosen_class.SetHitDice("1d8");
            chosen_class.SetDescription("A priestly champion who wields divine magic in service of a higher power");
            break;
        }
        case 11: // monk
        {
            chosen_class.SetName("monk");
            chosen_class.SetHitDice("1d8");
            chosen_class.SetDescription("A master of martial arts, harnessing the power of the body in pursuit of physical and spiritual perfection");
            break;
        }
        case 12: // bard
        {
            chosen_class.SetName("bard");
            chosen_class.SetHitDice("1d8");
            chosen_class.SetDescription("An inspiring magician whose power echoes the music of creation");
            break;
        }
        default: // functia se reapeleaza daca optiunea e invalida
        {
            std::cout << "Option invalid, try again?\n";
            std::cin.getline(option_string, 51);
			option_int = Dnd_Helper::ParseMessage(option_string, 1); // pt clasa parseaza cu 1; pt rasa cu 2
			//std::cout << optionString << std::endl;  // linie de debug
            chosen_class = Dnd_Helper::PickClass(option_int);
        }

        }
        return chosen_class;
    }

    inline Race PickRace(int option) // returneaza race-ul corect ales de utilizator
    {
		int option_int;
        char option_string[51];
		Race chosen_race;
        switch (option)
        {

        case 1: // human 
        {
            chosen_race.SetName("Human");
            chosen_race.SetDescription("Found throughout the multiverse, humans are as varied as they are numerous.");
            break;
        }
        case 2: // elf
        {
            chosen_race.SetName("Elf");
            chosen_race.SetDescription("The elves’ curiosity led many of them to explore other planes of existence.");
            break;
        }
        case 3: // dwarf
        {
            chosen_race.SetName("Dwarf");
            chosen_race.SetDescription("Dwarves were raised from the earth in the elder days by a deity of the forge.");
            break;
        }
        case 4: // halfling
        {
            chosen_race.SetName("Halfling");
            chosen_race.SetDescription("Halflings possess a brave and adventurous spirit that leads them on journeys of discovery.");
            break;
        }
        case 5: // dragonborn
        {
            chosen_race.SetName("Dragonborn");
            chosen_race.SetDescription("The ancestors of dragonborn hatched from the eggs of chromatic and metallic dragons.");
            break;
        }
        case 6: // half-elf
        {
            chosen_race.SetName("Half-Elf");
            chosen_race.SetDescription("");
            break;
        }
        case 7: // fairy
        {
            chosen_race.SetName("Fairy");
            chosen_race.SetDescription("Infused with the magic of the Feywild, most fairies look like Small elves with insectile wings, but each fairy has a special physical characteristic that sets the fairy apart.");
            break;
        }
        case 8: // tiefling
        {
            chosen_race.SetName("Tiefling");
            chosen_race.SetDescription("Tieflings are either born in the Lower Planes or have fiendish ancestors who originated there.");
            break;
        }
        default: // cand nu introduce o valoare existenta
        {
            std::cout << "Option not available, try again?\n";
            //std::cin.get();
            std::cin.getline(option_string, 51);
            option_int = Dnd_Helper::ParseMessage(option_string, 2);
            chosen_race = Dnd_Helper::PickRace(option_int);
        }

        }
        return chosen_race;
    }

    inline void PickPlayerCharacter() // just chooses and creates the PC, IF YOU WANT TO DISPLAY ATRIBUTES USE THE CLASS FUNCTION!!!
    {
        int option_int, lvl;
        char option_string[51];
        Class chosen_class;
        Race chosen_race;

        Dnd_Helper::PickClassMessage();
        std::cin.get();
        std::cin.getline(option_string, 51);
		option_int = Dnd_Helper::ParseMessage(option_string, 1);
        chosen_class = Dnd_Helper::PickClass(option_int);

        std::cout << "Now, choose your level (reminder: unless multi-classing, your character can be at most lvl 20)\n";
        std::cin >> lvl;
        chosen_class.SetLevel(lvl);

        Dnd_Helper::PickRaceMessage();
        std::cin.get();
        std::cin.getline(option_string, 51);
        option_int = Dnd_Helper::ParseMessage(option_string, 2);
        chosen_race = Dnd_Helper::PickRace(option_int);
    }

    inline void Menu()
    {
        std::cout << "|============================================================================\n";
        std::cout << "| Your character details have all been set up, what would you like to do?   |\n";
        std::cout << "| 1. show basic character details                                           |\n";
        std::cout << "| 2. add another class                                                      |\n";
        std::cout << "| 3. show equipment                                                         |\n";
        std::cout << "| 4. show abilities                                                         |\n";
        std::cout << "| 5. show proficiencies                                                     |\n";
        std::cout << "| 6. level up                                                               |\n";
        std::cout << "| 7. change character stats (e.g. strenght, charisma ...)                   |\n";
        std::cout << "| 8. change ability proficiency (e.g. arcana, history, perception ...)    |\n";
        std::cout << "| 9. show in depth character details (ability scores, bonuses etc.)         |\n";
        std::cout << "| 10. quit (deleting the character...)                                      |\n";
        std::cout << "|============================================================================\n";
    }

	inline void MenuPicker(int option, int &ongoing, PlayerCharacter &pc)
	{
        char option_string[50];
        int option_int;
        Class chosen_class;
        Dnd_Helper::ClearScreen();

		switch (option)
		{
		case 1:
			pc.ShowPlayerCharacterDetails();
			break;
		case 2:
        {
            std::cout << "Adding another class...\n\n";
            Dnd_Helper::PickClassMessage();
            std::cin.getline(option_string, 51);
			option_int = Dnd_Helper::ParseMessage(option_string, 1);
			chosen_class = Dnd_Helper::PickClass(option_int);
            std::cout << chosen_class << std::endl;

            //populate class atributes
            Atribute_Helper::ReadAtributes(chosen_class);

            // set the class level
            std::cout << "Choose level for this class (total character level will be equal to the sum of thhe two classes)\n";
			std::cin >> option_int;
			chosen_class.SetLevel(option_int);
	
			pc.AddCharacterClass(chosen_class);
            pc.RecalculateLevel(pc);
            break;
        }
		case 3:
			std::cout << "Showing all equipment:\n\n";
            for (int i = 0; i < pc.GetNumberOfClasses(); i++)
            {
                std::cout << "=================================\n";
                std::cout << "Currently showing " << pc.GetSpecificCharacterClass(i).GetName() << " items: \n";
                pc.GetSpecificCharacterClass(i).ShowEquipment();
            }
            std::cout << "=================================\n";
            break;
		case 4:
			std::cout << "Showing all abilities:\n\n";
            // taking each class from the class array and showing abilities
            for (int i = 0; i < pc.GetNumberOfClasses(); i++)
            {
                std::cout << "=================================\n";
                std::cout << "Currently showing " << pc.GetSpecificCharacterClass(i).GetName() << " abilities: \n";
                pc.GetSpecificCharacterClass(i).ShowAbilities();
            }
            std::cout << "=================================\n";
            break;
		case 5:
			std::cout << "Showing all proficiencies: \n\n";
            for (int i = 0; i < pc.GetNumberOfClasses(); i++)
            {
                std::cout << "=================================\n";
                std::cout << "Currently showing " << pc.GetSpecificCharacterClass(i).GetName() << " proficiencies: \n";
                pc.GetSpecificCharacterClass(i).ShowProficiencies();
            }
            std::cout << "=================================\n";
            break;
		case 6:
        {
            int class_nr;
            if (pc.GetNumberOfClasses() != 1)
            {
                std::cout << "Please select the class index that you'd like to level up\n";
                std::cin >> class_nr;
                pc.ModifyClass(pc, class_nr - 1, "", 1);
            }
            else
            {
                std::cout << "Leveling up!!\n";
                pc.ModifyClass(pc, 0, "", 1);
            }
            break;
        }
		case 7:
        {
            // metoda a entitatii - ia un input si modifica stat urile accordingly
            pc.ChangeCharacterStats();
            break;
        }
        case 8:
        {
            char prf_name[50];
            std::cout << "Input stat proficiency you would like to change: \n";
            std::cin >> prf_name;
            pc.ChangeGivenProficiency(prf_name);
            break;
        }
        case 9:
        {
            std::cout << pc;
            break;
        }
        case 10:
        {
            std::cout << "Quitting...\n";
            ongoing = 0;
            break;
        }
        default:
        {
            std::cout << "Invalid option, try again!\n";
            std::cin >> option;
            Dnd_Helper::MenuPicker(option, ongoing, pc);
            break;
        }
		}
	}
}


#endif // !DNDHELPER
