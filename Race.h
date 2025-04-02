#pragma once
#ifndef RACE_H
#define RACE_H

#include <iostream>

class Race {
	std::string name;
	std::string description;
public:
	Race();
	Race(std::string name, std::string description);
	Race(const Race& RaceObj);
	~Race();
	std::string getName();
	std::string getDescription();
	void setName(std::string name);
	void setDescription(std::string description);
	void showRaceDetails();
	friend std::ostream& operator << (std::ostream& cout, const Race& obj);
};


#endif // !RACE_H