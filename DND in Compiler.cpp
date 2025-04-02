#include <iostream>
#include "DndHelper.h"
#include "Class.h"
#include "Race.h"
#include "PlayerCharacter.h"

void start() {
    int option, lvl;
	Class chosenClass;
    Race chosenRace;
    std::string username, characterName;

    std::cout << "Welcome to the DND character Creator! Please say your name or nickname:\n";
    std::cin >> username;
    std::cout << std::endl;

    std::cout << "Now, let's start by picking your class, race and level!\n";
    dndHelper::pickClassMessage(); // includes telling the user to pick their class !!!!
    std::cin >> option;
    chosenClass = dndHelper::pickClass(option); // functie din namespace dndHelper facuta sa ajute utilizatorul la alegerea claseo

    dndHelper::pickRaceMessage(); // doar un mesaj ca sa aleaga utilizatorul user
    std::cin >> option;
    chosenRace = dndHelper::pickRace(option);
    //chosenRace.showRaceDetails();

    std::cout << "What do you want your character to be called? :P\n";
    std::cin >> characterName;

    PlayerCharacter PC(username, characterName, chosenClass, chosenRace); // aici se construieste in sine Player Character-ul

    std::cout << "Great! Your character currently looks like this:\n";
    PC.showPlayerCharacterDetails();

    dndHelper::menu();
}

int main()
{
    start();
}
