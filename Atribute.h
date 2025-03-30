#pragma once
#ifndef ATRIBUTE_H
#define ATRIBUTE_H

// class Atribute becomes an umbrella class for everything that'll be added to the character
class Atribute {
	bool isActive = false; 
	// lowk the most general value an object could have, is it equipped or not? does that character have said skill/ class etc.?
public:
	Atribute();
	Atribute(bool isActive);
	Atribute(const Atribute& atrbuteObject);
	~Atribute();
	void activateAtribute();
	void deactivateAtribute();
	bool getAtributeStatus();
};

#endif // !ATRIBUTE_H
