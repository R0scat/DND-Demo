#pragma once
#ifndef CLASS_H
#define CLASS_H

#include <string>

class Class {
	std::string name;
	std::string hitDice;
	std::string description;
	int classLevel;
public:
	Class();															     // constructor simplu clasa
	Class(std::string name, std::string hitDice, std::string description, int classLevel);   // constructor parametrii
	Class(const Class& obj);											     // constructor copiere
	~Class();															     // destructor
	std::string getName();												     // getter nume -> returneaza numele
	std::string getHitDice();											     // getter hd ---> returneaza hit dice-ul
	std::string getDescription();										     // getter desc -> returneaza desc
	int getLevel();														     // getter lvl --> returneaza level-ul
	void setName(std::string name);										     // setter nume
	void setHitDice(std::string hitDice);								     // setter hd
	void setDescription(std::string description);						     // setter desc
	void setLevel(int level);											     // setter lvl + verifica daca valoarea e valida (intre 1 si 20 momentan)
	void showClassDetails();											     // afiseaza toate detaliile clasei cu mesaj frumos <3
	friend std::ostream& operator << (std::ostream& cout, const Class& obj); // overload pt operatorul "<<"
};


#endif // !CLASS_H