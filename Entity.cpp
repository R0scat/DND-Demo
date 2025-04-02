#include "Entity.h"

using namespace std;

Entity::Entity() {
	//cout << "Created Entity!" << endl;
}

Entity::~Entity() {
	//cout << "Destroyed Entity!" << endl;
}

Entity::Entity(int health) {
	this->healthPoints = health;
	cout << "Created Entity with " << health << " HP!" << endl;
}

void Entity::getHealth() {
	cout << "Health: " << healthPoints << endl;
}

void Entity::setHealth(int health) {
	healthPoints = health;
}
