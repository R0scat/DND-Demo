#pragma once
#ifndef IEFFECT_H
#define IEFFECT_H

struct Effect
{
	std::string name;
	std::string description;

	friend std::ostream& operator << (std::ostream& cout, const Effect& obj)
	{
		cout << "Effect name: " << obj.name;
		cout << "Effect description: " << obj.description;
		return cout;
	}

	bool operator==(Effect const& obj)
	{
		if (name == obj.name && description == obj.description)
			return true;
		return false;
	}
};

class IEffect // interfata pt toate efectele pe care le poate avea un pc / any living creature
{
public:
	virtual void Apply(Effect applied_effect) = 0; 
	virtual void Remove(Effect removed_effect) = 0; 
	virtual ~IEffect() = default;
};


#endif // IEQUIPPABLE_H
