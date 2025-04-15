#pragma once
#ifndef CLASS_H
#define CLASS_H

#include <string>

class Class {
	std::string m_name;
	std::string m_hit_dice;
	std::string m_description;
	int m_class_level;
public:
	Class();															     // constructor simplu clasa
	Class(std::string name, std::string hitDice, std::string description, int classLevel);   // constructor parametrii
	Class(const Class& obj);											     // constructor copiere
	~Class();															     // destructor
	std::string GetName();												     // getter nume -> returneaza numele
	std::string GetHitDice();											     // getter hd ---> returneaza hit dice-ul
	std::string GetDescription();										     // getter desc -> returneaza desc
	int GetLevel();														     // getter lvl --> returneaza level-ul
	void SetName(std::string name);										     // setter nume
	void SetHitDice(std::string hitDice);								     // setter hd
	void SetDescription(std::string description);						     // setter desc
	void SetLevel(int level);											     // setter lvl + verifica daca valoarea e valida (intre 1 si 20 momentan)
	void ShowClassDetails();											     // afiseaza toate detaliile clasei cu mesaj frumos <3
	friend std::ostream& operator << (std::ostream& cout, const Class& obj); // overload pt operatorul "<<"
};


#endif // !CLASS_H