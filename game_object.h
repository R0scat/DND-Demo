#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <iostream>

// clasa abstracta mostenita de toate celelalte clase 
// id-ul unui obiect este facut din tipul sau si id
// de exemplu pt un obiect de tip PlayerCharacter id-ul va arata asa:
// PlayerCharacter1, PlayerCharacter2...


class GameObject
{
protected:
	static int m_id; // variabila statica ce va contoriza toate obiectele
	std::string m_object_type; // variabila ce tine tipul obiectului
	std::string m_full_id;

public:
	std::string GetId();
	virtual void SetId() = 0; // functie ce seteaza m_full_id in functie de tipul din fiecare clasa
	void ShowFullId();
	virtual ~GameObject() = default;
};

#endif // !GAMEOBJECT_H

