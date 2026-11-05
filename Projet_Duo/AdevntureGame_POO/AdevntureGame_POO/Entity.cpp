#include "Entity.h"
#include <iostream>
#include <conio.h>

bool Entity::isAlive()
{
	if (life_point <= 0)
	{
		return false;
	}
	return true;
}

void Entity::onUpdate(Map& map, std::vector<Entity*>& others)
{
	// 1. Mouvement
	Vector2 dir = chooseDirection(others);
	if (map.isWalkable(pos + dir))
		move(dir);

	// 2. Collisions
	for (Entity* other : others) {
		if (other != this && other->isAlive() && other->getPos() == pos)
			onCollision(other);
	}
}

void Entity::takeDamage()
{
	life_point -= 1;
}

int Entity::getLife()
{
	return life_point;
}

Vector2 Entity::getPos()
{
	return pos;
}

void Entity::move(Vector2 dir)
{
	pos = pos + dir;
}
