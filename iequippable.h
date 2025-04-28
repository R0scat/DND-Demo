#pragma once
#ifdef IEQUIPPABLE_H
#define IEQUIPPABLE_H

class IEquippable 
{
public:
	virtual void Equip() = 0; // pure virtual function for equipping an item
	virtual void Unequip() = 0; // pure virtual function for unequipping an item
	virtual ~IEquippable() {} // virtual destructor
};


#endif // IEQUIPPABLE_H
