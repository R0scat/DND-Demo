#include "entity_manager.h"

// initializare membru static in afara definitiei clasei
std::vector<Entity*> EntityManager::m_all_entities;

// functie ce ia fiecare entitate pe rand din vectorul de entitati si le afiseaza
void EntityManager::ShowAllEntities()
{
	int nr = 0;
	for (Entity* obj : m_all_entities)
		std::cout << "Showing entity number " << ++nr << " :\n" << *obj << "\n"; // *obj NU obj pt ca obj simplu e pointer; pointer la pointer inseamna ca il DIFERENTIEZI
}

// pt a returna entitatea de pe pozitia pos
Entity* EntityManager::GetSpecificEntity(int pos)
{
	return m_all_entities[pos];
}

// pt a adauga o entitate la final
void EntityManager::AddEntity(Entity*& de_adaugat)
{
	m_all_entities.push_back(de_adaugat);
	std::cout << "Added succesfully!\n";
}

// pt a returna tot vectorul 
std::vector<Entity*> EntityManager::GetEntityVector()
{
	return m_all_entities;
}

// se iau toate elem din vector cu indexul i pt ca vrea usa afisez pe ecran nu doar efectul ci si indexul entitatii ce e afectata (suna weird dar da?)
void EntityManager::ShowEffectsForEachEntity()
{
	for (int i = 0; i < m_all_entities.size(); i++)
	{
		std::cout << "Effect(s) for entity number " << (i + 1) << ":\n";
		m_all_entities[i]->ShowAllEffects();
		std::cout << "\n";
	}
}