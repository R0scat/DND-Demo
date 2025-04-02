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
	void getHealth();			 // getter pt HP
	void setHealth(int health);  // setter pt HP

protected:
	int healthPoints;
};

#endif // !ENTITY_H