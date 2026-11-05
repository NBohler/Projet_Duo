#include "Ennemies.h"
#include "Entity.h"
#include <random>

Vector2 Enemy::getRandomDirection()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> distrib(0, 3);

	return g_directions[distrib(gen)];
}


std::vector<Entity*> createEnemiesGroup()
{
	std::vector<Entity*> group;
	group.push_back(new Zombie({ 3, 3 }));
	group.push_back(new HeadlessZombie({ 5, 2 }));
	group.push_back(new SwimmerZombie({ 1, 4 }));
	return group;
}

void freeEnemyGroup(std::vector<Entity*>& group)
{
	for (Entity* e : group)
		delete e;
	group.clear();
}

void Enemy::move(Vector2 dir)
{ 
	dir = getRandomDirection();
	pos = pos + dir;
}