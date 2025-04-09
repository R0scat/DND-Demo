#include <iostream>
#include <string>
#include "DndHelper.h"
#include "Class.h"
#include "Race.h"
#include "PlayerCharacter.h"

void start() {
    int optionInt, lvl, ongoing = 1;
	Class chosenClass;
    Race chosenRace;
    std::string username, characterName;
    char optionString[50];

    std::cout << "Welcome to the DND character Creator! Please say your name or nickname:\n";
    std::getline(std::cin, username); // aici se ia numele personajului
    std::cout << std::endl;

    std::cout << "Now, let's start by picking your class, race and level!\n";
    dndHelper::pickClassMessage(); // includes telling the user to pick their class + level!!!!
    //std::cin >> optionString;
    std::cin.getline(optionString, 51);
	//std::cout << optionString << std::endl;  // linie de debug
    optionInt = dndHelper::parseMessage(optionString, 1); // pt clasa parseaza cu 1; pt rasa cu 2
    chosenClass = dndHelper::pickClass(optionInt); // functie din namespace dndHelper facuta sa ajute utilizatorul la alegerea claseo

    // pt alegerea lvl-ului
    std::cout << "Now, choose your level (reminder: unless multi-classing, your character can be at most lvl 20)\n";
    std::cin >> lvl;
    chosenClass.setLevel(lvl);

    dndHelper::pickRaceMessage(); // doar un mesaj ca sa aleaga utilizatorul user
    //std::cin >> optionString;
    std::cin.getline(optionString, 51);
    //std::cout << optionString << std::endl;  // linie de debug
    optionInt = dndHelper::parseMessage(optionString, 2); // 2 pt rasa
    chosenRace = dndHelper::pickRace(optionInt);
    //chosenRace.showRaceDetails();

    std::cout << "What do you want your character to be called? :P\n";
	std::getline(std::cin, characterName); // aici se ia numele personajului

    PlayerCharacter PC(username, characterName, chosenClass, chosenRace); // aici se construieste in sine Player Character-ul

    std::cout << "Great! Your character currently looks like this:\n";
    PC.showPlayerCharacterDetails();
    std::cout << "Press enter to continue!\n";

    dndHelper::clearScreen();

    while (ongoing)
    {
        dndHelper::menu();
        std::cin >> optionInt;
        dndHelper::menuPicker(optionInt, ongoing, PC);
    }
    
}

int main()
{
    start();
}
