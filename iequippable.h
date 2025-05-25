#pragma once
#ifndef IEQUIPPABLE_H
#define IEQUIPPABLE_H

//#include "class.h"
#include "entity.h"

class Iequippable // interfata pt lucruri echipabile? ce pot fi echipate? puse pe personaj?
{
public:
	virtual void Equip(Entity* pc) = 0; // pure virtual function for equipping an item
	virtual void Unequip(Entity* pc) = 0; // pure virtual function for unequipping an item
	virtual ~Iequippable() = default; // virtual destructor
};


#endif // IEQUIPPABLE_H
