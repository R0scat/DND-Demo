#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include <iostream>

class Entity {
public:
	Entity();					 // constructor simplu
	Entity(int health);			 // constructor cu parametrii
	Entity(const Entity& obj);   //constructor de copiere
	~Entity();					 // desctructor
	void GetHealth() const;			 // getter pt HP
	void SetHealth(int health);  // setter pt HP

protected:
	int m_health_points;
};

#endif // !ENTITY_H