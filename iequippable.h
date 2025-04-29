#pragma once
#ifndef IEQUIPPABLE_H
#define IEQUIPPABLE_H

#include "class.h"

class IEquippable // interfata pt lucruri echipabile? ce pot fi echipate? puse pe personaj?
{
public:
	virtual void Equip(Class* pc) = 0; // pure virtual function for equipping an item
	virtual void Unequip(Class* pc) = 0; // pure virtual function for unequipping an item
	virtual ~IEquippable() = default; // virtual destructor
};


#endif // IEQUIPPABLE_H
