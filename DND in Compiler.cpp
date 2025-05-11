#include <iostream>
#include <fstream>
#include <string>
#include "dnd_helper.h"
#include "atribute_helper.h"
#include "class.h"
#include "race.h"
#include "player_character.h"

static void PlayerMode() {
    int option_int, lvl, ongoing = 1;
	Class chosen_class;
    Race chosen_race;
    std::string username, character_name;
    char option_string[50];

    std::cout << "Welcome to the DND character Creator! Please say your name or nickname:\n";
    std::getline(std::cin, username); // aici se ia numele personajului
    std::cout << std::endl;

    std::cout << "Now, let's start by picking your class, race and level!\n";
    Dnd_Helper::PickClassMessage(); // includes telling the user to pick their class + level!!!!
    //std::cin >> optionString;
    std::cin.getline(option_string, 51);
	//std::cout << optionString << std::endl;  // linie de debug
    option_int = Dnd_Helper::ParseMessage(option_string, 1); // pt clasa parseaza cu 1; pt rasa cu 2
    chosen_class = Dnd_Helper::PickClass(option_int); // functie din namespace dndHelper facuta sa ajute utilizatorul la alegerea claseo

    // pt alegerea lvl-ului
    std::cout << "Now, choose your level (reminder: unless multi-classing, your character can be at most lvl 20)\n";
    std::cin >> lvl;
    chosen_class.SetLevel(lvl);

    std::cin.get();

    Dnd_Helper::PickRaceMessage(); // doar un mesaj ca sa aleaga utilizatorul user
    //std::cin >> optionString;
    std::cin.getline(option_string, 51);
    //std::cout << optionString << std::endl;  // linie de debug
    option_int = Dnd_Helper::ParseMessage(option_string, 2); // 2 pt rasa
    chosen_race = Dnd_Helper::PickRace(option_int);
    //chosenRace.showRaceDetails();

    std::cout << "What do you want your character to be called? :P\n";
	std::getline(std::cin, character_name); // aici se ia numele personajului

    PlayerCharacter pc(username, character_name, chosen_class, chosen_race); // aici se construieste in sine Player Character-ul

    std::cout << "Great! Your character currently looks like this:\n";
    pc.ShowPlayerCharacterDetails();
    std::cout << "Press enter to continue!\n";

    Dnd_Helper::ClearScreen();

    while (ongoing)
    {
        Dnd_Helper::Menu();
        std::cin >> option_int;
        Dnd_Helper::MenuPicker(option_int, ongoing, pc);
    }
}


int main()
{
    //PlayerMode();

    //Atribute_Helper::ReadAtributes(); // currently testing getting atributes for a rando class !!
  //  Equipment available_equipment[40];
  //  int total_equipment;
  //  Atribute_Helper::ReadEquipment(available_equipment, total_equipment); // testing file reading function nr.2
  //  std::cout << "======================TESTING===========================\n";
  //  for (int i = 0; i < total_equipment; i++)
  //  {
		//std::cout << available_equipment[i] << std::endl;
  //  }
}
