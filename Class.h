#pragma once
#ifndef CLASS_H
#define CLASS_H

#include <string>

class Class {
	std::string name;
	std::string hitDice;
	std::string description;
	int level;
public:
	Class();															     // constructor simplu clasa
	Class(std::string name, std::string hitDice, std::string description);   // constructor parametrii
	Class(const Class& obj);											     // constructor copiere
	~Class();															     // destructor
	std::string getName();												     // getter nume
	std::string getHitDice();											     // getter hd
	std::string getDescription();										     // getter desc
	int getLevel();														     // getter lvl
	void setName(std::string name);										     // setter nume
	void setHitDice(std::string hitDice);								     // setter hd
	void setDescription(std::string description);						     // setter desc
	void setLevel(int level);											     // setter lvl + verifica daca valoarea e valida (intre 1 si 20 momentan)
	void showClassDetails();											     // afiseaza toate detaliile clasei cu mesaj frumos <3
	friend std::ostream& operator << (std::ostream& cout, const Class& obj); // overload pt operatorul "<<"
};


#endif // !CLASS_H