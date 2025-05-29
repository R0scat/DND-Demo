#include "game_object.h"

int GameObject::m_id = 0;

std::string GameObject::GetId()
{
	return this->m_full_id;
}

void GameObject::ShowFullId()
{
	std::cout << this->m_full_id;
}