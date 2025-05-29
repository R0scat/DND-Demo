#pragma once
#ifndef ATRIBUTE_H
#define ATRIBUTE_H

#include <string>
#include "game_object.h"

// class Atribute becomes an umbrella class for everything that'll be added to the character
class Atribute : GameObject
{
protected:
	std::string m_type; // is it an atribute from a class? for a race? archetype?
	std::string m_name; // atribute name
	std::string m_description; // atribute description
	//int m_level; // level at which the atribute is available
public:
	Atribute();
	Atribute(std::string type, std::string name, std::string description, int level);
	Atribute(const Atribute& atributeObject);
	virtual ~Atribute() = default;

	void SetAtributeType(std::string type);
	void SetAtributeName(std::string name);
	void SetAtributeDescription(std::string description);
	
	std::string GetAtributeType() const;
	std::string GetAtributeName() const;
	std::string GetAtributeDescription() const;

	// override from GameObject
	void SetId() override;
};

#endif // !ATRIBUTE_H
