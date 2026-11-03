#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Vector2 getRandomDirection();
	void move(Enemy character);
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
