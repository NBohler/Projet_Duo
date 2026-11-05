#pragma once
#include <vector>
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(int life, Vector2 position = Vector2{}) : Entity(life, position) {}
	void move(Vector2 dir) override;
	virtual Vector2 getDirection(Vector2 target) = 0;
	void onCollision(Entity* other) override;
protected:
	Vector2 getRandomDirection();
	Vector2 chooseDirection(std::vector<Entity*>& others) override
	{
		return getDirection(others[0]->getPos());   // others[0] = le héros
	}
};



class Zombie : public Enemy
{
public:
	Zombie(Vector2 position) : Enemy(1, position) {};
	Vector2 getDirection(Vector2 target) override;
};

class HeadlessZombie : public Enemy
{
public:
	HeadlessZombie(Vector2 position) : Enemy(1, position) {};
	Vector2 getDirection(Vector2 target) override;
};

class SwimmerZombie : public Enemy
{
public:
	SwimmerZombie(Vector2 position) : Enemy(1, position) {};
	Vector2 getDirection(Vector2 target) override;
};

std::vector<Enemy*> createEnemiesGroup();
void freeEnemyGroup(std::vector<Enemy*>& group);