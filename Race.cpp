#include "Race.h"
#include <string.h>
#include <iostream>

Race::Race() {
	this->name = "None";
	this->description = "None";
}

Race::Race(std::string name, std::string description)
{
	this->name = name;
	this->description = description;
}

Race::Race(const Race& RaceObj)
{
	this->name = RaceObj.name;
	this->description = RaceObj.description;
}

Race:: ~Race() {}

std::string Race::getName()
{
	return this->name;
}

std::string Race::getDescription()
{
	return this->description;
}

void Race::setName(std::string name)
{
	this->name = name;
}

void Race::setDescription(std::string description)
{
	this->description = description;
}

void Race::showRaceDetails()
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Description: " << this->description << std::endl;
}