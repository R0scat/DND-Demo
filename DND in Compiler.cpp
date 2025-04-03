#include <iostream>
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
    std::cin >> username;
    std::cout << std::endl;

    std::cout << "Now, let's start by picking your class, race and level!\n";
    dndHelper::pickClassMessage(); // includes telling the user to pick their class !!!!
    std::cin >> optionString;

    optionInt = dndHelper::parseMessage(optionString, 1); // pt clasa parseaza cu 1; pt rasa cu 2

    //if (dndHelper::checkIfNumber(optionString) == NULL)
    //    optionInt = dndHelper::makeInt(optionString, 1); // cazul in care au introdus an entire ass word! lmao
    //else
    //    optionInt = int(optionString[0] - '0'); // cazul in care au introdus 1 sau 1. sau ceva de genul

    chosenClass = dndHelper::pickClass(optionInt); // functie din namespace dndHelper facuta sa ajute utilizatorul la alegerea claseo

    dndHelper::pickRaceMessage(); // doar un mesaj ca sa aleaga utilizatorul user
    std::cin >> optionInt;
    chosenRace = dndHelper::pickRace(optionInt);
    //chosenRace.showRaceDetails();

    std::cout << "What do you want your character to be called? :P\n";
    std::cin >> characterName;

    PlayerCharacter PC(username, characterName, chosenClass, chosenRace); // aici se construieste in sine Player Character-ul

    std::cout << "Great! Your character currently looks like this:\n";
    PC.showPlayerCharacterDetails();

    while (ongoing)
    {
        dndHelper::menu();
        std::cin >> optionInt;
        if (optionInt == 6)
            ongoing = 0;
    }
    
}

int main()
{
    start();
}
