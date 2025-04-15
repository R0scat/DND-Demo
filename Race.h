#pragma once
#ifndef RACE_H
#define RACE_H

#include <iostream>

class Race {
	std::string m_name;
	std::string m_description;
public:
	Race();
	Race(std::string name, std::string description);
	Race(const Race& RaceObj);
	~Race();
	std::string GetName();
	std::string GetDescription();
	void SetName(std::string name);
	void SetDescription(std::string description);
	void ShowRaceDetails();
	friend std::ostream& operator << (std::ostream& cout, const Race& obj);
};


#endif // !RACE_H