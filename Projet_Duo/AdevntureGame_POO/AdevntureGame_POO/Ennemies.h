#pragma once
#include <vector>
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
public:
	Zombie(Vector2 position) : Enemy(1, position) {};
};

class HeadlessZombie : public Enemy
{
public:
	HeadlessZombie(Vector2 position) : Enemy(1, position) {};
};

class SwimmerZombie : public Enemy
{
public:
	SwimmerZombie(Vector2 position) : Enemy(1, position) {};
};

std::vector<Entity*> createEnemiesGroup();
void freeEnemyGroup(std::vector<Entity*>& group);