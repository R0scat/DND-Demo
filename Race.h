#pragma once
#ifndef RACE_H
#define RACE_H

class Race {
	std::string name;
	std::string description;
public:
	Race();
	Race(std::string name, std::string description);
	Race(const Class& obj);
	~Race();
	std::string getName();
	std::string getDescription();
	void setName(std::string name);
	void setDescription(std::string description);
};


#endif // !RACE_H