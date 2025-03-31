#include <iostream>
#include "DndHelper.h"

void start() {
    int option;
	Class chosenClass;
    Race chosenRace;

    dndHelper::startMessage(); // includes telling the user to pick their class !!!!
    std::cin >> option;
    chosenClass = dndHelper::pickClass(option); // functie din namespace dndHelper facuta sa ajute utilizatorul la alegerea claseo
    std::cout << "Currently your current character looks something like this: \n";
	chosenClass.showClassDetails(); 

    dndHelper::pickRaceMessage(); // doar un mesaj 
    std::cin >> option;
    chosenRace = dndHelper::pickRace(option);
    chosenRace.showRaceDetails();
}

int main()
{
    start();
}
