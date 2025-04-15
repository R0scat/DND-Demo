#pragma once
#ifndef ATRIBUTE_H
#define ATRIBUTE_H

#include <string>

// class Atribute becomes an umbrella class for everything that'll be added to the character
class Atribute {
protected:
	std::string m_type; // is it an atribute for a class? for a race? archetype?
	std::string m_name; // atribute name
	std::string m_description; // atribute description
	int m_level; // level at which the atribute is available
public:
	Atribute();
	Atribute(std::string type, std::string name, std::string description, int level);
	Atribute(const Atribute& atrbuteObject);
	~Atribute();
	void SetAtributeType(std::string type);
	void SetAtributeName(std::string name);
	void SetAtributeDescription(std::string description);
	void SetAtributeLevel(int level);
	std::string GetAtributeType();
	std::string GetAtributeName();
	std::string GetAtributeDescription();
	int GetAtributeLevel();
};

#endif // !ATRIBUTE_H
