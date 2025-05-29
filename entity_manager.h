#pragma once
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include "entity.h"

class EntityManager
{
	// vector folosit pt a stoca toate entitatile create de DM
	static std::vector<Entity*> m_all_entities;

public:

	static Entity* GetSpecificEntity(int pos);
	static void ShowAllEntities();
	static void AddEntity(Entity* &de_adaugat);
	static std::vector<Entity*> GetEntityVector();
	static void ShowEffectsForEachEntity();
};

#endif // !ENTITYMANAGER_H
