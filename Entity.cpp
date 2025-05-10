#include "Entity.h"

using namespace std;

Entity::Entity() 
{
	//cout << "Created Entity!" << endl;
}

Entity::~Entity() 
{
	//cout << "Destroyed Entity!" << endl;
}

Entity::Entity(int health)
{
	this->m_health_points = health;
	cout << "Created Entity with " << health << " HP!" << endl;
}

void Entity::GetHealth() const
{
	cout << "Health: " << m_health_points << endl;
}

void Entity::SetHealth(int health) {
	m_health_points = health;
}
