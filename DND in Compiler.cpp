#include <iostream>
#include "DndHelper.h"
#include "Class.h"
#include "Race.h"
#include "PlayerCharacter.h"

void start() {
    int option;
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
    //std::cout << "Currently your character looks something like this: \n";
	//chosenClass.showClassDetails(); 

    dndHelper::pickRaceMessage(); // doar un mesaj ca sa aleaga utilizatorul user
    std::cin >> option;
    chosenRace = dndHelper::pickRace(option);
    //chosenRace.showRaceDetails();

    std::cout << "What do you want your character to be called? :P\n";
    std::cin >> characterName;


    PlayerCharacter PC(username, characterName, chosenClass, chosenRace);
    PC.setLevel(chosenClass.getLevel());

    std::cout << "Great! Your character currently looks like this:\n";
    PC.showPlayerCharacterDetails();
}

int main()
{
    start();
}
