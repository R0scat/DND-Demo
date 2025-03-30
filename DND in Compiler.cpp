#include <iostream>
#include "DndHelper.h"

void start() {
    int option;
	Class chosenClass;
    Race chosenRace;

    dndHelper::startMessage(); // includes telling the user to pick their class !!!!
    std::cin >> option;
    chosenClass = dndHelper::pickClass(option);
    std::cout << "Currently your current character looks something like this: \n";
	chosenClass.showClassDetails();

    dndHelper::pickRaceMessage();
    chosenRace = dndHelper::pickRace();
}

int main()
{
    start();
}
