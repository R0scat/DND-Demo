#pragma once
#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <iostream>

class Effect
{
	std::string m_name;
	std::string m_description;

public:
	friend std::ostream& operator << (std::ostream& cout, const Effect& obj);
	bool operator==(Effect const& obj);
	std::string GetName();
	void SetName(std::string name);
	void SetDescription(std::string desc);
};

#endif // !EFFECT_H