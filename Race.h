#pragma once
#ifndef RACE_H
#define RACE_H

#include "game_object.h"
#include <iostream>

struct RaceBonus // represents the bonus to base stats that each race gives
{
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
};

class Race :  public GameObject
{
	std::string m_name;
	std::string m_description;
	RaceBonus bonus; // to calculate stat bonuses
public:
	virtual ~Race() = default;
	std::string GetName() const;
	std::string GetDescription() const;
	void SetName(std::string name);
	void SetDescription(std::string description);
	void ShowRaceDetails();
	friend std::ostream& operator << (std::ostream& cout, const Race& obj);

	void SetId() override;
};


#endif // !RACE_H