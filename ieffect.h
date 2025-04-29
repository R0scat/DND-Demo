#pragma once
#ifndef IEFFECT_H
#define IEFFECT_H

class IEffect // interfata pt toate efectele pe care le poate avea un pc / any living creature
{
public:
	virtual void Apply() = 0; 
	virtual void Remove() = 0; 
	virtual ~IEffect() = default;
};


#endif // IEQUIPPABLE_H
