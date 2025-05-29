#include "effect.h"

// setterii  si getterii simplii
void Effect::SetName(std::string name)
{
	this->m_name = name;
}

std::string Effect::GetName()
{
	return this->m_name;
}

void Effect::SetDescription(std::string desc)
{
	this->m_description = desc;
}


//supraincarcare operatori << si ==
std::ostream& operator << (std::ostream& cout, const Effect& obj) {
	cout << "Effect name: " << obj.m_name;
	cout << "Effect description: " << obj.m_description;
	return cout;
}

bool Effect::operator==(Effect const& obj)
{
	if (m_name == obj.m_name && m_description == obj.m_description)
		return true;
	return false;
}

// override GameObject
void Effect::SetId()
{
	GameObject::m_id++; // creste contorul total al obiectelor
	this->m_object_type = "Effect"; // seteaza tipul obiectului
	this->m_full_id = m_object_type + std::to_string(GameObject::m_id);
}