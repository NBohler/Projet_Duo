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

bool Entity::getCollision()
{
	return 0;
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
