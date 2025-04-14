#pragma once
#ifndef ATRIBUTE_H
#define ATRIBUTE_H

#include <string>

// class Atribute becomes an umbrella class for everything that'll be added to the character
class Atribute {
protected:
	std::string type; // is it an atribute for a class? for a race? archetype?
	std::string name; // atribute name
	std::string description; // atribute description
	int level; // level at which the atribute is available
public:
	Atribute();
	Atribute(std::string type, std::string name, std::string description, int level);
	Atribute(const Atribute& atrbuteObject);
	~Atribute();
	void setAtributeType(std::string type);
	void setAtributeName(std::string name);
	void setAtributeDescription(std::string description);
	void setAtributeLevel(int level);
	std::string getAtributeType();
	std::string getAtributeName();
	std::string getAtributeDescription();
	int getAtributeLevel();
};

#endif // !ATRIBUTE_H
