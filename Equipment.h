
#pragma once
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Atribute.h"

class Equipment : public Atribute {
private:
	
	int m_value;
public:
	
	void setValue(int value);
	//int getWeight();
	//int getValue();
};

#endif // !EQUIPMENT_H
