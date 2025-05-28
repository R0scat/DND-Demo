#pragma once
#ifndef IEFFECT_H
#define IEFFECT_H

#include "effect.h"

class IEffect // interfata pt toate efectele pe care le poate avea un pc / any living creature
{
public:
	virtual void Apply(Effect applied_effect) = 0; 
	virtual void Remove(std::string effect_name) = 0; 
	virtual ~IEffect() = default;
};


#endif // IEQUIPPABLE_H
