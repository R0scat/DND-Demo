#pragma once
#ifndef RACE_H
#define RACE_H

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

class Race {
	std::string m_name;
	std::string m_description;
	RaceBonus bonus; // to calculate stat bonuses
public:
	Race();
	Race(std::string name, std::string description);
	Race(const Race& RaceObj);
	~Race();
	std::string GetName() const;
	std::string GetDescription() const;
	void SetName(std::string name);
	void SetDescription(std::string description);
	void ShowRaceDetails();
	friend std::ostream& operator << (std::ostream& cout, const Race& obj);
};


#endif // !RACE_H