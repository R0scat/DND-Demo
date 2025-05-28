#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include <iostream>
#include "ieffect.h"
#include <vector>

struct Stats { // will keep the actual number like 13 st, 14 cha lalala
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;

	friend std::ostream& operator << (std::ostream& cout, const Stats& obj)
	{
		cout << "strenght = " << obj.strength << "\n";
		cout << "dexterity = " << obj.dexterity << "\n";
		cout << "constitution = " << obj.constitution << "\n";
		cout << "intelligence = " << obj.intelligence << "\n";
		cout << "wisdom = " << obj.wisdom << "\n";
		cout << "charisma = " << obj.charisma << "\n";
		return cout;
	}
};



struct Skill
{
	char name[50]; // nume skill
	char statType[50]; // tipul skill-ului (str, dex, int, wis, cha)
	int bonus;   // asta e gen +2 la arcana sau + 4 perception-ul in sine
	bool proficient; // true sau false, daca e true se adauga proficiency bonusul
	bool expert; // same thing cu proficient doar ca mai adauga bonusul o data
	int nr; // pastreaza de cate ori a fost adaugat numarul la skill
	
	friend std::ostream& operator << (std::ostream& cout, const Skill& obj)
	{
		cout << "Name: " << obj.name << "\n";
		cout << "Stat Type: " << obj.statType << "\n";
		cout << "Bonus: " << obj.bonus << "\n";
		cout << "Proficiency: " << obj.proficient << "\n";
		cout << "Expertise:: " << obj.expert << "\n";
		cout << "\n";
		return cout;
	}
};

//struct SavingThrows { // will be calculated from stats + should be modified by FIRST chosen class 
//	int strength;
//	int dexterity;
//	int constitution;
//	int intelligence;
//	int wisdom;
//	int charisma;
//
//	friend std::ostream& operator << (std::ostream& cout, const SavingThrows& obj)
//	{
//		cout << "strenght = " << obj.strength << "\n";
//		cout << "dexterity = " << obj.dexterity << "\n";
//		cout << "constitution = " << obj.constitution << "\n";
//		cout << "intelligence = " << obj.intelligence << "\n";
//		cout << "wisdom = " << obj.wisdom << "\n";
//		cout << "charisma = " << obj.charisma << "\n";
//		return cout;
//	}
//};

struct EntityDetails // pun toate astea intr-un singru struct INAINTE sa le pun in clasa PlayerCharacter pt ca pare mai organizat
{
	Stats stats;
	Skill skills[18]; // sunt mereu aceleasi skil-uri deci nu are sens sa le pun intr- strctura de date dinamica (cum e lista de proficiencies)

	friend std::ostream& operator << (std::ostream& cout, const EntityDetails& obj)
	{
		cout << "Stats: " << obj.stats << "\n";
		cout << "Skills: \n";
		for (int i = 0; i < 18; i++)
			cout  << obj.skills[i] << "\n";
		return cout;
	}
};

class Entity: public IEffect
{
public:
	Entity();					 // constructor simplu
	Entity(int health);			 // constructor cu parametrii
	Entity(const Entity& obj);   //constructor de copiere
	~Entity();					 // desctructor
	void GetHealth() const;			 // getter pt HP
	void SetHealth(int health);  // setter pt HP
	void Apply(Effect applied_effect) override;
	void Remove(std::string effect_name) override;
	void ShowAllEffects();
	void CalculateSkills(EntityDetails& details);
	void PopulateSkills(EntityDetails& details);
	void ChangeCharacterStats();
	void ChangeGivenProficiency(char prf_name[50]);
	bool CheckIfStatsInInterval();
	std::vector<Effect> ReturnEffectVector();
	Effect GetEffectByName(std::string effect_name);

	virtual int CalculateAbilityStrenghts();
	//virtual void InputMessage();
	friend std::ostream& operator << (std::ostream& cout, const Entity& obj);

protected:
	int m_health_points;
	EntityDetails m_details;
	std::vector<Effect> m_active_effects;
};

#endif // !ENTITY_H