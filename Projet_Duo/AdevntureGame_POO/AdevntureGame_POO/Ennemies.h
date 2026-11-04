#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(int life, Vector2 position = Vector2{}) : Entity(life, position) {}
	Vector2 getRandomDirection();
	void move(Vector2 dir) override;
};

class Zombie : public Enemy
{
	Zombie(Vector2 position) : Enemy(1, position) {};
};

class HeadlessZombie : public Enemy
{
	HeadlessZombie(Vector2 position) : Enemy(1, position) {};
};

class SwimmerZombie : public Enemy
{
	SwimmerZombie(Vector2 position) : Enemy(1, position) {};
};

Entity* Enemy_group[4] = {
	enemy({0,5})
}