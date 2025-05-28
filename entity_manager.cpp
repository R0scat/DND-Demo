#include "entity_manager.h"

std::vector<Entity*> EntityManager::m_all_entities;

void EntityManager::ShowAllEntities()
{
	int nr = 0;
	for (Entity* obj : m_all_entities)
		std::cout << "Showing entity number " << ++nr << " :\n" << *obj << "\n"; // *obj NU obj pt ca obj simplu e pointer; pointer la pointer inseamna ca il DIFERENTIEZI
}

Entity* EntityManager::GetSpecificEntity(int pos)
{
	return m_all_entities[pos];
}

void EntityManager::AddEntity(Entity*& de_adaugat)
{
	m_all_entities.push_back(de_adaugat);
	std::cout << "Added succesfully!\n";
}

std::vector<Entity*> EntityManager::GetEntityVector()
{
	return m_all_entities;
}