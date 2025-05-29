#pragma once
#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <iostream>
#include "game_object.h"

// clasa asta nu mosteneste Atribute pt ca o facusem initial ca struct si acuma doar voiam sa ii mai adaug functii
class Effect : public GameObject
{
	std::string m_name;
	std::string m_description;

public:
	// operatorii
	friend std::ostream& operator << (std::ostream& cout, const Effect& obj);
	bool operator==(Effect const& obj);
	std::string GetName();
	void SetName(std::string name);
	void SetDescription(std::string desc);

	// override GameObject
	void SetId() override;
};

#endif // !EFFECT_H