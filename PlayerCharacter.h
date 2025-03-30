#ifndef PLAYERCHARACTER_H
#define PLAYERCHACTER_H

#pragma once
#include <string>
#include "Entity.h"
#include "Class.h"
#include "Race.h"

//

class PlayerCharacter : public Entity {
	std::string playerName;
	std::string characterName;
	Class characterClass;
	Race characterRace;
	int level;
public:
	PlayerCharacter();
	PlayerCharacter(const PlayerCharacter& PC);
	~PlayerCharacter();

};

#endif