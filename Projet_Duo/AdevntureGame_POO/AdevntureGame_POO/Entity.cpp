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

void Entity::getCollision() 
{

}

void Entity::takeDamage() 
{
	life_point-=1;
}

int Entity::getLife() 
{
	return life_point;
}