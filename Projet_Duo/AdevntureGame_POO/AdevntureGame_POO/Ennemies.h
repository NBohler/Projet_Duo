#pragma once
#include "Entity.h"

class Enemy : Entity
{
private:
	int life_point = 1;
	int damage = 1;
	
};

class Zombie : Enemy
{

};

class HeadlessZombie : Enemy
{
};

class SwimmerZombie : Enemy
{
	void getCollision();
};

