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