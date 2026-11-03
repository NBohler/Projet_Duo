#pragma once
#include "Entity.h"

class Enemy : public Entity
{
	void getCollision() override;
	
};

class Zombie : public Enemy
{

};

class HeadlessZombie : public Enemy
{
};

class SwimmerZombie : public Enemy
{
};

