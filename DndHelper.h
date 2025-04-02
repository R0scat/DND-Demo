#pragma once
#ifndef DNDHELPER_H
#define DNDHELPER_H

#include <iostream>
#include "Class.h"
#include "Race.h"

namespace dndHelper {
    inline void pickClassMessage() { // mesajul dat la inceput de tot 

        std::cout << "Pick your class:\n";
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

    inline void pickRaceMessage() { // mesaj dat pt afisare alegere neam/ rasa

        std::cout << "Great! Now chose your race :P\n";
        std::cout << "1. Human\n";
        std::cout << "2. Elf\n";
        std::cout << "3. Dragonborn\n";
        std::cout << "4. Halfling\n";
        std::cout << "5. Gnome\n";
		std::cout << "6. Half-Elf\n";
		std::cout << "7. Fairy\n";
		std::cout << "8. Tiefling\n";
    }

    inline Class pickClass(int option) {// big switch case for every available class lol - de la 1 la 12

        int lvl;
		Class chosenClass;
        switch (option)
        {

        case 1: // paladin
        {
            chosenClass.setName("Paladin");
            chosenClass.setHitDice("1d10");
            chosenClass.setDescription("A holy warrior bound to a sacred oath");
            break;
        }
        case 2: // wizard 
        {
            chosenClass.setName("Wizard");
            chosenClass.setHitDice("1d6");
            chosenClass.setDescription("A scholarly magic-user capable of manipulating reality");
            break;
        }
        case 3: // rogue
        {
            chosenClass.setName("Rogue");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A scoundrel who uses stealth and trickery to overcome obstacles and enemies");
            break;
        
        }
        case 4: // sorcerer
        {
            chosenClass.setName("Sorcerer");
            chosenClass.setHitDice("1d6");
            chosenClass.setDescription("A spellcaster who draws on inherent magic from a gift or bloodline");
            break;

        }
        case 5: // druid 
        {
            chosenClass.setName("Druid");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A priest of the Old Faith, wielding the powers of nature and adopting animal forms");
            break;
        }
        case 6: // warlock
        {
            chosenClass.setName("Warlock");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A wielder of magic that is derived from a bargain with an extraplanar entity");
            break;
        }
        case 7: // fighter
        {
            chosenClass.setName("Fighter");
            chosenClass.setHitDice("1d10");
            chosenClass.setDescription("A master of martial combat, skilled with a variety of weapons and armor");
            break;
        }
        case 8: // barbarian
        {
            chosenClass.setName("Barbarian");
            chosenClass.setHitDice("1d12");
            chosenClass.setDescription("A fierce warrior of primitive background who can enter a battle rage");
            break;
        }
        case 9: // artificer
        {
            chosenClass.setName("Artificer");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A master of invention, artificers use ingenuity and magic to unlock extraordinary capabilities in objects");
            break;
        }
        case 10: // cleric
        {
            chosenClass.setName("Cleric");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A priestly champion who wields divine magic in service of a higher power");
            break;
        }
        case 11: // monk
        {
            chosenClass.setName("Monk");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A master of martial arts, harnessing the power of the body in pursuit of physical and spiritual perfection");
            break;
        }
        case 12: // bard
        {
            chosenClass.setName("Bard");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("An inspiring magician whose power echoes the music of creation");
            break;
        }
        default: // functia se reapeleaza daca optiunea e invalida
        {
            std::cout << "Option invalid, try again?\n";
            std::cin >> option;
            dndHelper::pickClass(option);
        }

        }
        std::cout << "Now, choose your level (reminder: unless multi-classing, your character can be at most lvl 20)\n";
        std::cin >> lvl;
        chosenClass.setLevel(lvl);

        return chosenClass;
    }

    inline Race pickRace(int option) // returneaza race-ul corect ales de utilizator
    {

		Race chosenRace;
        switch (option)
        {

        case 1: // human 
        {
            chosenRace.setName("Human");
            chosenRace.setDescription("Found throughout the multiverse, humans are as varied as they are numerous.");
            break;
        }
        case 2: // elf
        {
            chosenRace.setName("Elf");
            chosenRace.setDescription("The elves’ curiosity led many of them to explore other planes of existence.");
            break;
        }
        case 3: // dwarf
        {
            chosenRace.setName("Dwarf");
            chosenRace.setDescription("Dwarves were raised from the earth in the elder days by a deity of the forge.");
            break;
        }
        case 4: // halfling
        {
            chosenRace.setName("Halfling");
            chosenRace.setDescription("Halflings possess a brave and adventurous spirit that leads them on journeys of discovery.");
            break;
        }
        case 5: // dragonborn
        {
            chosenRace.setName("Dragonborn");
            chosenRace.setDescription("The ancestors of dragonborn hatched from the eggs of chromatic and metallic dragons.");
            break;
        }
        case 6: // half-elf
        {
            chosenRace.setName("Half-Elf");
            chosenRace.setDescription("");
            break;
        }
        case 7: // fairy
        {
            chosenRace.setName("Fairy");
            chosenRace.setDescription("Infused with the magic of the Feywild, most fairies look like Small elves with insectile wings, but each fairy has a special physical characteristic that sets the fairy apart.");
            break;
        }
        case 8: // tiefling
        {
            chosenRace.setName("Tiefling");
            chosenRace.setDescription("Tieflings are either born in the Lower Planes or have fiendish ancestors who originated there.");
            break;
        }
        default: // cand nu introduce o valoare existenta
        {
            std::cout << "Option not available, try again?\n";
			std::cin >> option;
			dndHelper::pickRace(option);
        }

        }
        return chosenRace;
    }

    inline void pickPlayerCharacter() // just chooses and creates the PC, IF YOU WANT TO DISPLAY ATRIBUTES USE THE CLASS FUNCTION!!!
    {
        int option;
        Class chosenClass;
        Race chosenRace;

        dndHelper::pickClassMessage();
        std::cin >> option;
        chosenClass = dndHelper::pickClass(option);

        dndHelper::pickRaceMessage();
        std::cin >> option;
        chosenRace = dndHelper::pickRace(option);
    }

    inline void menu()
    {
        std::cout << "Your character basics have all been set up, what would you like to do?";
        std::cout << "1. add another class";
        std::cout << "2. add equipment";
        std::cout << "3. add backstory";
        std::cout << "4. pick abilities (available at current level)";
        std::cout << "5. level up";
        std::cout << "6. quit (deleting the character...)";
    }
}


#endif // !DNDHELPER
